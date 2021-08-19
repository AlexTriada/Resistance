params ["_sleepDogID"];

private _sleepDogs = missionNamespace getVariable ["sleepDogs", []];
private _sleepDog = _sleepDogs select _sleepDogID;
_sleepDog params ["_args", "_scriptName", "_handle"];

terminate _handle;

call compile (format ["%1 spawn %2;", _args, _scriptName]);