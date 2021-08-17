[] spawn Base_fnc_createSleepDogCycle;

if ("NewGame" call BIS_fnc_getParamValue == 1) then
{
	call Init_fnc_startNewGame;
}
else
{
	call Init_fnc_loadSavedGame;
};

[[], CIV_fnc_ambientCivilians, 10] call Base_fnc_spawnCycle;