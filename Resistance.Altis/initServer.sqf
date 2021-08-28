[] call RES_fnc_createSleepDogCycle;

if ("NewGame" call BIS_fnc_getParamValue == 1) then
{
	call RES_fnc_startNewGame;

	call RES_fnc_saveGame;
}
else
{
	call RES_fnc_loadGame;
};

if ("RandomCivilians" call BIS_fnc_getParamValue == 1) then
{
	[] spawn RES_fnc_createAmbientCivilianCycle;
};
