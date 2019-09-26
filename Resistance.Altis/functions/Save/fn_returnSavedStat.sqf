/*
	Author: Triada

	Description:
	???

	Parameter(s):
	0: The first argument <STRING>

	Return Value:
	The return value <ARRAY>

	Example:
	[varName] call RES_fnc_returnSavedStat;

	Public: Yes
*/
#include "..\script_component.hpp"

LOG("[Resistance] | Info | %1 Started")

_loadVariable = {
	params ["_varName"];
	private _varSaveName = [_varName] call RES_fnc_varNameToSaveName;
	profileNameSpace getVariable (_varSaveName)
};

params ["_varName"];

private _varValue = [_varName] call _loadVariable;

if (isNil "_varValue") then {
	private _spanishVarName = [_varName] call RES_fnc_translateVariable;
	_varValue = [_spanishVarName] call _loadVariable;
};

if (isNil "_varValue") exitWith {
	LOG_1("[Resistance] | ERROR | %1 | Variable %2 does not exist.", _varName)
};

LOG("[Resistance] | Info | %1 Finished")

_varValue
