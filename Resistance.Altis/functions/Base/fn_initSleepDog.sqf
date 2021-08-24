params ["_args", "_scriptName", "_scriptHandle", "_sleepTime"];

private _sleepDogs = missionNamespace getVariable ["sleepDogs", []];
private _sleepDog = [_args, _scriptName, _scriptHandle, time + (_sleepTime * 2)];

_sleepDogs pushBack _sleepDog;

_sleepDog
