#define SLEEP_TIME 5
#define RUINS_RECORD [_buildingID, _ruinType, _ruinPosW, _ruinVectorUpW, _ruinVectorDirW]
#define RUINS_VAR_NAME "buildings"
#define BUILDING_ID_VAR_NAME "buildingID"

_this spawn
{
	params ["_previousObject", "_newObject", "_isRuin"];

	diag_log (["building changed", _previousObject, _newObject] joinString " | ");

	if (!_isRuin) exitWith {};

	private _ruinType = typeOf _newObject;
	private _ruinPosW = getPosWorld _newObject;
	private _ruinVectorUpW = vectorUp _newObject;
	private _ruinVectorDirW = vectorDir _newObject;

	private _buildingID = [_previousObject] call RES_fnc_getTerrainID;
	private _ruins = missionNamespace getVariable RUINS_VAR_NAME;
	_ruins pushBack RUINS_RECORD;

	sleep SLEEP_TIME;

	_previousObject hideObjectGlobal true;
	_previousObject setDamage [0, false];
	_previousObject enableSimulationGlobal false;

	private _ruin = _ruinType createVehicle [0, 0, 0];

	diag_log ["create ruin", _ruin] joinString " | ";

	_ruin setVectorUp _ruinVectorUpW;
	_ruin setVectorDir _ruinVectorDirW;
	_ruin setPosWorld _ruinPosW;

	_ruin setVariable [BUILDING_ID_VAR_NAME, _buildingID];
};
