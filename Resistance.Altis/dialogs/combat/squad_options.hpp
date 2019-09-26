class squad_options {
	idd = 100;
	movingenable = false;

	class controls {

		class HQ_box: BOX {
			idc = -1;
			text = $STR_antistasi_dialogs_generic_box_text;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.30 * safezoneH;//30
		};

		class HQ_frame: RscFrame {
			idc = -1;
			text = "Squad Options"; //Squad Options
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.28 * safezoneH;//28
		};

		class HQ_button_back: RscButton {
			idc = -1;
			text = $STR_antistasi_dialogs_generic_button_back_text;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0; createDialog ""squad_recruit"";";
		};

		class HQ_button_Gsquad: RscButton {
			idc = 104;
			text = "Normal Squad"; //Normal Squad
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			//tooltip = "";
			action = "closeDialog 0; [groupsSDKSquad] spawn RES_fnc_addFIAsquadHC;";
		};

		class HQ_button_Gstatic: RscButton {
			idc = 105;
			text = "Engineer Squad"; //Engineer Squad
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [groupsSDKSquadEng] spawn RES_fnc_addFIAsquadHC;";
		};

		class HQ_button_Gremove: RscButton {
			idc = 106;
			text = "MG Squad"; //MG Squad
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [groupsSDKSquadSupp, ""MG""] spawn RES_fnc_addFIAsquadHC;";
		};

		class HQ_button_unlock: RscButton {
			idc = 107;
			text = "Mortar Squad"; //Mortar Squad
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [groupsSDKSquadSupp, ""Mortar""] spawn RES_fnc_addFIAsquadHC;";
		};
	};
};
