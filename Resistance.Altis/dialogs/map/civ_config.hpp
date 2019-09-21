class civ_config {
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
			text = "Civ Presence Config"; //--- ToDo: Localize;
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
			text = "+1 Max Civs"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "
				if (player == theBoss) then {
					if (civPerc < 150) then {
						civPerc = civPerc + 1;
						if (civPerc > 150) then {
							civPerc = 150;
						};
						publicVariable ""civPerc"";
					};
					hint format [""Maximum Number of Civilians Set to %1"", civPerc];
				} else {
					hint ""Only Player Commander has access to this function"";
				};
			";
		};

		class HQ_button_Gstatic: RscButton {
			idc = -1;
			text = "-1 Max Civs"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "
				if (player == theBoss) then {
					if (civPerc > 0) then {
						civPerc = civPerc - 1;
						if (civPerc < 0) then {
							civPerc = 0;
						};
						publicVariable ""civPerc"";
					};
					hint format [""Maximum Number of Civilians Set to %1"", civPerc];
				} else {
					hint ""Only Player Commander has access to this function"";
				};
			";
		};
	};
};
