params ["_unit"];

_unit addAction ["Сохранить игру", Save_fnc_saveGame, [], 0, false];
_unit addAction ["Загрузить игру", Save_fnc_loadGame, [], 0, false];
