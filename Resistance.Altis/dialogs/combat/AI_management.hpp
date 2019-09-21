class AI_management {
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
			text = "Battle Options"; //Battle Options
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
			text = "Temp. AI Control"; //Temp. AI Control
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Take personal control of the selected squad member or HC squad leader and be able to perform any kind of actions for 60 seconds. Control state will be cancelled if the player or the controlled unit receives any kind of damage";
			action = "
				closeDialog 0;
				if ((count groupselectedUnits player > 0) && (count hcSelected player > 0)) exitWith {
					hint ""You must select from HC or Squad Bars, not both"";
				};
				if (count groupselectedUnits player == 1) then {
					[groupselectedUnits player] execVM ""REINF\controlunit.sqf"";
				};
				if (count hcSelected player == 1) then {
					[hcSelected player] execVM ""REINF\controlHCsquad.sqf"";
				};
			";
		};

		class 8slots_R1: RscButton {
			idc = -1;
			text = "Auto Rearm \ Loot"; //Auto Rearm \ Loot
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "AI will search for better weapons, vests, helmets etc. if they are in a vehicle, they will just store what they scavenge in the vehicle. if not, they will equip them";
			action = "
				closeDialog 0;
				if (count groupselectedUnits player == 0) then {
					(units group player) spawn RES_fnc_rearmCall;
				} else {
					(groupselectedUnits player) spawn RES_fnc_rearmCall;
				};
			";
		};

		class 8slots_L2: RscButton {
			idc = -1;
			text = "Auto Heal"; //Auto Heal
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "AI squad mates will heal proactively each other";
			action = "
				if (autoHeal) then {
					autoHeal = false;
					hint ""Auto Healing disabled"";
				} else {
					autoHeal = true;
					hint ""Auto Heal enabled"";
					[] spawn RES_fnc_autoHealFnc;
				};
			";
		};

		class 8slots_R2: RscButton {
			idc = -1;
			text = "Squad SITREP"; //Squad SITREP
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Recover info about a HC squad status";
			action = "[""stats""] call RES_fnc_vehStats;";
		};

		class 8slots_L3: RscButton {
			idc = -1;
			text = "Garrison Units / Squads"; //Garrison Units / Squads
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Adds selected units or squads to a map selected garrison";
			action = "
				closeDialog 0;
				if (count groupselectedUnits player > 0) then {
					[groupselectedUnits player] execVM ""REINF\addToGarrison.sqf"";
				} else {
					if (count (hcSelected player) > 0) then {
						[hcSelected player] execVM ""REINF\addToGarrison.sqf"";
					};
				};
				if ((count groupselectedUnits player == 0) && (count hcSelected player == 0)) then {
					hint ""No units or squads selected"";
				};
			";
		};

		class 8slots_R3: RscButton {
			idc = -1;
			text = "Squad Add Vehicle"; //Squad Add Vehicle
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Look at some vehicle and assign it to the selected squad for it's use";
			action = "closeDialog 0; [] call RES_fnc_addSquadVeh;";
		};

		class 8slots_L4: RscButton {
			idc = -1;
			text = "Dismiss Units / Squad"; //Dismiss Units / Squad
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Dimiss selected units or squads, recovering it's cost to the proper resource pool";
			action = "
				closeDialog 0;
				if (count groupselectedUnits player > 0) then {
					[groupselectedUnits player] execVM ""REINF\dismissPlayerGroup.sqf"";
				} else {
					if (count (hcSelected player) > 0) then {
						[hcSelected player] execVM ""REINF\dismissSquad.sqf"";
					};
				};
				if ((count groupselectedUnits player == 0) && (count hcSelected player == 0)) then {
					hint ""No units or squads selected"";
				};
			";
		};

		class 8slots_R4: RscButton {
			idc = -1;
			text = "Mount / Dismount"; //Mount / Dismount
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Force squad to mount or dismount their assigned vehicle";
			action = "[""mount""] call RES_fnc_vehStats;";
		};
	};
};
