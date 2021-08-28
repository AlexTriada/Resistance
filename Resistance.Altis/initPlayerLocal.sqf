call RES_fnc_briefing;

if (isMultiplayer) then
{
	call RES_fnc_initMultiPlayer;
}
else
{
	call RES_fnc_initSinglePlayer;
};

[player] call RES_fnc_addActionsAndEHs;
