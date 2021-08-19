#define SLEEP_TIME 5

[_this, _fnc_scriptName, _thisScript, SLEEP_TIME] call Base_fnc_updateSleepDog;

call Civ_fnc_deleteAwayCivilians;
call Civ_fnc_addRandomCivilians;

sleep SLEEP_TIME;

_this spawn Civ_fnc_ambientCivilians;
