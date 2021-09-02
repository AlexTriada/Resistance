private _ruins = missionNamespace getVariable "buildings";

private ["_buildingID", "_ruinType", "_ruinPosW", "_ruinVectorUpW", "_ruinVectorDirW", "_building"];

[_ruins] remoteExec ["RES_fnc_hideObject", 0, true];

{
	_buildingID = _x #0;
	_ruinType = _x #1;
	_ruinPosW = _x #2;
	_ruinVectorUpW = _x #3;
	_ruinVectorDirW = _x #4;

	private _ruin = _ruinType createVehicle [0, 0, 0];

	diag_log (["load ruin", _ruin] joinString " | ");

	_ruin setVectorUp _ruinVectorUpW;
	_ruin setVectorDir _ruinVectorDirW;
	_ruin setPosWorld _ruinPosW;

	_ruin setVariable ["buildingID", _buildingID];

} forEach _ruins;
