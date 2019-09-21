class minebuild_menu {
	idd = -1;
	movingenable = false;

	class controls {
		class HQ_box: BOX {
			idc = -1;
			text = $STR_antistasi_dialogs_generic_box_text;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.30 * safezoneH;
		};
		class HQ_frame: RscFrame {
			idc = -1;
			text = $STR_antistasi_dialogs_minefield_frame_text;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.28 * safezoneH;
		};
		class HQ_button_back: RscButton {
			idc = -1;
			text = $STR_antistasi_dialogs_generic_button_back_text;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0; createDialog ""build_menu"";";
		};
		class HQ_button_mortar: RscButton {
			idc = -1;
			text = $STR_antistasi_dialogs_minefield_button_anti_personel_text;
			tooltip = $STR_antistasi_dialogs_minefield_button_anti_personel_tooltip;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [""APERSMine""] spawn RES_fnc_mineDialog;";
		};
		class HQ_button_MG: RscButton {
			idc = -1;
			text = $STR_antistasi_dialogs_minefield_button_remove_text;
			tooltip = $STR_antistasi_dialogs_minefield_button_remove_tooltip;
			x = 0.37749 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [""delete""] spawn RES_fnc_mineDialog;";
		};
		class HQ_button_AT: RscButton {
			idc = -1;
			text = $STR_antistasi_dialogs_minefield_button_anti_tank_text;
			tooltip = $STR_antistasi_dialogs_minefield_button_anti_tank_tooltip;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [""ATMine""] spawn RES_fnc_mineDialog;";
		};
	};
};
