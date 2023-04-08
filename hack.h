#ifndef _HACK_H_
#define _HACK_H_

#define _CRT_SECURE_NO_WARNINGS

// Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN

#define POINTER_64 __ptr64

#include <windows.h>
#include <stdio.h>
#include <list>
#include <string>
#include <d3dx8.h>
#include <corecrt_malloc.h>

extern "C" void* _AddressOfReturnAddress(void);
extern "C" void* _ReturnAddress(void);
#pragma intrinsic(_AddressOfReturnAddress)
#pragma intrinsic(_ReturnAddress)

#include "detours.h"
#include "vmthook.h"

#pragma comment(lib, "ddraw.lib")
#pragma comment(lib, "d3dx8.lib")
#pragma comment(lib, "detours.lib")

/// Debug log print function.
static void debug_print(const char* format, ...) {
    if (!format) return;

    va_list arguments  = {};
    char buffer[256]   = {};
    DWORD written_size = 0;

    va_start(arguments, format);
    _vsnprintf_s(buffer + strlen(buffer), sizeof(buffer) - strlen(buffer), 256, format, arguments);
    va_end(arguments);

    strcat(buffer, "\n");

    written_size = sizeof(buffer) - strlen(buffer);
    WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), buffer, strlen(buffer), &written_size, NULL);
}

#include "bf1942_sdk.h"

#endif /* _HACK_H_ */