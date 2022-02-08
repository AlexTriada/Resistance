/* ---------------------------------------------------------------------------------------------- */
/*                                      Макросы препроцессора                                     */
/* ---------------------------------------------------------------------------------------------- */

#define MILITARY_BUILDINGS_TYPES_CFG missionConfigFile >> "Resistance" >> "Building" >> "militaryTypes"

#define CIVILIAN_CFG missionConfigFile >> "Resistance" >> "Civilian"
#define CIVILIAN_TYPES_CFG CIVILIAN_CFG >> "types"
#define MAX_DISTANCE_TO_PLAYER_CFG CIVILIAN_CFG >> "maxDistanceToPlayer"
#define MIN_DISTANCE_TO_PLAYER_CFG CIVILIAN_CFG >> "minDistanceToPlayer"
#define MIN_DISTANCE_TO_CIVILIAN_CFG CIVILIAN_CFG >> "minDistanceToCivilian"
#define CIV_GROUP_SIZE_CFG CIVILIAN_CFG >> "groupSize"

/* ---------------------------------------------------------------------------------------------- */
/*                                         Исходные данные                                        */
/* ---------------------------------------------------------------------------------------------- */

/* -------------------------------- получаем настройки из конфига ------------------------------- */

private _militaryBuildingTypes = (MILITARY_BUILDINGS_TYPES_CFG) call BIS_fnc_getCfgDataArray;
private _civilianTypes = (CIVILIAN_TYPES_CFG) call BIS_fnc_getCfgDataArray;
private _maxDistanceToPlayer = (MAX_DISTANCE_TO_PLAYER_CFG) call BIS_fnc_getCfgData;
private _minDistanceToPlayer = (MIN_DISTANCE_TO_PLAYER_CFG) call BIS_fnc_getCfgData;
private _minDistanceToCivilian = (MIN_DISTANCE_TO_CIVILIAN_CFG) call BIS_fnc_getCfgData;
private _groupUnitsSize = (CIV_GROUP_SIZE_CFG) call BIS_fnc_getCfgData;

/* ------------------------- получаем настройки из глобальных переменных ------------------------ */

private _trafficRate = missionNamespace getVariable ["trafficRate", 0];
private _maxUnits = missionNamespace getVariable ["maxUnits", 140];

/* --------------------- получаем необходимые текущие данные для вычислений --------------------- */

private _aliveCivilians = call RES_fnc_getAliveCivilians;
private _headlessClients = entities "HeadlessClient_F";
private _players = allPlayers - _headlessClients;

/* ---------------------------------------------------------------------------------------------- */
/*                                        Главная процедура                                       */
/* ---------------------------------------------------------------------------------------------- */

/* --------------------------- подсчитываем количество активных юнитов -------------------------- */

private _allActiveUnitsCount =
{
	local _x && {
	simulationEnabled _x && {
	alive _x }}
} count allUnits;

/* --------------------- проверяем, достаточно ли юнитов или можно добавить --------------------- */

private _isEnoughCivilians = count _aliveCivilians >= _trafficRate
	|| { _allActiveUnitsCount >= _maxUnits };

/* ----------------------- если достаточно юнитов то выходим из процедуры ----------------------- */

if _isEnoughCivilians exitWith {};

/* --------------------- ищем здания, подходящие для спауна гражданских лиц --------------------- */

private _buildings = [];
private _nearestBuildings = [];
{
	_nearestBuildings = nearestTerrainObjects [_x, ["House"], _maxDistanceToPlayer];

	if (count _nearestBuildings == 0) then { continue; };

	_nearestBuildings = _nearestBuildings select 
	{ 
		!((typeOf _x) in _militaryBuildingTypes)
		&& { count (_x buildingPos -1) > 0
		&& { [_x, _players, _minDistanceToPlayer] call RES_fnc_isFarFromObjects
		&& { [_x, _aliveCivilians, _minDistanceToCivilian] call RES_fnc_isFarFromObjects }}}
	};

	if (count _nearestBuildings == 0) then { continue; };

	{ _buildings pushBack _x; } forEach _nearestBuildings;
} forEach _players;

/* ---------------------------- если нет зданий для спауна то выходим --------------------------- */

if (count _buildings == 0) exitWith {};

/* ------------------------------ ищем позицию для спауна в здании ------------------------------ */

private _building = selectRandom _buildings;
private _positionInBuilding = selectRandom (_building buildingPos -1);

/* ----------------------- если нет позиций для спауна в здании то выходим ---------------------- */

if (count _positionInBuilding == 0) exitWith {};

/* -------------------------- выбираем случайный тип гражданского лица -------------------------- */

private _type = selectRandom _civilianTypes;

/* --------------------------- создаём массив из групп гражданских лиц -------------------------- */

private _civilGroups = [];
{
	_civilGroups pushBackUnique (group _x);
} forEach _aliveCivilians;

/* ----------------------- выбираем группу, в которую добавим гражданского ---------------------- */

private _civilGroup = grpNull;
{
	_civilGroup = _x;

	if (count (units _x) < _groupUnitsSize) then { break; };
} forEach _civilGroups;

if (isNull _civilGroup) then { _civilGroup = createGroup civilian; };

/* ------------------------------------ создаём гражданского ------------------------------------ */

private _civilian = [_civilGroup, _type, [0, 0, 0], [], 0, "NONE"] call RES_fnc_createUnit;
_civilian setPosATL _positionInBuilding;
