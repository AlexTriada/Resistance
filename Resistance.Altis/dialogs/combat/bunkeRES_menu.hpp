class bunkeRES_menu {
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
			text = "Select Bunker Type"; //Select Bunker Type
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.18 * safezoneH;//28
		};

		class HQ_button_Gsquad: RscButton {
			idc = -1;
			text = "Sandbag Bunker"; //Sandbag Bunker
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Requires to be in a garrisoned zone. It will be permanent";
			action = "closeDialog 0; [""SB""] spawn RES_fnc_build;";
		};

		class HQ_button_Gstatic: RscButton {
			idc = -1;
			text = "Concrete Bunker"; //Concrete Bunker
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Requires to be in a garrisoned zone. It will be permanent";
			action = "closeDialog 0; [""CB""] spawn RES_fnc_build;";
		};
	};
};
