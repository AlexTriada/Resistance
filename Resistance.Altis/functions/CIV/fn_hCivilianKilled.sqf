_this spawn
{

	params ["_unit", "_killer", "_instigator", "_useEffects"];

	if (isNull _killer) then { _killer	= _unit; };

	if (_unit == _killer) exitWith
	{
		[-1, -1, getPos _unit] remoteExec ["A3A_fnc_citySupportChange", 2]; 
	};

	private _players = call Base_fnc_getAllPLayers;

	if (_killer in _players) then
	{
		if (_unit getVariable "unitType" == "C_man_w_worker_F") then { _killer addRating 1000; };
		[-10, _killer] call A3A_fnc_playerScoreAdd;
	};

	_multiplier = 1;

	if ((_unit getVariable "unitType") == "C_journalist_F") then {_multiplier = 3};

	//Must be group, in case they're undercover.
	if (side group _killer == teamPlayer) then
	{
		[Occupants, 10 * _multiplier, 60] remoteExec ["A3A_fnc_addAggression",2];
		[1,0,getPos _unit] remoteExec ["A3A_fnc_citySupportChange",2];
	}
	else
	{
		if (side group _killer == Occupants) then
		{
			[Occupants, -5 * _multiplier, 60] remoteExec ["A3A_fnc_addAggression",2];
			[0,1,getPos _unit] remoteExec ["A3A_fnc_citySupportChange",2];
		}
		else
		{
			if (side group _killer == Invaders) then
			{
				[-1,1,getPos _unit] remoteExec ["A3A_fnc_citySupportChange",2];
			};
		};
	};
};

true