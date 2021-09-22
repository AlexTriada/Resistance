#define NEW_GAME true

if ("Debug" call BIS_fnc_getParamValue == 1) then
{
	[missionNamespace, "Log", { diag_log (_this joinString " | "); }] call BIS_fnc_addScriptedEventHandler;
};

missionNamespace setVariable ["sleepDogs", []];
[] spawn RES_fnc_createSleepDogCycle;

if ("NewGame" call BIS_fnc_getParamValue == 1) then
{
	call RES_fnc_startNewGame;

	[NEW_GAME] spawn RES_fnc_saveGame;
}
else
{
	call RES_fnc_loadGame;
};

if ("RandomCivilians" call BIS_fnc_getParamValue == 1) then
{
	[] spawn RES_fnc_createAmbientCivilianCycle;
};

addMissionEventHandler ["BuildingChanged", RES_fnc_hBuildingChanged];
