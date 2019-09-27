/*
	Author: Triada

	Description:
	running when player was respawned

	Parameter(s):
	0: <OBJECT> new unit
	1: <OBJECT> old (killed) unit
	2: <STRING> respawn type
	3: <INT> respawn delay

	Return Value: none

	Example: add this to description.ext and dont forget create appropriate class in CfgFunctions

	respawnTemplates[] = {"RESISTANCE"};

	class CfgRespawnTemplates {
		class RESISTANCE {
			onPlayerRespawn = "RES_fnc_respawnPlayer";
		};
	};

	Public: No
*/

#include "script_component.hpp"

LOG("[Resistance] | Info | %1 Started")

if (!hasInterface) exitWith {};

params ["_newUnit", "_oldUnit", "_respawn", "_respawnDelay"];

private _unit = group player createUnit ["I_G_Survivor_F", objNull, [], 0, "CAN_COLLIDE"];
_unit setSkill 1;
_unit setPosWorld (getPosWorld _newUnit);
selectPlayer _unit;
deleteVehicle _newUnit;

{
	player addItem _x;
	player assignItem _x;
} forEach [
	"ItemMap",
	"ItemWatch",
	"ItemRadio",
	"ItemCompass"
];

LOG("[Resistance] | Info | %1 Finished")
