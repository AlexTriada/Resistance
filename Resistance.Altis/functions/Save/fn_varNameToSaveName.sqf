/*
	Author: Triada

	Description:
	???

	Parameter(s):
	0: The first argument <STRING>
	1: The second argument <OBJECT>
	2: Multiple input types <STRING|ARRAY|CODE>
	3: Optional input <BOOL> (default: true)
	4: Optional input with multiple types <CODE|STRING> (default: {true})
	5: Not mandatory input <STRING> (default: nil)

	Return Value:
	The return value <BOOL>

	Example:
	["varName"] call RES_fnc_vaarNameToSaveName;

	Public: Yes
*/
#include "script_component.hpp"

LOG("[Resistance] | Info | %1 Started")

params ["_varName"];

private ["_return"];

switch (true) do {
	case (worldName == "Tanoa"): {
		_return = _varName + serverID + campaignID + "WotP";
	};
	case (side group petros == independent): {
		_return = _varName + serverID + campaignID + "Antistasi" + worldName;
	};
	default {
		_return = _varName + serverID + campaignID + "AntistasiB" + worldName;
	};
};

LOG("[Resistance] | Info | %1 Finished")

_return
