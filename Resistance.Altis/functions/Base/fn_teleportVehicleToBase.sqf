params ["_vehicle"];

if (isNil "_vehicle" || isNull _vehicle) exitWith {};

private _boundingSphereDiameter = ((boundingBox _vehicle) select 2) + 1;

private ["_possiblePosition", "_newPosition", "_checkedPosition"];

for "_i" from 1 to 20 do {

	_possiblePosition = [(getMarkerPos respawnTeamPlayer), 20, 60, _boundingSphereDiameter, 0, 0.3] call BIS_fnc_findSafePos;

	if (count _possiblePosition > 0) then {
		_checkedPosition = _possiblePosition findEmptyPosition [0,0, typeOf _vehicle];
	} else {
		_checkedPosition = [];
	};

	if (count _checkedPosition > 0) exitWith {_newPosition = _checkedPosition};
};

if (count _newPosition == 0) exitWith {
	diag_log "[Antistasi] Couldn't find a safe position to teleport vehicle to base.";
	false;
};

_vehicle setVelocity [0, 0, 0];
_vehicle engineOn false;
_vehicle allowDamage false;
_vehicle enableSimulation false;

_vehicle setPos _newPosition;
_vehicle setVectorUp (surfaceNormal _newPosition);

[_vehicle] spawn {
	params ["_vehicle"];
	sleep 1;
	_vehicle allowDamage true;
	_vehicle enableSimulation true;
};

true;
