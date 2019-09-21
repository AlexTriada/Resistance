class vehicle_manager {
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
			text = "Vehicle Manager"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.28 * safezoneH;//28
		};

		class HQ_button_back: RscButton {
			idc = -1;
			text = $STR_antistasi_dialogs_generic_button_back_text;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0; createDialog ""radio_comm"";";
		};

		class HQ_button_Gsquad: RscButton {
			idc = -1;
			text = "Garage\Sell Vehicle"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Add to garage / sell the vehicle you are currently looking at";
			action = "closeDialog 0; createDialog ""garage_sell"";";
		};

		class HQ_button_Gstatic: RscButton {
			idc = -1;
			text = "Vehicles and Squads"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Options related to vehicle management in HC controlled squads";
			action = "closeDialog 0; if (player == theBoss) then {createDialog ""squad_manager""} else {hint ""Only Player Commander has access to this function""};";
		};

		class HQ_button_Gremove: RscButton {
			idc = -1;
			text = "Add to Air Support"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Gain Airstrike points giving this vehicle to the faction Air pool";
			action = "closeDialog 0; [] call RES_fnc_addBombRun";
		};

		class HQ_button_unlock: RscButton {
			idc = -1;
			text = "Unlock Vehicle"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Allow other groups to mount this vehicle";
			action = "closeDialog 0; [] call RES_fnc_unlockVehicle";
		};
	};
};
