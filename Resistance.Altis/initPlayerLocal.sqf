call Init_fnc_briefing;

if (isMultiplayer) then
{
	call Init_fnc_initMultiPlayer;
}
else
{
	call Init_fnc_initSinglePlayer;
};

