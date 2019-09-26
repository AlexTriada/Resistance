class radio_comm {
	idd = -1;
	movingenable = false;

	class controls {
		//Menu Structure
		class 8slots_box: BOX {
			idc = -1;
			text = $STR_antistasi_dialogs_generic_box_text;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.492103 * safezoneH;
		};

		class 8slots_frame: RscFrame {
			idc = -1;
			text = "Battle Options"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.462103 * safezoneH;
		};

		class 8slots_Back: RscButton {
			idc = -1;
			text = $STR_antistasi_dialogs_generic_button_back_text;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;
			h = 0.05 * safezoneH;
			action = "closeDialog 0";
		};
		//Action Buttons
		class 8slots_L1: RscButton {
			idc = -1;
			text = "Fast Travel"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Teleport your squad or a HC selected squad to a friendly zone depending on several factors";
			action = "closeDialog 0; [] spawn RES_fnc_fastTravelRadio;";
		};

		class 8slots_R1: RscButton {
			idc = -1;
			text = "Player and Money"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Look at some player and interact with him";
			action = "closeDialog 0; if (isMultiPlayer) then {createDialog ""playeRES_money""} else {hint ""MP Only Menu""};";
		};

		class 8slots_L2: RscButton {
			idc = -1;
			text = "Undercover ON"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Become Undercover if you match the requirements. Enemy AI won't attack you until they discover you";
			action = "closeDialog 0; [] spawn RES_fnc_undercover;";
		};

		class 8slots_R2: RscButton {
			idc = -1;
			text = "Construct Here"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Construct in the spot where you are a selected building facing this direction";
			action = "closeDialog 0; createDialog ""construction_menu"";";
		};

		class 8slots_L3: RscButton {
			idc = -1;
			text = "Garage Vehicle"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Vehicle or Static gun you're looking at will be garaged, interact with Flag to retrieve";
			action = "closeDialog 0; if (player != theBoss) then {[false] call RES_fnc_garageVehicle} else {if (isMultiplayer) then {createDialog ""garage_check""} else {[true] call RES_fnc_garageVehicle}};";
		};

		class 8slots_R3: RscButton {
			idc = -1;
			text = "Unlock Vehicle"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Allow other groups to mount this vehicle";
			action = "closeDialog 0; [] call RES_fnc_unlockVehicle;";
		};

		class 8slots_L4: RscButton {
			idc = -1;
			text = "AI Management"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Several AI options";
			action = "if (player == leader group player) then {closeDialog 0; createDialog ""AI_management""} else {hint ""Only group leaders may access to this option""};";
		};

		class 8slots_R4: RscButton {
			idc = -1;
			text = "Commander"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Open commander options";
			action = "closeDialog 0; createDialog ""commandeRES_comm"";";
		};
	};
};
