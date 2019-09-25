/*
* Author: [Triada]
* [create 3D icon on uncoscious players]
*
* Arguments: none
*
* Return Value: none
*
* Example:
* [] spawn RES_fnc_unconscious
*
* Public: [No]
*/
#include "..\script_component.hpp"

#define DISTANCE_3D 10000
#define ICON_SIZE 0.8
#define ICON_COLOR [1, 0, 0, 1]

LOG("[Resistance] | Info | %1 Started")

addMissionEventHandler [
	"Draw3D", {
		{
			_pos = getPosWorld _x; _pos set [2, 0.1];

			if (((_x distance player) < DISTANCE_3D) && {_x getVariable "ACE_isUnconscious"}) then {
				drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Revive\overlayIcons\u100_ca.paa", ICON_COLOR, _pos, ICON_SIZE, ICON_SIZE, 0];
			};
		} forEach (playableUnits - [player]);
	}
];

LOG("[Resistance] | Info | %1 Finished")
