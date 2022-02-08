/* ---------------------------------------------------------------------------------------------- */
/*                                Макросы и директивы препроцессора                               */
/* ---------------------------------------------------------------------------------------------- */

#define BUILDING 'building'
#define DAMAGED_OBJECT 'damagedObject'
#define DAMAGED_OBJECTS 'damagedObjects'
#define DAMAGED_BUILDINGS 'damagedBuildings'

/* ---------------------------------------------------------------------------------------------- */
/*                                   Подготовка исходных данных                                   */
/* ---------------------------------------------------------------------------------------------- */

waitUntil { sleep 0.1; !(isNil BIS_fnc_init) };

toFixed 20;

private _damagedTerrainObjects = missionNamespace getVariable [DAMAGED_OBJECTS, []];
private _damagedTerrainBuildings = missionNamespace getVariable [DAMAGED_BUILDINGS, []];

/* ---------------------------------------------------------------------------------------------- */
/*                                          Начало работы                                         */
/* ---------------------------------------------------------------------------------------------- */

/* ------------------------------------ Обрабатываем объекты ------------------------------------ */

private ["_object", "_objectID", "_damage", "_allHitPointsDamage"];

{
	_objectID = 			_x param [0];
	_position = 			_x param [1];
	_damage = 				_x param [2];
	_allHitPointsDamage = 	_x param [3];

	_object = [_position #0, _position #1] nearestObject _objectID;

	[_object, _damage, _allHitPointsDamage] call RES_fnc_setDamage;

} forEach _damagedTerrainObjects;

/* ------------------------------------- Обрабатываем здания ------------------------------------ */

private ["_building", "_buildingID", "_type", "_position", "_vectorUp", "_vectorDir", "_createdObject"];

{
	_buildingID = 			_x param [0];
	_type = 				_x param [1];
	_position = 			_x param [2];
	_vectorUp = 			_x param [3];
	_vectorDir = 			_x param [4];
	_damage = 				_x param [5];
	_allHitPointsDamage = 	_x param [6];

	_building = [_position #0, _position #1] nearestObject _buildingID;

	_building hideObjectGlobal true;
	_building allowDamage false;

	_createdObject = createVehicle [_type, [0, 0, 0], [], 0, "CAN_COLLIDE"];
	_building setVariable [DAMAGED_OBJECT, _createdObject];
	_createdObject setVariable [BUILDING, _building];

	[_createdObject, _damage, _allHitPointsDamage] call RES_fnc_setDamage;

	_createdObject setVectorUp _vectorUp;
	_createdObject setVectorDir _vectorDir;
	_createdObject setPosWorld _position;

} forEach _damagedTerrainBuildings;

toFixed -1;
