#define SLEEP_TIME 30
#define RUINS_RECORD [_buildingID, _ruinType, _ruinPosition, _ruinVectorUp, _ruinVectorDir]
#define RUINS_VAR_NAME "buildings"
#define BUILDING_ID_VAR_NAME "buildingID"

_this spawn
{
	params ["_previousObject", "_newObject", "_isRuin"];

	if (!_isRuin) exitWith {};

	private _ruinType = typeOf _newObject;
	private _ruinPosition = getPosWorld _newObject;
	private _ruinVectorUp = vectorUp _newObject;
	private _ruinVectorDir = vectorDir _newObject;

	private _buildingID = [_previousObject] call RES_fnc_getTerrainID;
	private _ruins = missionNamespace getVariable RUINS_VAR_NAME;
	_ruins pushBack RUINS_RECORD;

	sleep SLEEP_TIME;

	private _ruin = createVehicle [_ruinType, [0, 0, 0], [], 0, "CAN_COLLIDE"];

	_previousObject hideObjectGlobal true;
	_previousObject setDamage [0, false];
	_previousObject enableSimulationGlobal false;

	_ruin setVectorUp _ruinVectorUp;
	_ruin setVectorDir _ruinVectorDir;
	_ruin setPosWorld _ruinPosition;

	_ruin setVariable [BUILDING_ID_VAR_NAME, _buildingID];
};
