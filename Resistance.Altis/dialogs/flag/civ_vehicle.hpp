class civ_vehicle {
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
			text = $STR_antistasi_dialogs_dialog_vehicle_purchase_civ_text;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.28 * safezoneH;
		};

		class HQ_button_back: RscButton {
			idc = -1;
			text = $STR_antistasi_dialogs_generic_button_back_text;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0; createDialog ""vehicle_option"";";
		};

		class HQ_button_Gsquad: RscButton {
			idc = 104;
			text = $STR_antistasi_dialogs_dialog_vehicle_purchase_civ_offroad_text;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [civCar] spawn RES_fnc_addFIAveh;";
		};

		class HQ_button_Gstatic: RscButton {
			idc = 105;
			text = $STR_antistasi_dialogs_dialog_vehicle_purchase_civ_truck_text;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [civTruck] spawn RES_fnc_addFIAveh;";
		};

		class HQ_button_Gremove: RscButton {
			idc = 106;
			text = $STR_antistasi_dialogs_dialog_vehicle_purchase_civ_heli_text;
			//x = 0.37749 * safezoneW + safezoneX;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [civHeli] spawn RES_fnc_addFIAveh;";
		};

		class HQ_button_offroad: RscButton {
			idc = 107;
		 	text = $STR_antistasi_dialogs_dialog_vehicle_purchase_civ_boat_text;
			x = 0.272481 * safezoneW + safezoneX;
		 	y = 0.415981 * safezoneH + safezoneY;
		 	w = 0.175015 * safezoneW;
		 	h = 0.0560125 * safezoneH;
		 	action = "closeDialog 0; [civBoat] spawn RES_fnc_addFIAveh;";
		 };
	};
};
