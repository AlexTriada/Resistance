[] call Base_fnc_createSleepDogCycle;

if ("NewGame" call BIS_fnc_getParamValue == 1) then
{
	call Init_fnc_startNewGame;

	call Save_fnc_saveGame;
}
else
{
	call Save_fnc_loadGame;
};

if ("RandomCivilians" call BIS_fnc_getParamValue == 1) then
{
	[] spawn Civ_fnc_createAmbientCivilianCycle;
};
