params ["_object", "_hitPointsDamage"];

{
	_object setHitIndex [_forEachIndex, _x, false];

} forEach (_hitPointsDamage #2);
