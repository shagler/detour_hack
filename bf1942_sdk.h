#ifndef _BF1942_SDK_H
#define _BF1942_SDK_H

#define STATIC_GAME_DEVICE_POINTER	  *((int*)0x9C0184)

#define STATIC_OFFSET_BASE            *((DWORD*)0x00A5C630)
#define STATIC_OFFSET_PLAYERMANAGER   *((DWORD*)0x0097D76C)
#define STATIC_OFFSET_RENDERER	      *((DWORD*)0x009A99D4)
#define STATIC_OFFSET_RENDERERVIEW	  *((DWORD*)0x009AB868)
#define STATIC_OFFSET_TEMPLATEMANAGER *((DWORD*)0x0097D768)
#define STATIC_OFFSET_OBJECTMANAGER	  *((DWORD*)0x0097D764)
#define STATIC_OFFSET_CLASSMANAGER    *((DWORD*)0x009A4F50)
#define STATIC_OFFSET_TEXTWRITER      *((DWORD*)0x00971EAC)

namespace bf1942 {
	template<class T> 
	class Ref {
	public:
		T* ptr;
	};

	struct Text_Manager {
	public:
		virtual void			function0(void);
		virtual void			function1(void);
		virtual void			function2(void);
		virtual void			set_text_parameters(std::string* textparam);//?? loadfont ??
		virtual void			draw_text(float x, float y, std::string* text);
		virtual void			function5(void);
		virtual void			function6(void);
		virtual int				get_text_width(std::string* text);
		virtual void			function8(void);
		virtual void			function9(void);
		virtual void			set_text_color(DWORD dwColor);
		virtual DWORD			get_text_color(void);
	};

	struct Text_Manager_Holder {
	public:
		char          unknown0[4];
		Text_Manager* console_text_manager;
		Text_Manager* nametag_text_manager;
	};

	struct Text_Writer_Base {
	public:
		char                 unknown0[728];
		Text_Manager_Holder* manager;       /* 02D8 */
	};

	class View_Settings_Base {
	public:
		virtual void function0();
		virtual void function1();
		virtual void function2();
		virtual void function3();
		virtual void function4();

		char    unknown0[4];             /* 0000 */
		__int32 texture_quality;         /* 0008 */
		__int32 unknown1;                /* 000C */
		BYTE    unknown2;                /* 0010 */
		BYTE    unknown3;                /* 0011 */
		BYTE    unknown4;                /* 0012 */
		BYTE    unknown5;                /* 0013 */
		__int32 graphics_quality;        /* 0014 */
		__int32 view_distance;           /* 0018 */
		float   map_distance;            /* 001C */
		__int32 effects_quality;         /* 0020 */
		char    unknown6[4];
		__int32 altenate_spawninterface; /* 0028 */
		char    unknown7[4];
		__int32 view_port_width;         /* 0030 */
		__int32 view_port_height;        /* 0034 */

		void set_view_distance(DWORD view_distance, float map_distance) {
			this->view_distance = view_distance;
			this->map_distance  = map_distance;
		}
	};

	class Mouse_Common {
	public:
		virtual void function0();

		char  unknown0[8]; /* 0000 */
		float mouse_sence; /* 000C */
	};

	class Mouse_Air {
	public:
		virtual void function0();

		char  unknown0[8];    /* 0000 */
		float mouse_sence;    /* 000C */
		char  unknown1[4];
		float keyboard_sence; /* 000C */
	};

	class Mouse_Infantry {
	public:
		virtual void function0();

		char  unknown0[8]; /* 0000 */
		float mouse_sence; /* 000C */
	};

	class Mouse_Land_Sea {
	public:
		virtual void function0();

		char  unknown0[8];    /* 0000 */
		float mouse_sence;    /* 000C */
		char  unknown1[4];
		float keyboard_sence; /* 000C */
	};

	class Mouse_Settings_Base {
	public:
		virtual void function0();
		virtual void function1();
		virtual void function2();
		virtual void function3();
		virtual void function4();

