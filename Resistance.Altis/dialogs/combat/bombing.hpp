class tu_madre {
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

		class HQ_button_back: RscListBox {
			idc = -1;
			//text = $STR_antistasi_dialogs_generic_button_back_text;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 35) * 1.2)";
			colorText[] = {1, 1, 1, 1}; // Text and frame color
			colorDisabled[] = {1, 1, 1, 0.5}; // Disabled text color
			colorSelect[] = {1, 1, 1, 1}; // Text selection color
			colorSelect2[] = {1, 1, 1, 1}; // Text selection color (oscillates between this and colorSelect)
			colorShadow[] = {0, 0, 0, 0.5}; // Text shadow color (used only when shadow is 1)
			pictureColor[] = {1, 1, 1, 1}; // Picture color
			pictureColorSelect[] = {1, 1, 1, 1}; // Selected picture color
			pictureColorDisabled[] = {0, 1, 0, 1}; // Disabled picture color
		};

		class HQ_button_Gsquad: RscButton {
			idc = -1;
			text = "HE Bombs"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Cost: 10 points";
			action = "closeDialog 0; [""HE""] spawn RES_fnc_NATObomb;";
		};

		class HQ_button_Gstatic: RscButton {
			idc = -1;
			text = "Carpet Bombing"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Cost: 10 points";
			action = "closeDialog 0; [""CARPET""] spawn RES_fnc_NATObomb;";
		};

		class HQ_button_Gremove: RscButton {
			idc = -1;
			text = "NAPALM Bomb"; //--- ToDo: Localize;
			x = 0.37749 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Cost: 10 points";
			action = "closeDialog 0; [""NAPALM""] spawn RES_fnc_NATObomb;";
		};
	};
};
