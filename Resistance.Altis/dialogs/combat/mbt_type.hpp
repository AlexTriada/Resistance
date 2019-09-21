class mbt_type {
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
			text = "Select type ammo for the strike"; //Select type ammo for the strike
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
			action = "closeDialog 0";
		};

		class HQ_button_Gsquad: RscButton {
			idc = -1;
			text = "HE"; //HE
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; typeAmmunition = ""32Rnd_155mm_Mo_shells"";";
		};

		class HQ_button_Gstatic: RscButton {
			idc = -1;
			text = "Laser Guided"; //Laser Guided
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; typeAmmunition = ""2Rnd_155mm_Mo_LG"";";
		};

		class HQ_button_Gremove: RscButton {
			idc = -1;
			text = "Smoke"; //Smoke
			x = 0.37749 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; typeAmmunition = ""6Rnd_155mm_Mo_smoke"";";
		};
	};
};
