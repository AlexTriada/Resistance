params ["_object", "_damage", "_hitPointsDamage"];

_object setDamage [_damage, false];

if (_hitPointsDamage isEqualTo []) exitWith {};

[_object, _hitPointsDamage] remoteExec ["RES_fnc_setHitPointsDamage", 0, true];
