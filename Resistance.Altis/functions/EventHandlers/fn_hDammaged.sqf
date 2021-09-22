params ["_unit", "_selection", "_damage", "_hitIndex", "_hitPoint", "_shooter", "_projectile"];

[missionNamespace, "Log", ["fn_hDammaged.sqf", _unit, _selection, _damage, _hitIndex, _hitPoint, _shooter, _projectile],
	false] call BIS_fnc_callScriptedEventHandler;
