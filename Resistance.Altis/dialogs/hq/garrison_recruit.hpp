class garrison_recruit {
	idd = 100;
	movingenable = false;

	class controls {

		class HQ_box: BOX {
			idc = 101;
			text = $STR_antistasi_dialogs_generic_box_text;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.492103 * safezoneH;
		};

		class HQ_frame: RscFrame {
			idc = 102;
			text = $STR_antistasi_dialogs_garrison_recruit_frame_text;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.462103 * safezoneH;
		};

		class HQ_button_back: RscButton {
			idc = 103;
			text = $STR_antistasi_dialogs_generic_button_back_text;
			tooltip = $STR_antistasi_dialogs_generic_button_back_tooltip;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0; createDialog ""build_menu"";";
		};

		class HQ_button_rifleman: RscButton {
			idc = 104;
			text = $STR_antistasi_dialogs_garrison_spawn_rifleman_text;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "[SDKMil] spawn RES_fnc_garrisonAdd;";
		};

		class HQ_button_autorifleman: RscButton {
			idc = 105;
			text = $STR_antistasi_dialogs_garrison_spawn_autorifleman_text;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "[SDKMG] spawn RES_fnc_garrisonAdd;";
		};

		class HQ_button_medic: RscButton {
			idc = 126;
			text = $STR_antistasi_dialogs_garrison_spawn_medic_text;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "[SDKMedic] spawn RES_fnc_garrisonAdd;";
		};

		class HQ_button_engineer: RscButton {
			idc = 107;
			text = $STR_antistasi_dialogs_garrison_spawn_squad_lead_text;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "[SDKSL] spawn RES_fnc_garrisonAdd;";
		};

		class HQ_button_explosive: RscButton {
			idc = 108;
			text = $STR_antistasi_dialogs_garrison_spawn_mortaRES_text;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "[staticCrewTeamPlayer] spawn RES_fnc_garrisonAdd;";
		};

		class HQ_button_grenadier: RscButton {
			idc = 109;
			text = $STR_antistasi_dialogs_garrison_spawn_grenadieRES_text;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "[SDKGL] spawn RES_fnc_garrisonAdd;";
		};

		class HQ_button_marksman: RscButton {
			idc = 110;
			text = $STR_antistasi_dialogs_garrison_spawn_marksman_text;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "[SDKSniper] spawn RES_fnc_garrisonAdd;";
		};

		class HQ_button_AT: RscButton {
			idc = 111;
			text = $STR_antistasi_dialogs_garrison_spawn_at_text;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "[SDKATman] spawn RES_fnc_garrisonAdd;";
		};
	};
};
