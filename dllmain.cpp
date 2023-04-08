
#include "hack.cpp"
#include "draw.cpp"
bf1942::SDK g_sdk = {};
vmt::Hook_Manager* g_vmt = {};

typedef void (WINAPI* Hack_Detour_t)();
Hack_Detour_t g_hackdetour = {};

typedef HRESULT(WINAPI* End_Scene_t)(LPDIRECT3DDEVICE8 dx_device);
End_Scene_t g_endscene = {};

static void write_memory(int address, BYTE data[], int size) {
    // Overwrite the address's memory region protections. 
    unsigned long protection_flags = {};
    VirtualProtect((LPVOID)address, size, PAGE_EXECUTE_READWRITE, &protection_flags);

    // Overwrite the memory region with our data.
    memcpy((LPVOID)address, (const void*)data, size);

    // Restore the address's memory region protections.
    VirtualProtect((LPVOID)address, size, protection_flags, &protection_flags);
}

static void write_nops(int address, int nops) {
    unsigned char nop_byte = 0x90;

    // Overwrite the address's memory region protections. 
    DWORD old_protection = 0;
    VirtualProtect((LPVOID)address, nops, PAGE_EXECUTE_READWRITE, &old_protection);

    // Fill the memory region with the designated amount of NOPs.
    for (int i = 0; i < nops; ++i) {
        memcpy((void*)(address + i), &nop_byte, 1);
    }

    // Restore the address's memory region protections.
    VirtualProtect((LPVOID)address, nops, old_protection, &old_protection);
}

/// Creates console for outputting debug information.
static void create_debug_console() {
    AllocConsole();
    GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTitleA("detour_hack -- debug console");
}

static void hide_unique_identifier(DWORD punkbuster_address) {
    // Get the address where the unique identifier is stored.
    PBYTE guid_address = (PBYTE)(punkbuster_address + 0x4B1D8);

    char current_unique_identifier[256] = {};

    // Create a new unique identifier. 
    GUID new_guid = {};
    CoCreateGuid(&new_guid);
    OLECHAR* new_unique_identifier = {};
    StringFromCLSID(new_guid, &new_unique_identifier);

    // Get the unique identifier currently stored and overwrite it. 
    for (int i = 0; i < 256; ++i) {
        if (guid_address[i] == NULL) break;

        current_unique_identifier[i] = guid_address[i];
        guid_address[i] = new_unique_identifier[i];
    }

    debug_print("Old GUID: %s", current_unique_identifier);
    debug_print("New GUID: %s", new_unique_identifier);
}

HRESULT WINAPI end_scene_hook(LPDIRECT3DDEVICE8 device) {
    draw_text(g_sdk.settings_base->view_settings->view_port_width - 200, g_sdk.settings_base->view_settings->view_port_height - 10, "Shawn Hagler, Jaehyun Lee, Noah Fielder", device);

    return g_endscene(device);
}

void WINAPI game_hook() {
    // Make sure that we are actually in a match. 
    if ((DWORD)_ReturnAddress() == 0x0046760B) {
        bf1942::Player* local_player = g_sdk.player_manager->get_local_player();
        if (local_player) {
            // Make enemies always appear on radar.
            write_nops(0x46B0EF, 6);
            write_nops(0x46B7BF, 6);
        }
    }
}

DWORD WINAPI render_hook(LPVOID thread_param) {
    // Create DirectX device pointer.
    LPDIRECT3DDEVICE8* dx_device = {};
    for (Sleep(5000); dx_device == NULL; Sleep(5000)) {
        memcpy(&dx_device, (void*)STATIC_GAME_DEVICE_POINTER, 4);
    }

    debug_print("DirectX_Device: 0x%X", dx_device);

    // Hook the game's DirectX `EndScene` function with our render code. 
    g_endscene = (End_Scene_t)DetourFunction((PBYTE)dx_device[35], (PBYTE)end_scene_hook);

    return 0;
}

/// Hack thread procedure.
DWORD WINAPI init_hack(LPVOID thread_param) {
    // Assign game pointers.
    g_sdk.settings_base    = (bf1942::Settings_Base*)STATIC_OFFSET_BASE;
    g_sdk.player_manager   = (bf1942::Player_Manager*)STATIC_OFFSET_PLAYERMANAGER;
    g_sdk.renderer         = (bf1942::Renderer*)STATIC_OFFSET_RENDERER;
    g_sdk.renderer_view    = (bf1942::Renderer_View*)STATIC_OFFSET_RENDERERVIEW;
    g_sdk.template_manager = (bf1942::Template_Manager*)STATIC_OFFSET_TEMPLATEMANAGER;
    g_sdk.object_manager   = (bf1942::Object_Manager*)STATIC_OFFSET_OBJECTMANAGER;
    g_sdk.class_manager    = (bf1942::Class_Manager*)STATIC_OFFSET_CLASSMANAGER;
    g_sdk.text_writer      = (bf1942::Text_Writer_Base*)STATIC_OFFSET_TEXTWRITER;
    g_sdk.text_manager = g_sdk.text_writer->manager->nametag_text_manager;

    // Allocate our virtual method hook manager and initalize it to the
    // game's renderer structure. 
    g_vmt = (vmt::Hook_Manager*)malloc(sizeof(vmt::Hook_Manager*));
    g_vmt->initalize((PDWORD*)g_sdk.renderer);

    // Find out where the anit-cheat is located within the game.
    //DWORD punkbuster = 0;
    //for (Sleep(500); punkbuster == 0; Sleep(500)) {
    //    DWORD punkbuster = (DWORD)GetModuleHandle(L"pbcl.dll");
    //}

    //debug_print("Punk Buster: 0x%X", punkbuster);
    //debug_print("");

    // Hide the unique identifier of the machine to prevent permanent bans.
    //hide_unique_identifier(punkbuster);

    debug_print("Settings_Base: 0x%X", g_sdk.settings_base);
    debug_print("Player_Manager: 0x%X", g_sdk.player_manager);
    debug_print("Renderer: 0x%X", g_sdk.renderer);
    debug_print("Renderer_View: 0x%X", g_sdk.renderer_view);
    debug_print("Template_Manager: 0x%X", g_sdk.template_manager);
    debug_print("Object_Manager: 0x%X", g_sdk.object_manager);
    debug_print("Class_Manager: 0x%X", g_sdk.class_manager);
    debug_print("Text_Writer: 0x%X", g_sdk.text_writer);
    debug_print("Text_Manager: 0x%X", g_sdk.text_manager);
    debug_print("VMT Hook: 0x%X", g_vmt);

    // Hook the game's renderer 20th virtual method function with our code.
    g_hackdetour = (Hack_Detour_t)g_vmt->hook_method((DWORD)game_hook, 20);

    debug_print("");
    debug_print("Draw_Detour: 0x%X", g_hackdetour);

    return 0;
}

/// Defines the entry point for the DLL application.
BOOL WINAPI DllMain(HMODULE module, DWORD reason, LPVOID reserved) {
    switch (reason) {
        case DLL_PROCESS_ATTACH: {
            // Disables DLL_THREAD_ATTACH and DLL_THREAD_DETACH.
            DisableThreadLibraryCalls(module);

            // Attach our debug console.
            create_debug_console();

            // Create our hack thread.
            CreateThread(0, 0, init_hack, 0, 0, 0);
            CreateThread(0, 0, render_hook, 0, 0, 0);
        } break;
    }

    return TRUE;
}