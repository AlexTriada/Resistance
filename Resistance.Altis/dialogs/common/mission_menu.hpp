class mission_menu {
	idd = -1;
	movingenable = false;

	class controls {

		class HQ_box: BOX {
			idc = -1;
			text = $STR_antistasi_dialogs_generic_box_text;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.492103 * safezoneH;
		};

		class HQ_frame: RscFrame {
			idc = -1;
			text = "Available Missions"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.462103 * safezoneH;
		};

		class HQ_button_back: RscButton {
			idc = -1;
			text = $STR_antistasi_dialogs_generic_button_back_text;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0;";
		};

		class HQ_button_AS: RscButton {
			idc = -1;
			text = "Assasination Mission"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "
				closeDialog 0;
				if (([player] call RES_fnc_isMember) || (not(isPlayer theBoss))) then {
					[[""AS""], ""RES_fnc_missionRequest""] call BIS_fnc_MP;
				} else {
					hint ""Only Player Commander has access to this function"";
				};
			";
		};

		class HQ_button_CONV: RscButton {
			idc = -1;
			text = "Convoy Ambush"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "
				closeDialog 0;
				if (([player] call RES_fnc_isMember) || (not(isPlayer theBoss))) then {
					[[""CONVOY""], ""RES_fnc_missionRequest""] call BIS_fnc_MP;
				} else {
					hint ""Only Player Commander has access to this function"";
				};
			";
		};

		class HQ_button_DES: RscButton {
			idc = -1;
			text = "Destroy Missions"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "
				closeDialog 0;
				if (([player] call RES_fnc_isMember) || (not(isPlayer theBoss))) then {
					[[""DES""], ""RES_fnc_missionRequest""] call BIS_fnc_MP;
				} else {
					hint ""Only Player Commander has access to this function"";
				};
			";
		};

		class HQ_button_LOG: RscButton {
			idc = -1;
			text = "Logistics Mission"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "
				closeDialog 0;
				if (([player] call RES_fnc_isMember) || (not(isPlayer theBoss))) then {
					[[""LOG""], ""RES_fnc_missionRequest""] call BIS_fnc_MP;
				} else {
					hint ""Only Player Commander has access to this function"";
				};
			";
		};

		class HQ_button_RES: RscButton {
			idc = -1;
			text = "Rescue Missions"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "
				closeDialog 0;
				if (([player] call RES_fnc_isMember) || (not(isPlayer theBoss))) then {
					[[""RES""], ""RES_fnc_missionRequest""] call BIS_fnc_MP;
				} else {
					hint ""Only Player Commander has access to this function"";
				};
			";
		};

		class HQ_button_vehicle: RscButton {
			idc = -1;
			text = "Conquest Missions"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "
				closeDialog 0;
				if (([player] call RES_fnc_isMember) || (not(isPlayer theBoss))) then {
					[[""CON""], ""RES_fnc_missionRequest""] call BIS_fnc_MP;
				} else {
					hint ""Only Player Commander has access to this function"";
				};
			";
		};

		class HQ_button_exit: RscButton {
			idc = -1;
			text = "EXIT"; //--- ToDo: Localize;
			x = 0.37749 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "closeDialog 0;";
		};
	};
};
