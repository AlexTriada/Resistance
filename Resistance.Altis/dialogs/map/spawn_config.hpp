class spawn_config {
	idd = -1;
	movingenable = false;

	class controls {

		class HQ_box: BOX {
			idc = -1;
			text = $STR_antistasi_dialogs_generic_box_text;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.20 * safezoneH;//30
		};

		class HQ_frame: RscFrame {
			idc = -1;
			text = "Spawn Distance Config"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.18 * safezoneH;//28
		};

		class HQ_button_back: RscButton {
			idc = -1;
			text = $STR_antistasi_dialogs_generic_button_back_text;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0; createDialog ""game_options"";";
		};

		class HQ_button_Gsquad: RscButton {
			idc = -1;
			text = "+100 Spawn Dist."; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "
				if (player == theBoss) then {
					if (distanceSPWN < 2000) then {
						distanceSPWN = distanceSPWN + 100;
						distanceSPWN1 = distanceSPWN * 1.3;
						distanceSPWN2 = distanceSPWN /2;
						publicVariable ""distanceSPWN"";
						publicVariable ""distanceSPWN1"";
						publicVariable ""distanceSPWN2""
					};
					hint format [""Spawn Distance Set to %1 meters. Be careful, this may affect game performance"", distanceSPWN];
				} else {
					hint ""Only Player Commander has access to this function"";
				};
			";
		};

		class HQ_button_Gstatic: RscButton {
			idc = -1;
			text = "-100 Spawn Dist."; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "
				if (player == theBoss) then {
					if (distanceSPWN > 600) then {
						distanceSPWN = distanceSPWN - 100;
						if (distanceSPWN < 600) then {distanceSPWN = 600};
						distanceSPWN1 = distanceSPWN * 1.3;
						distanceSPWN2 = distanceSPWN /2;
						if (distanceSPWN < 600) then {distanceSPWN = 600};
						publicVariable ""distanceSPWN"";
						publicVariable ""distanceSPWN1"";
						publicVariable ""distanceSPWN2"";
					};
					hint format [""Spawn Distance Set to %1 meters"", distanceSPWN]
				} else {
					hint ""Only Player Commander has access to this function"";
				};
			";
		};
	};
};
