#define SLEEP_TIME 30

_this spawn
{
	params ["_previousObject", "_newObject", "_isRuin"];

	if (_isRuin) then
	{
		private _newType = typeOf _newObject;
		private _newPosW = getPosWorld _newObject;
		private _vectorDirW = vectorDirVisual _newObject;

		private _buildings = missionNamespace getVariable "buildings";
		_buildings pushBack [_previousObject, _newType, _newPosW, _vectorDirW];

		sleep SLEEP_TIME;

		hideObjectGlobal _previousObject;
		_previousObject setDamage [0, false];
		_previousObject enableSimulationGlobal false;

		private _buildObject = _newType createVehicle [0, 0, 0];
		_buildObject setVectorDir _vectorDirW;
		_buildObject setPosWorld _newPosW;
	};
};
