#define SLEEP_TIME 5

private _sleepDog = [_this, _fnc_scriptName, _thisScript, SLEEP_TIME] call RES_fnc_initSleepDog;

while {true} do
{
	call RES_fnc_deleteAwayCivilians;
	call RES_fnc_addRandomCivilian;

	sleep SLEEP_TIME;

	[_sleepDog, SLEEP_TIME] call RES_fnc_updateSleepDog;
};
