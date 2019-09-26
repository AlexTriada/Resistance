class AI_management {
	idd = -1;
	movingenable = false;

	class controls {
		//Menu Structure
		class 8slots_box: BOX {
			idc = -1;
			text = "";
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.492103 * safezoneH;
		};

		class 8slots_frame: RscFrame {
			idc = -1;
			text = $STR_RES_AI_management_title; //Battle Options
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.462103 * safezoneH;
		};

		class 8slots_Back: RscButton {
			idc = -1;
			text = $STR_RES_back;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;
			h = 0.05 * safezoneH;
			action = "closeDialog 0; createDialog ""radio_comm"";";
		};
		//Action Buttons
		class 8slots_L1: RscButton {
			idc = -1;
			text = $STR_RES_AI_management_L1_text; //Temp. AI Control
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = $STR_RES_AI_management_L1_tooltip;
			action = "closeDialog 0; if ((count groupselectedUnits player > 0) && (count hcSelected player > 0)) exitWith { hint (""STR_RES_AI_management_L1_hint"" call BIS_fnc_localize); }; if (count groupselectedUnits player == 1) then { [groupselectedUnits player] spawn RES_fnc_controlunit; }; if (count hcSelected player == 1) then { [hcSelected player] spawn RES_fnc_controlHCsquad; };";
		};

		class 8slots_R1: RscButton {
			idc = -1;
			text = $STR_RES_AI_management_R1_text; //Auto Rearm \ Loot
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = $STR_RES_AI_management_R1_tooltip;
			action = "closeDialog 0; if (count groupselectedUnits player == 0) then { (units group player) spawn RES_fnc_rearmCall; } else { (groupselectedUnits player) spawn RES_fnc_rearmCall; };";
		};

		class 8slots_L2: RscButton {
			idc = -1;
			text = $STR_RES_AI_management_L2_text; //Auto Heal
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = $STR_RES_AI_management_L2_tooltip;
			action = "if (autoHeal) then { autoHeal = false; hint (""STR_RES_AI_management_L2_hint_dis"" call BIS_fnc_localize); } else { autoHeal = true; hint (""STR_RES_AI_management_L2_hint_en"" call BIS_fnc_localize); [] spawn RES_fnc_autoHealFnc; };";
		};

		class 8slots_R2: RscButton {
			idc = -1;
			text = $STR_RES_AI_management_R2_text; //Squad SITREP
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = $STR_RES_AI_management_R2_tooltip;
			action = "[""stats""] call RES_fnc_vehStats;";
		};

		class 8slots_L3: RscButton {
			idc = -1;
			text = $STR_RES_AI_management_L3_text; //Garrison Units / Squads
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = $STR_RES_AI_management_L3_tooltip;
			action = "closeDialog 0; if (count groupselectedUnits player > 0) then { [groupselectedUnits player] spawn RES_fnc_addToGarrison; } else { if (count (hcSelected player) > 0) then { [hcSelected player] spawn RES_fnc_addToGarrison; }; }; if ((count groupselectedUnits player == 0) && (count hcSelected player == 0)) then { hint (""STR_RES_AI_management_hint_nosel"" call BIS_fnc_localize); };";
		};

		class 8slots_R3: RscButton {
			idc = -1;
			text = $STR_RES_AI_management_R3_text; //Squad Add Vehicle
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.514003 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = $STR_RES_AI_management_R3_tooltip;
			action = "closeDialog 0; [] call RES_fnc_addSquadVeh;";
		};

		class 8slots_L4: RscButton {
			idc = -1;
			text = $STR_RES_AI_management_L4_text; //Dismiss Units / Squad
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = $STR_RES_AI_management_L4_tooltip;
			action = "closeDialog 0; if (count groupselectedUnits player > 0) then { [groupselectedUnits player] spawn RES_fnc_dismissPlayerGroup; } else { if (count (hcSelected player) > 0) then { [hcSelected player] spawn RES_fnc_dismissSquad; }; }; if ((count groupselectedUnits player == 0) && (count hcSelected player == 0)) then { hint (""STR_RES_AI_management_hint_nosel"" call BIS_fnc_localize); };";
		};

		class 8slots_R4: RscButton {
			idc = -1;
			text = $STR_RES_AI_management_R4_text; //Mount / Dismount
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.612025 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = $STR_RES_AI_management_R4_tooltip;
			action = "[""mount""] call RES_fnc_vehStats;";
		};
	};
};
