/*
	Author: Triada

	Description:
	???

	Parameter(s):
	0: The first argument <STRING>
	1: The second argument <OBJECT>

	Return Value:
	The return value <BOOL>

	Example:
	["varName", varValue] call RES_fnc_saveStat;

	Public: Yes
*/
#include "script_component.hpp"

LOG("[Resistance] | Info | %1 Started")

params ["_varName", "_varValue"];

if (!isNil "_varValue") then {
	private _varSaveName = [_varName] call RES_fnc_varNameToSaveName;
	profileNamespace setVariable [_varSaveName, _varValue];

	if (isDedicated) then {
		saveProfileNamespace;
	};
};

LOG("[Resistance] | Info | %1 Finished")