		char            unknown0[4];    /* 0000 */
		Mouse_Common*   mouse_common;   /* 0008 */
		Mouse_Air*      mouse_air;      /* 000C */
		Mouse_Infantry* mouse_infantry; /* 0010 */
		Mouse_Land_Sea* mouse_land_sea; /* 0014 */
	};

	class Settings_Base {
	public:
		virtual void function0();
		virtual void function1();
		virtual void function2();
		virtual void function3();
		virtual void function4();
		virtual void function5();

		char unknown0[16];                   /* 0000 */
		View_Settings_Base*  view_settings;  /* 0014 */
		Mouse_Settings_Base* mouse_settings;
	};

	class Armor {
	public:
		char  unknown0[56];
		float current_health;
		float max_health;
		float get_health_percentage(void) { return this->current_health / this->max_health * 100.0f; }
	};

	class Armor_Holder {
	public: 
		char   unknown0[16];
		Armor* armor;
	};

	class Renderer {
	public:
		virtual void function0();
		virtual void function1();
		virtual void function2();
		virtual void function3();
		virtual void function4();
		virtual void function5();
		virtual void function6();
		virtual void function7();
		virtual void function8();
		virtual void function9();
		virtual void function10();
		virtual void function11();
		virtual void function12();
		virtual void function13();
		virtual void function14();
		virtual void function15();
		virtual void function16();
		virtual void function17();
		virtual void function18();
		virtual void function19();
		virtual void draw();	   /* hook if return address is 0x0046760B */ 
		virtual void function21();
		virtual void function22();
		virtual void function23();
		virtual void function24();
		virtual void function25();
		virtual void function26();
		virtual void function27();
		virtual void function28();
		virtual void function29();
		virtual void function30();
		virtual void function31();
		virtual void function32();
		virtual void function33();
		virtual void function34();
		virtual void function35();
		virtual void function36();
		virtual void function37();
		virtual void function38();
		virtual void function39();
		virtual void function40();

		char              unknown0[136];
		IDirect3D8*       dx_interface;  /* 008C */
		IDirect3DDevice8* dx_device;     /* 0090 */
	};

	class Renderer_View {
	public:
		virtual void        function0();
		virtual void        function1();
		virtual void        function2();
		virtual void        function3();
		virtual void        function4();
		virtual void        function5();
		virtual void        function6();
		virtual void        function7();
		virtual void        function8();
		virtual void        function9();
		virtual void        function10();
		virtual void        function11();
		virtual void        function12();
		virtual void        function13();
		virtual void        function14();
		virtual void        function15();
		virtual void        function16();
		virtual void        function17();
		virtual void        function18();
		virtual void        function19();
		virtual void        function20();
		virtual void        function21();
		virtual void        function22();
		virtual D3DXMATRIX* get_view_matrix();
		virtual void        function24();
		virtual void        draw_view();
		virtual void        function26();
		virtual void        function27();
		virtual void        function28();
		virtual void        function29();

		char       unknown0[28];
		float      fov_mod;      /* 001C */
		float      current_fov;  /* 0020 */
		float      fov_mod1;     /* 0024 */
		char       unknown1[20];
		D3DXMATRIX view_matrix;  /* 003C */


		void setfov(float fov) {
			this->current_fov = fov;
		}
	};

	class OComponent {
	public:
		virtual void function0();
	};

	class Physics_Node {

	};

	class Geometry {

	};

	class TComponent {
	public:
		virtual void function0();
	};

	class Template {
	public:
		virtual void         function0();
		virtual void         function1();
		virtual TComponent* get_component(DWORD template_id);
		virtual int          get_template_type(void);
		virtual void         function5();
		virtual std::string* get_template_name(void);
		virtual void         function6();
		virtual int          get_template_id(void);
		virtual void         function8();
		virtual void         function9();
		virtual void         function10();
		virtual void         function11();
		virtual void         function12();
		virtual void         function13();
		virtual void         function14();
		virtual void         function15();
		virtual void         function16();
		virtual void         function17();
		virtual void         function18();
		virtual void         function19();
		virtual void         function20();
		virtual void         function21();
		virtual void         function22();
		virtual void         function23();
		virtual void         function24();
		virtual void         function25();
		virtual void         function26();
		virtual void         function27();
		virtual void         function28();
		virtual void         function29();
		virtual void         function30();

