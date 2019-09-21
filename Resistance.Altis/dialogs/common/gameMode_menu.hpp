class gameMode_menu {
	idd = 100;
	movingenable = false;

	class controls {

		class HQ_box: BOX {
			idc = -1;
			text = $STR_antistasi_dialogs_generic_box_text;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.30 * safezoneH;
		};

		class HQ_frame: RscFrame {
			idc = -1;
			text = "Select your Game Mode"; //Select your Game Mode
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.28 * safezoneH;
		};

		class HQ_button_Gsquad: RscButton {
			idc = 104;
			text = "Reb vs Gov vs Inv"; //Reb vs Gov vs Inv
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; gameMode = 1;";
		};

		class HQ_button_Gstatic: RscButton {
			idc = 105;
			text = "Rev vs Gov & Inv"; //Rev vs Gov & Inv
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; gameMode = 2;";
		};

		class HQ_button_Gremove: RscButton {
			idc = 106;
			text = "Reb vs Gov"; //Reb vs Gov
			//x = 0.37749 * safezoneW + safezoneX;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; gameMode = 3;";
		};

		class HQ_button_offroad: RscButton {
			idc = 107;
		 	text = "Reb vs Inv"; //Reb vs Inv
			x = 0.272481 * safezoneW + safezoneX;
		 	y = 0.415981 * safezoneH + safezoneY;
		 	w = 0.175015 * safezoneW;
		 	h = 0.0560125 * safezoneH;
		 	action = "closeDialog 0; gameMode = 4;";
		 };
	};
};
