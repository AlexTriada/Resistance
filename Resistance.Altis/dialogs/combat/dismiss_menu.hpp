class dismiss_menu {
	idd = 100;
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
			text = "Dismiss Options"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.18 * safezoneH;//28
		};

		class HQ_button_Gsquad: RscButton {
			idc = -1;
			text = "Dismiss Units / Squad"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Dimiss selected units or squads, recovering it's cost to the proper resource pool";
			action = "closeDialog 0; if (count groupselectedUnits player > 0) then { [groupselectedUnits player] execVM ""REINF\dismissPlayerGroup.sqf""; } else { if (count (hcSelected player) > 0) then { [hcSelected player] execVM ""REINF\dismissSquad.sqf""; }; }; if ((count groupselectedUnits player == 0) && (count hcSelected player == 0)) then { hint ""No units or squads selected""; };";
		};

		class HQ_button_Gstatic: RscButton {
			idc = -1;
			text = "Garrison Units / Squads"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Adds selected units or squads to a map selected garrison";
			action = "closeDialog 0; if (count groupselectedUnits player > 0) then { [groupselectedUnits player] execVM ""REINF\addToGarrison.sqf""; } else { if (count (hcSelected player) > 0) then { [hcSelected player] execVM ""REINF\addToGarrison.sqf""; }; }; if ((count groupselectedUnits player == 0) && (count hcSelected player == 0)) then { hint ""No units or squads selected""; };";
		};
	};
};
