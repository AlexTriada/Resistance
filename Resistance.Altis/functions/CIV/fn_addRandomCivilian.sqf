#define BUILDING_CFG missionConfigFile >> "Resistance" >> "Building"
#define CIVILIAN_CFG missionConfigFile >> "Resistance" >> "Civilian"

#define MILITARY_BUILDINGS_TYPES_CFG BUILDING_CFG >> "militaryTypes"
#define CIVILIAN_TYPES_CFG CIVILIAN_CFG >> "types"
#define MAX_DISTANCE_TO_PLAYER_CFG CIVILIAN_CFG >> "maxDistanceToPlayer"
#define MIN_DISTANCE_TO_PLAYER_CFG CIVILIAN_CFG >> "minDistanceToPlayer"
#define MIN_DISTANCE_TO_CIVILIAN_CFG CIVILIAN_CFG >> "minDistanceToCivilian"
#define CIV_GROUP_SIZE_CFG CIVILIAN_CFG >> "groupSize"

private _militaryBuildingTypes = (MILITARY_BUILDINGS_TYPES_CFG) call BIS_fnc_getCfgDataArray;
private _civilianTypes = (CIVILIAN_TYPES_CFG) call BIS_fnc_getCfgDataArray;
private _maxDistanceToPlayer = (MAX_DISTANCE_TO_PLAYER_CFG) call BIS_fnc_getCfgData;
private _minDistanceToPlayer = (MIN_DISTANCE_TO_PLAYER_CFG) call BIS_fnc_getCfgData;
private _minDistanceToCivilian = (MIN_DISTANCE_TO_CIVILIAN_CFG) call BIS_fnc_getCfgData;
private _groupUnitsSize = (CIV_GROUP_SIZE_CFG) call BIS_fnc_getCfgData;

private _aliveCivilians = call Civ_fnc_getAliveCivilians;
private _headlessClients = entities "HeadlessClient_F";
private _players = allPlayers - _headlessClients;
private _trafficRate = missionNamespace getVariable ["trafficRate", 0];
private _maxUnits = missionNamespace getVariable ["maxUnits", 140];

/* --------------------------------------- Private Methods -------------------------------------- */

private _isEnoughCivilians =
{
	private _allActiveUnitsCount =
	{
		local _x && {
		simulationEnabled _x && {
		alive _x }}
	} count allUnits;

	count _aliveCivilians >= _trafficRate
	|| { _allActiveUnitsCount >= _maxUnits }
};

private _isCorrectCivilBuilding =
{
	params ["_building"];

	!((typeOf _building) in _militaryBuildingTypes)
	&& { count (_building buildingPos -1) > 0
	&& { [_building, _players, _minDistanceToPlayer] call Base_fnc_isFarFromObjects
	&& { [_building, _aliveCivilians, _minDistanceToCivilian] call Base_fnc_isFarFromObjects }}}
};


private _findPositionForNewCivilian =
{
	private _nearPlayerBuildings = [];
	private _civilBuildings = [];

	{
		_nearPlayerBuildings = nearestTerrainObjects [_x, ["House"], _maxDistanceToPlayer];

		if (count _nearPlayerBuildings == 0) then { continue; };

		_correctPlayerCivilBuildings = _nearPlayerBuildings select { [_x] call _isCorrectCivilBuilding };

		if (count _correctPlayerCivilBuildings == 0) then { continue; };

		{ _civilBuildings pushBack _x; } forEach _correctPlayerCivilBuildings;
	} forEach _players;

	if (count _civilBuildings == 0) exitWith { [] };

	private _building = selectRandom _civilBuildings;

	selectRandom (_building buildingPos -1)
};

private _getCivilGroup =
{
	private _civilGroups = [];

	{
		_civilGroups pushBackUnique (group _x);
	} forEach _aliveCivilians;

	private "_group";

	{
		_group = _x;

		if (count (units _x) < _groupUnitsSize) then { break; };
	} forEach _civilGroups;

	if (isNil "_group") then
	{
		createGroup civilian
	}
	else
	{
		_group
	};
};

private _createCivilian =
{
	params ["_position"];

	private _type = selectRandom _civilianTypes;
	private _civilGroup = call _getCivilGroup;

	private _civilian = [_civilGroup, _type, [0, 0, 0], [], 0, "NONE"] call Base_fnc_createUnit;

	_civilian setPosATL _position;

	// [_civilian] spawn Civ_fnc_initCivilian;

	// if (_civilian == leader _civilian) then
	// {
	// 	[_civilian, "ambientCiv", "SAFE", "SPAWNED", "NOFOLLOW", "NOVEH2", "NOSHARE", "DoRelax"]
	// 		execVM "scripts\UPSMON.sqf"
	// };
	//TODO delete UPSMON

	_civilian
};

/* -------------------------------------------- Main -------------------------------------------- */

if (call _isEnoughCivilians) exitWith {};

private _civilianPosition = call _findPositionForNewCivilian;

if (count _civilianPosition == 0) exitWith {};

[_civilianPosition] call _createCivilian;
