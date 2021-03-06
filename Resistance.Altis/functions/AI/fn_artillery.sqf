if (!isServer and hasInterface) exitWith{};

private ["_mrkOrigin","_pos","_sideX","_countX","_mrkDestination","_veh","_posOrigin","_sidesOccupants","_posDestination","_typeVehX","_typeAmmunition","_size","_vehicle","_vehCrew","_groupVeh","_roundsX","_objectiveX","_objectivesX","_timeX"];

_mrkOrigin = _this select 0;
_posOrigin = if (_mrkOrigin isEqualType "") then {getMarkerPos _mrkOrigin} else {_mrkOrigin};
_mrkDestination = _this select 1;
_sideX = _this select 2;
_sidesOccupants = _sideX call BIS_fnc_enemySides;
_posDestination = getMarkerPos _mrkDestination;
_typeVehX = if (_sideX == Occupants) then {vehNATOMRLS} else {vehCSATMRLS};

if !([_typeVehX] call RES_fnc_vehAvailable) exitWith {};

_typeAmmunition = if (_sideX == Occupants) then {vehNATOMRLSMags} else {vehCSATMRLSMags};

_pos = [_posOrigin, 50,100, 10, 0, 0.3, 0] call BIS_Fnc_findSafePos;

_vehicle=[_pos, random 360,_typeVehX, _sideX] call bis_fnc_spawnvehicle;
_veh = _vehicle select 0;
_vehCrew = _vehicle select 1;
{[_x] call RES_fnc_NATOinit} forEach _vehCrew;
[_veh] call RES_fnc_AIVEHinit;
_groupVeh = _vehicle select 2;
_size = [_mrkDestination] call RES_fnc_sizeMarker;

if (_posDestination inRangeOfArtillery [[_veh], ((getArtilleryAmmo [_veh]) select 0)]) then
	{
	while {(alive _veh) and ({_x select 0 == _typeAmmunition} count magazinesAmmo _veh > 0) and (_mrkDestination in forcedSpawn)} do
		{
		_objectiveX = objNull;
		_roundsX = 1;
		_objectivesX = vehicles select {(side (group driver _x) in _sidesOccupants) and (_x distance _posDestination <= _size * 2) and (_sideX knowsAbout _x >= 1.4) and (speed _x < 1)};
		if (count _objectivesX > 0) then
			{
			{
			if (typeOf _x in vehAttack) exitWith {_objectiveX = _x; _roundsX = 4};
			} forEach _objectivesX;
			if (isNull _objectiveX) then {_objectiveX = selectRandom _objectivesX};
			}
		else
			{
			_objectivesX = allUnits select {(side (group _x) in _sidesOccupants) and (_x distance _posDestination <= _size * 2) and (_sideX knowsAbout _x >= 1.4) and (_x == leader group _x)};
			if (count _objectivesX > 0) then
				{
				_countX = 0;
				{
				_potential = _x;
				_countGroup = {(alive _x) and (!captive _x)} count units group _potential;
				if (_countGroup > _countX) then
					{
					if ((_sideX == Invaders) or ({(side (group _x) == civilian) and (_x distance _potential < 50)} count allUnits == 0)) then
						{
						_objectiveX = _potential;
						if (_countGroup > 6) then {_roundsX = 2};
						};
					};
				} forEach _objectivesX;
				};
			};
		if (!isNull _objectiveX) then
			{
			_veh commandArtilleryFire [position _objectiveX,_typeAmmunition,_roundsX];
			_timeX = _veh getArtilleryETA [position _objectiveX, ((getArtilleryAmmo [_veh]) select 0)];
			sleep 9 + ((_roundsX - 1) * 3);
			}
		else
			{
			sleep 29;
			};
		sleep 1;
		};
	};

if (!([distanceSPWN,1,_veh,teamPlayer] call RES_fnc_distanceUnits) and (({_x distance _veh <= distanceSPWN} count (allPlayers - (entities "HeadlessClient_F"))) == 0)) then {deleteVehicle _veh};

{
_veh = _x;
waitUntil {sleep 1; !([distanceSPWN,1,_veh,teamPlayer] call RES_fnc_distanceUnits) and (({_x distance _veh <= distanceSPWN} count (allPlayers - (entities "HeadlessClient_F"))) == 0)};
deleteVehicle _veh;
} forEach _vehCrew;

deleteGroup _groupVeh;
