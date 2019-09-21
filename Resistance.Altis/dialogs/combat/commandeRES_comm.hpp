class commandeRES_comm {
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
			text = "Commander Battle Options"; //--- ToDo: Localize;
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
			action = "closeDialog 0; createDialog ""radio_comm"";";
		};
		//Action Buttons
		class 8slots_L1: RscButton {
			idc = -1;
			text = "Recruit Squad"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Recruit new squads and manage them with the HC Module (CTRL + SPACE)";
			action = "
				closeDialog 0;
				if (player == theBoss) then {
					[] spawn RES_fnc_squadRecruit;
				} else {
					hint ""Only Player Commander has access to this function"";
				};
			";
		};

		class 8slots_R1: RscButton {
			idc = -1;
			text = "Air Support"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Ask for Air Support (uses Airstrike points)";
			action = "
				closeDialog 0;
				if (player == theBoss) then {
					createDialog ""carpet_bombing"";
				} else {
					hint ""Only Player Commander has access to this function"";
				};
			";
		};

		class 8slots_L2: RscButton {
			idc = -1;
			text = "O.Post - Roadblock"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Establish a new watchpost or roadblock depending on the type of terrain you select";
			action = "
				if (player == theBoss) then {
					closeDialog 0;
					[""create""] spawn RES_fnc_outpostDialog;
				} else {
					hint ""You're not the Commander!"";
				};
			";
		};

		class 8slots_R2: RscButton {
			idc = -1;
			text = "Garbage Clean"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Cleans several things in game. Use with caution as it freezes the mission";
			action = "
				if (player == theBoss) then {
					closedialog 0;
					[] remoteExec [""RES_fnc_garbageCleaner"", 2];
				} else {
					hint ""Only Player Commander has access to this function"";
				};
			";
		};

		class 8slots_L3: RscButton {
			idc = -1;
			text = "O.Post-Roadblock Delete"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Remove selected observation post or roadblock, money will be refunded";
			action = "
				if (player == theBoss) then {
					closeDialog 0;
					[""delete""] spawn RES_fnc_outpostDialog;
				} else {
					hint ""You're not the Commander!"";
				};
			";
		};

		class 8slots_R3: RscButton {
			idc = -1;
			text = "Faction Garage"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Look at a vehicle and garage it into faction garage (shared among commanders)";
			action = "
				if (player == theBoss) then {
					closeDialog 0;
					[true] call RES_fnc_garageVehicle;
				} else {
					hint ""You're not the Commander!"";
				};
			";
		};

		class 8slots_L4: RscButton {
			idc = -1;
			text = "Resign / Eligible"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Step down from commander or toggle eligibility";
			action = "
				if (isMultiplayer) then {
					closedialog 0;
					execVM ""orgPlayers\commResign.sqf"";
				} else {
					hint ""This feature is MP Only"";
				};
			";
		};

		class 8slots_R4: RscButton {
			idc = -1;
			text = "Sell Vehicle"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Look at a vehicle and sell it for money";
			action = "
				if (player == theBoss) then {
					closeDialog 0;
					[] call RES_fnc_sellVehicle;
				} else {
					hint ""Only the Commander can sell vehicles"";
				};
			";
		};
	};
};
