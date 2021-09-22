#define IS_HIDING "isHiding"

params ["_object"];

_object setVariable [IS_HIDING, true];

hideObject _object;
_object enableSimulation false;

_object setVariable [IS_HIDING, false];
