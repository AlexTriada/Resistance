params ["_unit"];

_unit addAction ["Сохранить игру", { [] remoteExec ["RES_fnc_saveGame", 2]; true }, [], 0, false];
_unit addAction ["Загрузить игру", { [] remoteExec ["RES_fnc_loadGame", 2]; true }, [], 0, false];
