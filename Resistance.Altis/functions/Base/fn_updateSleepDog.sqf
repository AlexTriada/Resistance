scopeName "main";

params ["_args", "_scriptName", "_scriptHandle", "_sleepTime"];

private _updatedTime = time + (_sleepTime * 2);
private _sleepDogs = missionNamespace getVariable ["sleepDogs", []];

{
	if ((_x #1) isEqualTo _scriptName) then
	{
		terminate (_x #2);

		_x set [3, _updatedTime];
		_x set [2, _scriptHandle];

		breakOut "main";
	};
} forEach _sleepDogs;

_sleepDogs pushBack [_args, _scriptName, _scriptHandle, _updatedTime];
missionNamespace setVariable ["sleepDogs", _sleepDogs];