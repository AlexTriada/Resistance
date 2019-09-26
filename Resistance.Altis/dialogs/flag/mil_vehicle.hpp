class buy_vehicle {
	idd = 100;
	movingenable = false;

	class controls {

		class HQ_box: BOX {
			idc = 101;
			text = $STR_antistasi_dialogs_generic_box_text;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.492103 * safezoneH;
		};

		class HQ_frame: RscFrame {
			idc = 102;
			text = $STR_antistasi_dialogs_vehicle_purchase_military_text;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.462103 * safezoneH;
		};

		class HQ_button_back: RscButton {
			idc = 103;
			text = $STR_antistasi_dialogs_generic_button_back_text;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0; createDialog ""vehicle_option"";";
		};

		class HQ_button_quad: RscButton {
			idc = 104;
			text = $STR_antistasi_dialogs_dialog_vehicle_purchase_military_quad_text;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closedialog 0; [vehSDKBike] spawn RES_fnc_addFIAveh;";
		};

		class HQ_button_offroad: RscButton {
			idc = 105;
			text = $STR_antistasi_dialogs_dialog_vehicle_purchase_military_offroad_text;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [vehSDKLightUnarmed] spawn RES_fnc_addFIAveh;";
		};

		class HQ_button_truck: RscButton {
			idc = 106;
			text = $STR_antistasi_dialogs_dialog_vehicle_purchase_military_truck_text;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [vehSDKTruck] spawn RES_fnc_addFIAveh;";
		};

		class HQ_button_Aoffroad: RscButton {
			idc = 107;
			text = $STR_antistasi_dialogs_dialog_vehicle_purchase_military_a_offroad_text;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [vehSDKLightArmed] spawn RES_fnc_addFIAveh;";
		};

		class HQ_button_MG: RscButton {
			idc = 108;
			text = $STR_antistasi_dialogs_dialog_vehicle_purchase_military_s_mg_text;
			tooltip = $STR_antistasi_dialogs_dialog_vehicle_purchase_military_s_mg_tooltip;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [SDKMGStatic] spawn RES_fnc_addFIAveh;";
		};

		class HQ_button_mortar: RscButton {
			idc = 109;
			text = $STR_antistasi_dialogs_dialog_vehicle_purchase_military_s_mortaRES_text;
			tooltip = $STR_antistasi_dialogs_dialog_vehicle_purchase_military_s_mortaRES_tooltip;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [SDKMortar] spawn RES_fnc_addFIAveh;";
		};

		class HQ_button_AT: RscButton {
			idc = 110;
			text = $STR_antistasi_dialogs_dialog_vehicle_purchase_military_s_at_text;
			tooltip = $STR_antistasi_dialogs_dialog_vehicle_purchase_military_s_at_tooltip;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [staticATteamPlayer] spawn RES_fnc_addFIAveh;";
		};

		class HQ_button_AA: RscButton {
			idc = 111;
			text = $STR_antistasi_dialogs_dialog_vehicle_purchase_military_s_aa_text;
			tooltip = $STR_antistasi_dialogs_dialog_vehicle_purchase_military_s_aa_tooltip;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0; [staticAAteamPlayer] spawn RES_fnc_addFIAveh;";
		};
	};
};
