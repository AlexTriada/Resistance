/*
	Author: Triada

	Description:
	???

	Parameter(s):
	0: The first argument <???>
	1: The second argument <???>

	Return Value:
	The return value <???>

	Example:
	...

	Public: Yes
*/
#include "script_component.hpp"

LOG("[Resistance] | Info | %1 Started")

params ["_varName"];

private _varValue = [_varName] call RES_fnc_ReturnSavedStat;

if (isNil "_varValue") exitWith {};
[_varName, _varValue] call RES_fnc_setStat;

LOG("[Resistance] | Info | %1 Finished")
