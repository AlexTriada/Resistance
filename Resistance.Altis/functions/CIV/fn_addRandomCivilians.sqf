private _isNeedAddCivilian =
{
	private _trafficRate = missionNamespace getVariable ["TrafficRate", 0];
	private _maxUnits = missionNamespace getVariable ["MaxUnits", 140];
	private _aliveCivilians = call _getAliveCivilians;

	private _allActiveUnitsCount =
	{
		local _x && {
		simulationEnabled _x && {
		alive _x }}
	} count allUnits;

	count _aliveCivilians < _trafficRate
	&& { _allActiveUnitsCount < _maxUnits }
};

if !(call _isNeedAddCivilian) exitWith {};

private	_houses = (nearestTerrainObjects [player, ["House"], 300])
		select { count (_x buildingPos -1) > 0 };

private _listbld = ["Land_Cargo_Tower_V1_F","Land_Cargo_Tower_V1_No1_F","Land_Cargo_Tower_V1_No2_F","Land_Cargo_Tower_V1_No3_F","Land_Cargo_Tower_V1_No4_F","Land_Cargo_Tower_V1_No5_F","Land_Cargo_Tower_V1_No6_F","Land_Cargo_Tower_V1_No7_F","Land_Cargo_Tower_V2_F", "Land_Cargo_Tower_V3_F", "Land_Cargo_Tower_V4_F"];

private _listMilBld = _listbld + ["Land_Radar_01_HQ_F","Land_Cargo_HQ_V1_F","Land_Cargo_HQ_V2_F","Land_Cargo_HQ_V3_F","Land_Cargo_HQ_V4_F","Land_Cargo_Patrol_V1_F","Land_Cargo_Patrol_V2_F","Land_Cargo_Patrol_V3_F", "Land_Cargo_Patrol_V4_F","Land_HelipadSquare_F","Land_Posed","Land_Hlaska","Land_fortified_nest_small_EP1","Land_fortified_nest_small","Fort_Nest","Fortress1","Land_GuardShed","Land_BagBunker_Small_F","Land_BagBunker_01_small_green_F","Land_vn_b_tower_01","Land_vn_o_shelter_05","Land_vn_bagbunker_01_small_green_f","Land_vn_bagbunker_small_f", "Land_vn_o_tower_01","Land_vn_o_tower_02", "Land_vn_o_tower_03","Land_vn_hut_tower_01", "Land_vn_o_platform_05","Land_vn_o_platform_06","Land_vn_o_snipertree_01","Land_vn_o_snipertree_02","Land_vn_o_snipertree_03","Land_vn_o_snipertree_04","Land_vn_o_platform_01","Land_vn_o_platform_02","Land_vn_o_platform_03", "Land_vn_hlaska", "Land_vn_b_trench_bunker_04_01", "Land_vn_pillboxbunker_02_hex_f", "Land_vn_guardtower_01_f", "Land_vn_strazni_vez", "Land_vn_b_trench_firing_05", "Land_vn_cementworks_01_grey_f", "Land_vn_cementworks_01_brick_f", "Land_vn_radar_01_hq_f", "Land_vn_a_office01"];

_houses = _houses select { !((typeOf _x) in _listMilBld) };
private _numHouses = count _houses;

if (_numHouses <= 0) exitWith {};

_reset = false;

if (daytime < 8 || { daytime > 21 }) then { _numHouses = round (_numHouses / 2); };

if ({ _x distance player < 300 } count (call _getAliveCivilians) > _numHouses) exitWith {};

private _house = selectRandom _houses;

if ({ _x distance _house < 20 } count (allPlayers - (entities "HeadlessClient_F")) != 0) exitWith {};

if (isNull _group || { count (units _group) > 2 }) then { _group = createGroup civilian; };

private _posHouse = selectRandom (_house buildingPos -1);
private _unit = selectRandom ["C_man_polo_1_F","C_man_polo_1_F_afro","C_man_polo_1_F_asia","C_man_polo_1_F_euro","C_man_sport_1_F_tanoan"];

private _civilian = [_group, _unit, _posHouse, [],0, "NONE"] call Base_fnc_createUnit;
_civilian setPosATL _posHouse;

[_civilian] spawn CIV_fnc_initCivilian;

// if (_civilian == leader _civilian) then
// {
// 	[_civilian, "ambientCiv", "SAFE", "SPAWNED", "NOFOLLOW", "NOVEH2", "NOSHARE", "DoRelax"]
// 		execVM "scripts\UPSMON.sqf"
// };
//TODO delete UPSMON