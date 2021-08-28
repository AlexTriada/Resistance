_this spawn
{

	params ["_unit", "_killer", "_instigator", "_useEffects"];

	if (isNull _killer) then { _killer	= _unit; };

	if (_unit == _killer) exitWith
	{
		[-1, -1, getPos _unit] remoteExec ["A3A_fnc_citySupportChange", 2];
	};

	private _players = call RES_fnc_getAllPLayers;

	if (_killer in _players) then
	{
		_killer addRating 1000;
		[-10, _killer] call A3A_fnc_playerScoreAdd;
	};
};
