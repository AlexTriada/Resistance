_moneyX = _this select 0;

_moneyX = _moneyX + (player getVariable "moneyX");
if (_moneyX < 0) then {_moneyX = 0};
player setVariable ["moneyX",_moneyX,true];
[] spawn RES_fnc_statistics;
["moneyX",_moneyX] call fn_SaveStat;
true
