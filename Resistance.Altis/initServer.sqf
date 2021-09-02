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

if ("SaveDestruction" call BIS_fnc_getParamValue == 1) then
{
	call RES_fnc_loadRuins;
	call RES_fnc_loadDestruction;
};

addMissionEventHandler ["BuildingChanged", RES_fnc_hBuildingChanged];
addMissionEventHandler ["EntityKilled", RES_fnc_hEntityKilled];
