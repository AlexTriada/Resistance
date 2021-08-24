#define SLEEP_TIME 5

private _sleepDog = [_this, _fnc_scriptName, _thisScript, SLEEP_TIME] call Base_fnc_initSleepDog;

while {true} do
{
	[_sleepDog, SLEEP_TIME] call Base_fnc_updateSleepDog;

	call Civ_fnc_deleteAwayCivilians;
	call Civ_fnc_addRandomCivilian;

	sleep SLEEP_TIME;
};
