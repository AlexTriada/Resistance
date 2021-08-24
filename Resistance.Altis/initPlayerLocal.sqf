call Init_fnc_briefing;

if (isMultiplayer) then
{
	call Init_fnc_initMultiPlayer;
}
else
{
	call Init_fnc_initSinglePlayer;
};

player addAction ["Сохранить игру", { call Save_fnc_saveGame; }, [], 0, false];
player addAction ["Загрузить игру", { call Save_fnc_loadGame; }, [], 0, false];
