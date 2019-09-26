class construction_menu {
	idd = -1;
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
			text = "Construction Menu"; //--- ToDo: Localize;
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
			action = "closeDialog 0; createDialog ""radio_comm"";";
		};

		class HQ_button_Gsquad: RscButton {
			idc = -1;
			text = "Small Trench"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Make a quick small trench for one man";
			action = "closeDialog 0; [""ST""] spawn RES_fnc_build;";
		};

		class HQ_button_Gstatic: RscButton {
			idc = -1;
			text = "Medium Trench"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "A mid sized trench with capabilities for more than one soldier";
			action = "closeDialog 0; [""MT""] spawn RES_fnc_build;";
		};

		class HQ_button_Gremove: RscButton {
			idc = -1;
			text = "Vehicle obstacles"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Build some obstacles for vehicles";
			action = "closeDialog 0; [""RB""] spawn RES_fnc_build;";
		};

		class HQ_button_unlock: RscButton {
			idc = -1;
			text = "Bunker Options"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Need to be built in garrison controlled zones and cost money";
			action = "closeDialog 0; createDialog ""bunkeRES_menu"";";
		};
	};
};
