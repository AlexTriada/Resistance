[] spawn Base_fnc_createSleepDogCycle;

sleep 1;

if ("NewGame" call BIS_fnc_getParamValue == 1) then
{
	call Init_fnc_startNewGame;

	call Save_fnc_saveGame;
}
else
{
	call Save_fnc_loadGame;
};

[] spawn Civ_fnc_createAmbientCivilianCycle;
