class HQ_menu {
	idd = 100;
	movingenable = false;

	class controls {
		//Structure
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
			text = $STR_antistasi_dialogs_hq_frame_text;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.462103 * safezoneH;
		};

		class HQ_button_back: RscButton {
			idc = 103;
			text = $STR_antistasi_dialogs_generic_button_back_text;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0;";
		};
		//Buttons L and R
		class HQ_button_load: RscButton {
			idc = 104; 	//L1
			text = $STR_antistasi_dialogs_hq_button_withdraw_text;
			tooltip = $STR_antistasi_dialogs_hq_button_withdraw_tooltip;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "if (isMultiPlayer) then { if (player == theBoss) then { call RES_fnc_theBossSteal; } else { hint ""Only Player Commander has access to this function""; }; } else { hint ""This function is MP only""; };";
		};

		class HQ_button_savegame: RscButton {
			idc = 105; 	//L2
			text = $STR_antistasi_dialogs_hq_button_garrisons_text;
			tooltip = $STR_antistasi_dialogs_hq_button_garrisons_tooltip;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; if (player == theBoss) then { CreateDialog ""build_menu""; } else { hint ""Only Player Commander has access to this function""; };";
		};

		class HQ_button_moveHQ: RscButton {
			idc = 106;	//L3
			text = $STR_antistasi_dialogs_hq_button_move_headquarters_text;
			tooltip = $STR_antistasi_dialogs_hq_button_move_headquarters_tooltip;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; if (player == theBoss) then { [] spawn RES_fnc_moveHQ; } else { hint ""Only Player Commander has access to this function""; };";
		};

		class HQ_button_recruitUnit: RscButton {
			idc = 107;	//R1
			text = $STR_antistasi_dialogs_hq_button_members_list_text;
			tooltip = $STR_antistasi_dialogs_hq_button_members_list_tooltip;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "if (player == theBoss) then { if (isMultiplayer) then { [] call RES_fnc_membersList; } else { hint ""This function is MP only""; }; } else { hint ""Only Player Commander has access to this function""; };";
		};

		class HQ_button_recruitSquad: RscButton {
			idc = 108;	//R2
			text = $STR_antistasi_dialogs_hq_button_rebuild_assets_text;
			tooltip = $STR_antistasi_dialogs_hq_button_rebuild_assets_tooltip;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; if (player == theBoss) then { [] spawn RES_fnc_rebuildAssets; } else { hint ""Only Player Commander has access to this function""; };";
		};

		class HQ_button_vehicle: RscButton {
			idc = 109;	//R3
			text = $STR_antistasi_dialogs_hq_button_train_ai_text;
			tooltip = $STR_antistasi_dialogs_hq_button_train_ai_tooltip;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; if (player == theBoss) then { [] call RES_fnc_FIAskillAdd; } else { hint ""Only Player Commander has access to this function""; };";
		};

		class HQ_button_skill: RscButton {
			idc = 110;	//M4
			text = $STR_antistasi_dialogs_hq_button_garage_text;
			tooltip = $STR_antistasi_dialogs_hq_button_garage_tooltip;
			x = 0.37749 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [GARAGE_FACTION] spawn RES_fnc_garage;";
		};
	};
};
