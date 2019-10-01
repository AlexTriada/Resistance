/*
	Author: Triada

	Description:
	initialising BOX

	Parameter(s):
	0: box <OBJECT> default: objNull
	1: optional array of weapon types side NATO <ARRAY> default: []
	2: optional array of weapon types side CSAT <ARRAY> defaut: []
	3: optional array of items side AAF <ARRAY> default: []
	4: optional array of mines side AAF <ARRAY> default: []
	5: optional array of opticals side AAF <ARRAY> default: []
	6: has TFAR mod <BOOL> default: false

	Return Value: true

	Example:
	[wpnNATO, wpnCSAT, itemsAAF, minesAAF, opticalsAAF, true] spawn RES_fnc_boxAAF;

	Public: No
*/
#include "script_component.hpp"

#define CHANCE_NATO_WEAPON_TYPE 50 // in percent
#define MAG_PER_WEAPON 10

#define MIN_WEAPON_TYPES 1
#define MAX_WEAPON_TYPES 4
#define MIN_WEAPON_COUNT 1
#define MAX_WEAPON_COUNT 4

#define MIN_ITEMS_TYPES 1
#define MAX_ITEMS_TYPES 6
#define MIN_ITEM_COUNT 1
#define MAX_ITEM_COUNT 5

#define MIN_MINES_TYPES 1
#define MAX_MINES_TYPES 3
#define MIN_MINES_COUNT 1
#define MAX_MINES_COUNT 5

#define MIN_OPTIC_TYPES 1
#define MAX_OPTIC_TYPES 2
#define MIN_OPTIC_COUNT 1
#define MAX_OPTIC_COUNT 2

#define LONG_RANGE_TFR "tf_rt1523g_big_bwmod"

LOG("[Resistance] | Info | %1 Started")

if (!isServer) exitWith {false};

params [
	["_box", objNull],
	["_wpnNATO", [], [[""]]],
	["_wpnCSAT", [], [[""]]],
	["_itemsAAF", [], [[""]]],
	["_minesAAF", [], [[""]]],
	["_opticsAAF", [], [[""]]],
	["_hasTFAR", false]
];

if (_box isEqualTo objNull) exitWith {
	LOG("[Resistance] | Error | %1 | aborting, box is null")
	false
};

private ["_thingX", "_num", "_mag"];

clearWeaponCargoGlobal _box;
clearMagazineCargoGlobal _box;
clearItemCargoGlobal _box;
clearBackpackCargoGlobal _box;

for "_i" from 1 to (MIN_WEAPON_TYPES + floor random (1 + MAX_WEAPON_TYPES - MIN_WEAPON_TYPES)) do {

	if (CHANCE_NATO_WEAPON_TYPE > random 100) then {
		_thingX = selectRandom _wpnNATO;
	} else {
		_thingX = selectRandom _wpnCSAT;
	};

	if !(isNil "_thingX") then {
		_num = MIN_WEAPON_COUNT + floor random (1 + MAX_WEAPON_COUNT - MIN_WEAPON_COUNT);
		_box addWeaponCargoGlobal [_thingX, _num];
		_mag = (getArray (configFile >> "CfgWeapons" >> _thingX >> "magazines")) select 0;
		_box addMagazineCargoGlobal [_mag, _num * MAG_PER_WEAPON];
	};
};

if !(_itemsAAF isEqualTo []) then {
	for "_i" from 1 to (MIN_ITEMS_TYPES + floor random (1 + MAX_ITEMS_TYPES - MIN_ITEMS_TYPES)) do {
		_thingX = selectRandom _itemsAAF;
		_num = MIN_ITEM_COUNT + floor random (1 + MAX_ITEM_COUNT - MIN_ITEM_COUNT);
		_box addItemCargoGlobal [_thingX, _num];
	};
};

if !(_minesAAF isEqualTo []) then {
	for "_i" from 1 to (MIN_MINES_TYPES + floor random (1 + MAX_MINES_TYPES - MIN_MINES_TYPES)) do {
		_thingX = selectRandom _minesAAF;
		_num = MIN_MINES_COUNT + floor random (1 + MAX_MINES_COUNT - MIN_MINES_COUNT);
		_box addMagazineCargoGlobal [_thingX, _num];
	};
};

if !(_opticsAAF isEqualTo []) then {
	for "_i" from 1 to (MIN_OPTIC_TYPES + floor random (1 + MAX_OPTIC_TYPES - MIN_OPTIC_TYPES)) do {
		_thingX = selectRandom _opticsAAF;
		_num = MIN_OPTIC_COUNT + floor random (1 + MAX_OPTIC_COUNT - MIN_OPTIC_COUNT);
		_box addItemCargoGlobal [_thingX, _num];
	};
};

if (_hasTFAR) then {
	_box addBackpackCargoGlobal [LONG_RANGE_TFR, 1];
};

LOG("[Resistance] | Info | %1 Finished")

true
