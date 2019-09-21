class squad_recruit {
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
			text = "Squad Recruitment Options"; //--- ToDo: Localize;
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
			action = "closeDialog 0; createDialog ""radio_comm"";";
		};

		class HQ_button_infsquad: RscButton {
			idc = 104;
			text = "Recruit Inf. Squad"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [] spawn RES_fnc_squadOptions;";
		};

		class HQ_button_infteam: RscButton {
			idc = 105;
			text = "Recruit Inf. Team"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [groupsSDKmid] spawn RES_fnc_addFIAsquadHC;";
		};

		class HQ_button_ATteam: RscButton {
			idc = 106;
			text = "Recruit AT Team"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [groupsSDKAT] spawn RES_fnc_addFIAsquadHC;";
		};

		class HQ_button_sniperTeam: RscButton {
			idc = 107;
			text = "Recruit Sniper Team"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [groupsSDKSniper] spawn RES_fnc_addFIAsquadHC;";
		};

		class HQ_button_infsquadM: RscButton {
			idc = 108;
			text = "Recruit MG Team"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [SDKMGStatic] spawn RES_fnc_addFIAsquadHC;";
		};

		class HQ_button_infteamM: RscButton {
			idc = 109;
			text = "Recruit AT Car"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [vehSDKAT] spawn RES_fnc_addFIAsquadHC;";
		};

		class HQ_button_ATteamM: RscButton {
			idc = 110;
			text = "Recruit AA Truck"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [staticAAteamPlayer] spawn RES_fnc_addFIAsquadHC;";
		};

		class HQ_button_mortar: RscButton {
			idc = 111;
			text = "Recruit Mortar Team"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [SDKMortar] spawn RES_fnc_addFIAsquadHC;";
		};
	};
};
