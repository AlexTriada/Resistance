if !(isNil "gameMenu") then {(findDisplay 46) displayRemoveEventHandler ["KeyDown", gameMenu]};
gameMenu = (findDisplay 46) displayAddEventHandler ["KeyDown",RES_fnc_keys];

if (player != theBoss) exitWith {};

if (count _this == 0) then {hint "Reinitialised:\n\nSpecial Keys\n\nStatistics Report"};