		char        unknown0[4];
		std::string template_name;                     /* 000C */
		std::string networkable_info;                  /* 0028 */
		__int32     template_id;
		char        unknown1[16];
		float       cull_radius_scale;                 /* 0054 */
		char        unknown2[116];
		float       drag;                              /* 00CC */
		D3DXVECTOR3 drag_offset;                       /* 00D0 */
		float       mass;                              /* 00DC */
		D3DXVECTOR3 center_of_mass_offset;             /* 00E0 */
		D3DXVECTOR3 inertia_modifier;                  /* 00EC */
		BYTE        unknown3;                          /* 00F8 */
		BYTE        unknown4;                          /* 00F9 */
		BYTE        unknown5;                          /* 00FA */
		BYTE        unknown6;                          /* 00FB */
		char        unknown7[8];
		BYTE        has_armor;                         /* 0104 */
		BYTE        unknown8;                          /* 0105 */
		BYTE        unknown9;                          /* 0106 */
		BYTE        unknown10;                         /* 0107 */
		__int32     hitpoints;                         /* 0108 */
		__int32     max_hitpoints;                     /* 010C */
		__int32     material;                          /* 0110 */
		float       gravity_modifier;                  /* 0114 */
		float       unknown12;                         /* 0118 */
		float       speed_modifier;                    /* 011C */
		char        unknown13[48];
		BYTE        damage_from_water;                 /* 0150 */
		char        unknown14[3];                      /* 0151 */
		float       water_damage_delay;                /* 0154 */
		float       respawn_time;                      /* 0158 */
		char        unknown15[4];
		float       unknown16;                         /* 0160 */
		char        unknown17[4];
		float       critical_damage;                   /* 0168 */
		float       sink_in_to_land_after_death_speed; /* 016C */
		float       explosion_radius;                  /* 0170 */
		float       explosion_damage;                  /* 0174 */
		__int32     explosion_material;                /* 0178 */
		float       explosion_force;                   /* 017C */
		float       explosion_force_mod;               /* 0180 */
		float       explosion_force_max;               /* 0184 */
		char        unknown18[28];
		float       health_lost_while_critical_damage; /* 01A4 */
		float       health_lost_white_upside_down;     /* 01A8 */
		float       health_lost_from_water;            /* 01AC */
		char        unknown23[52];
		__int32     template_end;                      /* 01E0 */
	};

	class Template_Manager {
	public:
		virtual void         function0();
		virtual void         function1();
		virtual void         function2();
		virtual int          get_template_type(void);
		virtual void         function5();
		virtual std::string* get_template_name(void);
		virtual void         function6();
		virtual int          get_template_id(void);
		virtual void         function8();
		virtual void         function9();
		virtual void         function10();
		virtual void         function11();
		virtual void         function12();
		virtual void         function13();
		virtual void         function14();
		virtual void         function15();
		virtual void         function16();
		virtual void         function17();
		virtual void         function18();
		virtual void         function19();
		virtual void         function20();
		virtual void         function21();
		virtual void         function22();
		virtual void         function23();
		virtual void         function24();
		virtual void         function25();
		virtual void         function26();
		virtual void         function27();
		virtual void         function28();
		virtual void         function29();
		virtual void         function30();
	};

