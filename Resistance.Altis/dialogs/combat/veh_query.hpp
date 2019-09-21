class veh_query {
	idd = 100;
	movingenable = false;

	class controls {

		class HQ_box: BOX {
			idc = 101;
			text = $STR_antistasi_dialogs_generic_box_text;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.20 * safezoneH;//30
		};

		class HQ_frame: RscFrame {
			idc = 102;
			text = "Add Vehicle to Squad?"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.18 * safezoneH;//28
		};

		class HQ_button_back: RscButton {
			idc = 103;
			text = $STR_antistasi_dialogs_generic_button_back_text;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "
				closeDialog 0;
				vehQuery = nil;
				if (player == theBoss) then {
					[] spawn RES_fnc_squadRecruit;
				} else {
					hint ""Only Player Commander has access to this function"";
				};
			";
		};

		class HQ_button_Gsquad: RscButton {
			idc = 104;
			text = "YES"; //YES
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; vehQuery = true";
		};

		class HQ_button_Gstatic: RscButton {
			idc = 105;
			text = "NO"; //NO
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; vehQuery = nil";
		};
	};
};
