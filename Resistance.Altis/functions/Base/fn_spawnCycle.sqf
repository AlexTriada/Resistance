params ["_args", "_code", "_dogTime"];

private _scriptHandle = _args spawn _code;

sleepDogs pushBack [time + _dogTime, _scriptHandle, _args, _code, _dogTime];