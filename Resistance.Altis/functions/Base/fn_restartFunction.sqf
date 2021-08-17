params ["_functionInfo", "_index"];
_functionInfo params ["_time", "_handle", "_args", "_code", "_dogTime"];

terminate _handle;

sleepDogs = deleteAt _index;

[_args, _code, _dogTime] call BASE_fnc_spawnCycle;