	class Object {
	public:
		virtual void         function0();
		virtual void         function1();
		virtual OComponent*  get_component(DWORD object_id);
		virtual void         function3();
		virtual void         function4();
		virtual void         function5();
		virtual void         function6();
		virtual void         function7();
		virtual void         function8();
		virtual void         function9();
		virtual void         function10();
		virtual std::string* get_object_name(void);
		virtual void         function12();
		virtual D3DXVECTOR3* get_object_pos(void);
		virtual void         function14();
		virtual D3DXMATRIX*  get_object_matrix(void);
		virtual void         function16();
		virtual void         function17();
		virtual void         function18();
		virtual void         function19();
		virtual void         function20();
		virtual void         function21();
		virtual void         function22();
		virtual void         function23();
		virtual void         function24();
		virtual void         function25();
		virtual void         function26();
		virtual void         function27();
		virtual void         function28();
		virtual void         function29();
		virtual void         function30();
		virtual void         function31();
		virtual void         function32();
		virtual void         function33();
		virtual void         function34();
		virtual void         function35();
		virtual void         function36();
		virtual void         function37();
		virtual void         function38();
		virtual void         function39();
		virtual void         function40();
		virtual void         function41();
		virtual void         function42();
		virtual void         function43();
		virtual void         function44();
		virtual void         function45();
		virtual void         function46();
		virtual void         function47();
		virtual void         function48();
		virtual void         function49();
		virtual void         function50();
		virtual void         function51();
		virtual void         function52();
		virtual void         function53();
		virtual void         function54();
		virtual DWORD        enable_item(BYTE index);
		virtual void         function56();
		virtual void         function57();
		virtual void         function58();
		virtual void         function59();
		virtual void         function60();
		virtual void         function61();
		virtual void         function62();
		virtual void         function63();
		virtual void         function64();
		virtual int          get_selected_item(void);
		virtual void         function66();
		virtual void         function67();
		virtual void         function68();
		virtual void         function69();
		virtual void         function70();
		virtual void         function71();
		virtual void         function72();
		virtual void         function73();

		char               unknown0[72];
		Template*          object_template; /* 004C */
		char               unknown1[12];
		Geometry*          object_mesh;     /* 005C */
		Physics_Node*      object_physics;  /* 0060 */
		char               unknown2[16];
		D3DXMATRIX         object_matrix;   /* 0074 */
		char               unknown3[8];
		Ref<Armor_Holder>* object_armor;
		char               unknown4[44];
		Object*            object_root;     /* 00EC */
		Object*            object_parent;   /* 00F0 */
		char               unknown5[36];
		__int32            object_end;      /* 0118 */
	};

	class Player {
	public:
		virtual void         function0();
		virtual void         function1();
		virtual void         function2();
		virtual DWORD        get_object_type(void);
		virtual void         function4();
		virtual void         set_player_name(std::string* str_name);
		virtual std::string* get_player_name();
		virtual void         function7();
		virtual void         function8();
		virtual void         function9();
		virtual void         function10();
		virtual void         function11();
		virtual void         function12();
		virtual void         function13();
		virtual Object*      get_player_object();
		virtual void         function15();
		virtual void         function16();
		virtual void         function17();
		virtual void         function18();
		virtual void         function19();
		virtual void         function20();
		virtual void         function21();
		virtual void         function22();
		virtual void         function23();

		char           unknown0[96];
		Object*        player_object;           /* 0064 */
		char           unknown1[44];
		Renderer_View* render_view;             /* 0094 */
		Object*        player_soldier;          /* 0098 */
		char           unknown2[8];
		Object*        multiplayer_free_camera; /* 00A4 */
		BYTE           unknown3;                /* 00A8 */
		BYTE           player_alive;            /* 00A9 */
		BYTE           unknown4;                /* 00AA */
		BYTE           unknown5;                /* 00AB */
		__int32        player_team;             /* 00AC */
		__int32        kit_num;                 /* 00B0 */
		char           unknown6[12];
		float          time_till_spawn;         /* 00C0 (singleplayer only) */
		char           unknown7[16];
		__int32        deaths;                  /* 00D4 */
		__int32        total_kills;             /* 00D8 */
		char           unknown8[20];
		__int32        suicides;                /* 00F0 */
		__int32        total_points;            /* 00F4 */
		char           unknown9[8];
		__int32        unknown10;               /* (score related) */
		char           unknown11[8];
		__int32        unknown12;               /* 010C (score related) */
		char           unknown13[8];
		__int32        unknown14;               /* 0118 (score related) */
		char           unknown15[12];
		__int32        unknown16;               /* 0128 (score related) */
		char           unknown17[24];
		__int32        unknown18;               /* 0144 (score related) */
		__int32        unknown19;               /* 0148 (score related) */
		char           unknown20[48];
		__int32        unknown21;               /* 017C (score related) */
		char           unknown22[4];
		BYTE           primary_fire_down;       /* 0184 */
		BYTE           secondary_fire_down;     /* 0185 */
		BYTE           unknown23;               /* 0186 */
		BYTE           game_paused;             /* 0187 */

