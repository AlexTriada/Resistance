class build_menu {
	idd = -1;
	movingenable = false;

	class controls {
		//Structure
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
			text = $STR_antistasi_dialogs_build_frame_text;
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
			action = "closeDialog 0; createDialog ""HQ_menu"";";
		};
		//Action Buttons
		class 4slots_L1: RscButton {
			idc = -1;
			text = $STR_antistasi_dialogs_build_minefield_button_text;
			tooltip = $STR_antistasi_dialogs_build_minefield_button_tooltip;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; createDialog ""minebuild_menu"";";
		};

		class 4slots_R1: RscButton {
			idc = -1;
			text = $STR_antistasi_dialogs_build_outpost_button_text;
			tooltip = $STR_antistasi_dialogs_build_outpost_button_tooltip;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [""create""] spawn RES_fnc_outpostDialog;";
		};

		class 4slots_L2: RscButton {
			idc = -1;
			text = $STR_antistasi_dialogs_build_recruit_units_button_text;
			tooltip = $STR_antistasi_dialogs_build_recruit_units_button_tooltip;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [""add""] spawn RES_fnc_garrisonDialog;";
		};

		class 4slots_R2: RscButton {
			idc = -1;
			text = $STR_antistasi_dialogs_build_disband_units_button_text;
			tooltip = $STR_antistasi_dialogs_build_disband_units_button_tooltip;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [""rem""] spawn RES_fnc_garrisonDialog;";
		};
	};
};
