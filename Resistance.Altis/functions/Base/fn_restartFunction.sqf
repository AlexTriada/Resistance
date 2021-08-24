params ["_index"];

private _sleepDogs = missionNamespace getVariable ["sleepDogs", []];

private _sleepDog = _sleepDogs select _index;
_sleepDog params ["_args", "_scriptName", "_handle"];

terminate _handle;
_sleepDogs deleteAt _index;

call compile (format ["%1 spawn %2;", _args, _scriptName]);
