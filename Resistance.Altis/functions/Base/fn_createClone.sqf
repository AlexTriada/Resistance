params ["_vehicle", "_isRuin"];

private _clone = createVehicle [typeOf _vehicle, [0, 0, 0], [], 0, "CAN_COLLIDE"];

toFixed 20;

_clone setVectorUp (vectorUp _vehicle);
_clone setVectorDir (vectorDir _vehicle);

private _damage = damage _newObject;
private _hitPointsDamage = getAllHitPointsDamage _newObject;

if !(_isRuin)
then { [_clone, _damage, _hitPointsDamage] call RES_fnc_setDamage; };

private _position = getPosWorld _vehicle;

deleteVehicle _vehicle;
_clone setPosWorld _position;

toFixed -1;

_clone
