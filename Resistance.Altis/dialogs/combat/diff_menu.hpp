class diff_menu {
	idd = -1;
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
			text = "Choose difficulty"; //Choose difficulty
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.28 * safezoneH;
		};

		class HQ_button_mortar: RscButton {
			idc = -1;
			text = "Easy"; //Easy
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; skillMult = 0.5;";
		};

		class HQ_button_MG: RscButton {
			idc = -1;
			text = "Normal"; //Normal
			x = 0.37749 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;";
		};

		class HQ_button_AT: RscButton {
			idc = -1;
			text = "Hard"; //Hard
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; skillMult = 2;";
		};
	};
};
