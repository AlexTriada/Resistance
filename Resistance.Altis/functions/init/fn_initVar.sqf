/*
	Author: Triada

	Description:
	Init global variables

	Parameter(s): none
	Return Value:
	true <BOOL>

	Example:
	[] call RES_fnc_initVar;

	Public: Yes
*/
#include "script_component.hpp"

LOG("[Resistance] | Info | %1 Started")

if (!isServer) exitWith { LOG("[Resistance] | Error | %1 | function run on client") };

hasTFAR = isClass (configFile >> "CfgPatches" >> "task_force_radio"); publicVariable hasTFAR;
hasACRE = isClass (configFile >> "cfgPatches" >> "acre_main"); publicVariable hasACRE;
hasACE = !(isNil "ace_common_fnc_isModLoaded");
hasACEHearing = isClass (configFile >> "CfgSounds" >> "ACE_EarRinging_Weak"); publicVariable hasACEHearing;
hasACEMedical = isClass (configFile >> "CfgSounds" >> "ACE_heartbeat_fast_3"); publicVariable hasACEMedical;
hasADVCPR = isClass (configFile >> "CfgPatches" >> "adv_aceCPR"); publicVariable hasADVCPR;
hasADVSplint = isClass (configFile >> "CfgPatches" >> "adv_aceSplint"); publicVariable hasADVSplint;
hasIFA = isClass (configFile >> "CfgPatches" >> "LIB_Core"); publicVariable hasIFA;
activeAFRF = isClass (configFile >> "CfgFactionClasses" >> "rhs_faction_vdv"); publicVariable activeAFRF;
activeUSAF = isClass (configFile >> "CfgFactionClasses" >> "rhs_faction_usarmy"); publicVariable activeUSAF;
activeGREF = isClass (configFile >> "CfgFactionClasses" >> "rhsgref_faction_tla"); publicVariable activeGREF;
has3CB = isClass (configfile >> "CfgPatches" >> "UK3CB_BAF_Weapons"); publicVariable has3CB;
hasFFAA = isClass (configfile >> "CfgPatches" >> "ffaa_armas"); publicVariable hasFFAA;

/*
  ██████╗██████╗  █████╗     ███████╗███████╗████████╗████████╗██╗███╗   ██╗ ██████╗ ███████╗
 ██╔════╝██╔══██╗██╔══██╗    ██╔════╝██╔════╝╚══██╔══╝╚══██╔══╝██║████╗  ██║██╔════╝ ██╔════╝
 ██║     ██████╔╝███████║    ███████╗█████╗     ██║      ██║   ██║██╔██╗ ██║██║  ███╗███████╗
 ██║     ██╔══██╗██╔══██║    ╚════██║██╔══╝     ██║      ██║   ██║██║╚██╗██║██║   ██║╚════██║
 ╚██████╗██████╔╝██║  ██║    ███████║███████╗   ██║      ██║   ██║██║ ╚████║╚██████╔╝███████║
  ╚═════╝╚═════╝ ╚═╝  ╚═╝    ╚══════╝╚══════╝   ╚═╝      ╚═╝   ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚══════╝
*/

if (hasTFAR) then {
	[] spawn {
		waitUntil {sleep 1; !isNil "TF_server_addon_version"};
		["TF_no_auto_long_range_radio", true, true, "mission"] call CBA_settings_fnc_set;

		if (hasIFA) then {
			["TF_give_personal_radio_to_regular_soldier", false, true, "mission"] call CBA_settings_fnc_set;
			["TF_give_microdagr_to_soldier", false, true, "mission"] call CBA_settings_fnc_set;
		};

		["TF_same_sw_frequencies_for_side", true, true, "mission"] call CBA_settings_fnc_set;
		["TF_same_lr_frequencies_for_side", true, true, "mission"] call CBA_settings_fnc_set;
	};
};

/*
  ██████╗██╗██╗   ██╗    ██╗   ██╗███╗   ██╗██╗████████╗███████╗
 ██╔════╝██║██║   ██║    ██║   ██║████╗  ██║██║╚══██╔══╝██╔════╝
 ██║     ██║██║   ██║    ██║   ██║██╔██╗ ██║██║   ██║   ███████╗
 ██║     ██║╚██╗ ██╔╝    ██║   ██║██║╚██╗██║██║   ██║   ╚════██║
 ╚██████╗██║ ╚████╔╝     ╚██████╔╝██║ ╚████║██║   ██║   ███████║
  ╚═════╝╚═╝  ╚═══╝       ╚═════╝ ╚═╝  ╚═══╝╚═╝   ╚═╝   ╚══════╝
*/

