{
if (vehicle _x == _x) then {[_x] spawn RES_fnc_autoRearm} else {[_x,vehicle _x] spawn RES_fnc_autoLoot};
sleep 3+(random 5)
} forEach _this;
