params ["_unit"];

_unit addAction ["Сохранить игру", RES_fnc_saveGame, [], 0, false];
_unit addAction ["Загрузить игру", RES_fnc_loadGame, [], 0, false];
