private _ruins = missionNamespace getVariable "buildings";

private ["_terrainObject", "_ruinType", "_posWorld", "_vectorWorld"];

{
	_terrainObject = _x #0;
	_ruinType = _x #1;
	_posWorld = _x #2;
	_vectorWorld = _x #3;

	hideObjectGlobal _terrainObject;
	_terrainObject enableSimulationGlobal false;

	_buildObject = _ruinType createVehicle [0, 0, 0];
	_buildObject setVectorDir _vectorWorld;
	_buildObject setPosWorld _posWorld;

} forEach _ruins;
