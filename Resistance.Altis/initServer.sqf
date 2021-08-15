if ("NewGame" call BIS_fnc_getParamValue == 1) then
{
	call Init_fnc_startNewGame;
}
else
{
	call Init_fnc_loadSavedGame;
};

[] spawn CIV_fnc_ambientCivilians;