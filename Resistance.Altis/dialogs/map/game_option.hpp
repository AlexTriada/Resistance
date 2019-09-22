class game_options {
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
			text = "Game Options"; //--- ToDo: Localize;
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
			action = "closeDialog 0;";
		};
		//Action Buttons
		class 8slots_L1: RscButton {
			idc = -1;
			text = "Civ Limit"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Set the max number of spawned civilians. Affects game performance";
			action = "if (player == theBoss) then { closeDialog 0; createDialog ""civ_config""; } else { hint ""Only Player Commander has access to this function""; };";
		};

		class 8slots_R1: RscButton {
			idc = -1;
			text = "Spawn Distance"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Affects performance. Please use this with caution. Set it to lower distances if you feel Antistasi is running bad";
			action = "if (player == theBoss) then { closeDialog 0; createDialog ""spawn_config""; } else { hint ""Only Player Commander has access to this function""; };";
		};

		class 8slots_L2: RscButton {
			idc = -1;
			text = "AI Limiter"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Sets how much local and simulated AI can spawn in the map. Affects performance and AI ""intelligence"". Use with caution. This is not an exact number as vehicles and squad leaders will allways spawn";
			action = "if (player == theBoss) then { closeDialog 0; createDialog ""fps_limiter""; } else { hint ""Only Player Commander has access to this function""; };";
		};

		class 8slots_R2: RscButton {
			idc = -1;
			text = "Music ON/OFF"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Disables/Enable situational music";
			action = "closedialog 0; if (musicON) then { musicON = false; hint ""Music turned OFF""; } else { musicON = true; hint ""Music turned ON""; }; execVM ""musica.sqf"";";
		};

		class 8slots_M4: RscButton {
			idc = -1;
			text = "Persistent Save"; //--- ToDo: Localize;
			x = 0.37749 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Use this option to save your current game. It does save the most important data in a ""Grand Theft Auto"" way. This opnion allows good MP save and independent saves of any version update. Vanilla saves are disabled because of lack of several features";
			action = "closeDialog 0; if (player == theBoss) then { [""statSave\saveLoop.sqf"", ""BIS_fnc_execVM""] call BIS_fnc_MP; } else { [] execVM ""statSave\saveLoop.sqf""; hintC ""Personal Stats Saved""; };";
		};
	};
};
