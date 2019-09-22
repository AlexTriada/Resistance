class carpet_bombing {
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
			text = "Carpet Bombing Strike"; //--- ToDo: Localize;
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
			text = "HE Bombs"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Cost: 1 point";
			action = "closeDialog 0; [""HE""] spawn RES_fnc_NATObomb;";
		};

		class HQ_button_Gstatic: RscButton {
			idc = -1;
			text = "Carpet Bombing"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Cost: 1 point";
			action = "closeDialog 0; [""CARPET""] spawn RES_fnc_NATObomb;";
		};

		class 4slots_L2: RscButton {
			idc = -1;
			text = "NAPALM Bomb"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Cost: 1 point";
			action = "closeDialog 0; [""NAPALM""] spawn RES_fnc_NATObomb;";
		};

		class 4slots_R2: RscButton {
			idc = -1;
			text = "Add to Air Support"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Gain Airstrike points giving this aircraft to the faction Air pool";
			action = "closeDialog 0; [] call RES_fnc_addBombRun;";
		};
	};
};
