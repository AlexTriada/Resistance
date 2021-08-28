params ["_args", "_scriptName", "_scriptHandle", "_sleepTime"];

private _sleepDogs = missionNamespace getVariable ["sleepDogs", []];
private _dogTime = _sleepTime call RES_fnc_getSleepDogTime;
private _sleepDog = [_args, _scriptName, _scriptHandle, _dogTime];

_sleepDogs pushBack _sleepDog;

_sleepDog
