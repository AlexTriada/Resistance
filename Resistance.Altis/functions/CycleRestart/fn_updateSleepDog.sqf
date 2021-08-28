params ["_sleepDog", "_sleepTime"];

private _dogTime = _sleepTime call RES_fnc_getSleepDogTime;

_sleepDog set [3, _dogTime];
