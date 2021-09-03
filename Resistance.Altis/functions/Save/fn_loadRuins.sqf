#define RUINS_VAR_NAME "buildings"
#define BUILDING_ID_VAR_NAME "buildingID"

private _ruins = missionNamespace getVariable RUINS_VAR_NAME;

private ["_buildingID", "_ruinType", "_ruinPosition", "_ruinVectorUp", "_ruinVectorDir", "_building"];

// [_ruins] remoteExec ["RES_fnc_hideObject", 0, true];

{
	_buildingID = _x #0;
	_ruinType = _x #1;
	_ruinPosition = _x #2;
	_ruinVectorUp = _x #3;
	_ruinVectorDir = _x #4;

	private _ruin = createVehicle [_ruinType, [0, 0, 0], [], 0, "CAN_COLLIDE"];

	_building = [_ruinPosition #0, _ruinPosition #1] nearestObject _buildingID;
	_building hideObjectGlobal true;
	_building enableSimulationGlobal false;

	_ruin setVectorUp _ruinVectorUp;
	_ruin setVectorDir _ruinVectorDir;
	_ruin setPosWorld _ruinPosition;

	_ruin setVariable [BUILDING_ID_VAR_NAME, _buildingID];

} forEach _ruins;