		Renderer_View* get_renderer_view() {
			return this->render_view;
		}
	};

	class Player_Manager {
	public:
		virtual void function0();
		virtual void function1();
		virtual void function2();
		virtual void function3();
		virtual void function4();
		virtual void function5();
		virtual Player* get_player_by_index(int iIndex);
		virtual void function7();
		virtual Player* get_local_player(void);
		virtual void function9();
		virtual void function10();
		virtual void function11();
		virtual void function12();
		virtual void function13();
		virtual void function14();
		virtual void function15();
		virtual void function16();
		virtual void function17();
		virtual void function18();
		virtual void function19();
		virtual Player* get_some_player(void);
		virtual void function21();
		virtual DWORD get_players_connected(void);

		char               unknown0[8];
		std::list<Player*> player_list;   /* 000C */
		char               unknown1[4];
		__int32            total_players; /* 0014 */
		char               unknown2[60];
		Player*            local_players; /* 0054 */
	};

	class Object_Manager {
	public:
		virtual void function0(); //
		virtual void function1(); //
		virtual Object* get_object_by_id(DWORD dwID); //
		virtual void function3(); //
		virtual void function4(); //
		virtual void function5(); //
		virtual void function6(); //
		virtual void function7(); //
		virtual void function8(int); //
		virtual void function9(int); //
		virtual void function10(); //
		virtual void function11(); //
		virtual void function12(); //
		virtual void function13(); //
		virtual void function14(); //
		virtual void function15(int, int, int, int, int, int, int, int, int, int, int, int, int); //
		virtual void function16(); //
		virtual void function17(); //
		virtual void function18(int, int, int, int, int, int, int); //
		virtual void function19(int, int, int, int, int, int, int, int, int); //
		virtual void function20(); //
		virtual void function21(); //
		virtual void function22(); //
		virtual void function23(); //
		virtual void function24(); //
		virtual void function25(); //
		virtual void function26(); //
		virtual void function27(); //
		virtual void function28(); //
		virtual void function29(); //
		virtual void function30(); //
		virtual void function31(); //
		virtual void function32(); //
		virtual void function33(); //
		virtual void function34(); //
		virtual void function35(); //
		virtual void function36(); //
		virtual void function37(); //
		virtual void function38(); //
		virtual void function39(); //
		virtual void function40(); //
		virtual void function41(); //
		virtual void function42(); //
		virtual void function43(); //
		virtual void function44(); //
		virtual void function45(); //
		virtual void function46(); //
		virtual void function47(); //
		virtual void function48(); //
		virtual void function49(); //
		virtual void function50(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int); //
		virtual void function51(); //
		virtual void function52(); //
		virtual void function53(); //
		virtual void function54(); //
		virtual void function55(); //
		virtual void function56(); //
		virtual void function57(); //
		virtual void function58(); //
		virtual void function59(); //
		virtual void function60(); //
		virtual void function61(); //
		virtual void function62(); //
		virtual void function63(); //
		virtual void function64(); //
		virtual void function65(); //
		virtual void function66(); //
		virtual void function67(); //
		virtual void function68(); //
		virtual void function69(); //
		virtual void function70(); //
		virtual void function71(); //
		virtual void function72(); //

		char unknown4[160]; /* 0004 */
	}; /* size = 0x0434(1076) */

	class Class_Manager {
	public:
		virtual void function0();
	};

	struct SDK {
		Settings_Base* settings_base;
		Player_Manager* player_manager;
		Renderer* renderer;
		Renderer_View* renderer_view;
		Template_Manager* template_manager;
		Object_Manager* object_manager;
		Class_Manager* class_manager;
		Text_Writer_Base* text_writer;
		Text_Manager* text_manager;
	};
}

#endif /* _BF1942_SDK_H_ */