switch (true) do {
	case (worldName == "Tanoa"): {
		arrayCivs = [
			"C_man_1",
			"C_man_1_1_F",
			"C_man_1_2_F",
			"C_man_1_3_F",
			"C_man_hunter_1_F",
			"C_man_p_beggar_F",
			"C_man_p_beggar_F_afro",
			"C_man_p_fugitive_F",
			"C_man_p_shorts_1_F",
			"C_man_polo_1_F",
			"C_man_polo_2_F",
			"C_man_polo_3_F",
			"C_man_polo_4_F",
			"C_man_polo_5_F",
			"C_man_polo_6_F",
			"C_man_shorts_1_F",
			"C_man_shorts_2_F",
			"C_man_shorts_3_F",
			"C_man_shorts_4_F",
			"C_scientist_F",
			"C_Orestes",
			"C_Nikos",
			"C_Nikos_aged",
			"C_Man_casual_1_F_tanoan",
			"C_Man_casual_2_F_tanoan",
			"C_Man_casual_3_F_tanoan",
			"C_man_sport_1_F_tanoan",
			"C_man_sport_2_F_tanoan",
			"C_man_sport_3_F_tanoan",
			"C_Man_casual_4_F_tanoan",
			"C_Man_casual_5_F_tanoan",
			"C_Man_casual_6_F_tanoan"
		];
	};
	case (hasIFA): {
		arrayCivs = [
			"LIB_CIV_Assistant",
			"LIB_CIV_Assistant_2",
			"LIB_CIV_Citizen_1",
			"LIB_CIV_Citizen_2",
			"LIB_CIV_Citizen_3",
			"LIB_CIV_Citizen_4",
			"LIB_CIV_Citizen_5",
			"LIB_CIV_Citizen_6",
			"LIB_CIV_Citizen_7",
			"LIB_CIV_Citizen_8",
			"LIB_CIV_Doctor",
			"LIB_CIV_Functionary_3",
			"LIB_CIV_Functionary_2",
			"LIB_CIV_Functionary_4",
			"LIB_CIV_Villager_4",
			"LIB_CIV_Villager_1",
			"LIB_CIV_Villager_2",
			"LIB_CIV_Villager_3",
			"LIB_CIV_Woodlander_1",
			"LIB_CIV_Woodlander_3",
			"LIB_CIV_Woodlander_2",
			"LIB_CIV_Woodlander_4",
			"LIB_CIV_SchoolTeacher",
			"LIB_CIV_SchoolTeacher_2",
			"LIB_CIV_Rocker",
			"LIB_CIV_Worker_3",
			"LIB_CIV_Worker_1",
			"LIB_CIV_Worker_4",
			"LIB_CIV_Worker_2"
		];
	};
	default {
		arrayCivs = [
			"C_man_1",
			"C_man_1_1_F",
			"C_man_1_2_F",
			"C_man_1_3_F",
			"C_man_hunter_1_F",
			"C_man_p_beggar_F",
			"C_man_p_beggar_F_afro",
			"C_man_p_fugitive_F",
			"C_man_p_shorts_1_F",
			"C_man_polo_1_F",
			"C_man_polo_2_F",
			"C_man_polo_3_F",
			"C_man_polo_4_F",
			"C_man_polo_5_F",
			"C_man_polo_6_F",
			"C_man_shorts_1_F",
			"C_man_shorts_2_F",
			"C_man_shorts_3_F",
			"C_man_shorts_4_F",
			"C_scientist_F",
			"C_Orestes",
			"C_Nikos",
			"C_Nikos_aged"
		];
	};
};

if (has3CB) then {
	arrayCivs append [
		"UK3CB_CHC_C_BODYG",
		"UK3CB_CHC_C_CAN",
		"UK3CB_CHC_C_COACH",
		"UK3CB_CHC_C_DOC",
		"UK3CB_CHC_C_FUNC",
		"UK3CB_CHC_C_HIKER",
		"UK3CB_CHC_C_LABOUR",
		"UK3CB_CHC_C_PILOT",
		"UK3CB_CHC_C_POLITIC",
		"UK3CB_CHC_C_PROF",
		"UK3CB_CHC_C_VILL",
		"UK3CB_CHC_C_WORKER"
	];
};
/*
  ██████╗██╗██╗   ██╗    ██╗   ██╗███████╗██╗  ██╗██╗ ██████╗██╗     ███████╗███████╗
 ██╔════╝██║██║   ██║    ██║   ██║██╔════╝██║  ██║██║██╔════╝██║     ██╔════╝██╔════╝
 ██║     ██║██║   ██║    ██║   ██║█████╗  ███████║██║██║     ██║     █████╗  ███████╗
 ██║     ██║╚██╗ ██╔╝    ╚██╗ ██╔╝██╔══╝  ██╔══██║██║██║     ██║     ██╔══╝  ╚════██║
 ╚██████╗██║ ╚████╔╝      ╚████╔╝ ███████╗██║  ██║██║╚██████╗███████╗███████╗███████║
  ╚═════╝╚═╝  ╚═══╝        ╚═══╝  ╚══════╝╚═╝  ╚═╝╚═╝ ╚═════╝╚══════╝╚══════╝╚══════╝
*/
switch (true) do {
	case (hasIFA): {
		arrayCivVeh = [
			"LIB_DAK_OpelBlitz_Open",
			"LIB_GazM1",
			"LIB_GazM1_dirty",
			"LIB_DAK_Kfz1",
			"LIB_DAK_Kfz1_hood"
		];
		civBoats = [];
	};
	default {
		arrayCivVeh = [
			"C_Hatchback_01_F",
			"C_Hatchback_01_sport_F",
			"C_Offroad_01_F",
			"C_SUV_01_F",
			"C_Van_01_box_F",
			"C_Van_01_fuel_F",
			"C_Van_01_transport_F",
			"C_Truck_02_transport_F",
			"C_Truck_02_covered_F",
			"C_Offroad_02_unarmed_F"
		];
		civBoats = [
			"C_Boat_Civil_01_F",
			"C_Scooter_Transport_01_F",
			"C_Boat_Transport_02_F",
			"C_Rubberboat"
		];
	};
};

LOG("[Resistance] | Info | %1 Finished")
