#define TYPES_TO_SAVE 	['BUILDING', 'HOUSE', 'LIGHTHOUSE', 'CHURCH', 'CHAPEL', 'VIEW-TOWER', 'POWER LINES', 'FUELSTATION', 'FENCE', 'WALL']
#define DAMAGED_OBJECT 'damagedObject'
#define DAMAGED_OBJECTS 'damagedObjects'
#define DAMAGED_BUILDINGS 'damagedBuildings'

toFixed 20;

private ['_object', '_damage', '_allHitPointsDamage', '_damagedObject'];

private _isNotDamaged =
{
	_damage == 0
	&& { _allHitPointsDamage isEqualTo []
	|| { (_allHitPointsDamage #2) findIf { _x != 0 } == -1 }}
};

private _halfWorld = worldSize / 2;
private _terrainObjects = nearestTerrainObjects [[_halfWorld, _halfWorld], TYPES_TO_SAVE, worldSize];

private _damagedTerrainObjects = [];
private _damagedTerrainBuildings = [];

private _saveObject =
{
	_damagedObject = _object getVariable DAMAGED_OBJECT;

	if (isNil '_damagedObject') then
	{
		if (isHidden _object) exitWith {};

		_damage = damage _object;
		_allHitPointsDamage = getAllHitPointsDamage _object;

		if ([_object] call _isNotDamaged) exitWith {};

		_damagedTerrainObjects pushBack
		[
			[_object] call RES_fnc_getTerrainID,	// 0
			getPosWorld _object, 					// 1
			_damage,								// 2
			_allHitPointsDamage						// 3
		];
	}
	else
	{
		_damagedTerrainBuildings pushBackUnique
		[
			[_object] call RES_fnc_getTerrainID,	// 0
			typeOf _damagedObject, 					// 1
			getPosWorld _damagedObject, 			// 2
			vectorUp _damagedObject, 				// 3
			vectorDir _damagedObject, 				// 4
			damage _damagedObject, 					// 5
			getAllHitPointsDamage _damagedObject  	// 6
		];
	};
};

{
	_object = _x;
	call _saveObject;

} forEach _terrainObjects;

private _edenObjects = [];

{
	_edenObjects = allMissionObjects _x;

	{
		_object = _x;
		call _saveObject

	} forEach _edenObjects;

} forEach TYPES_TO_SAVE;

missionNamespace setVariable [DAMAGED_OBJECTS, _damagedTerrainObjects];
missionNamespace setVariable [DAMAGED_BUILDINGS, _damagedTerrainBuildings];

toFixed -1;
