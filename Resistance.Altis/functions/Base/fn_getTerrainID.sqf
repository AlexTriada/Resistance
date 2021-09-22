params ["_object"];

if (isNull _object) exitWith { -1 };

private _strings = (str _object) splitString ' ';

private _result = switch (count _strings) do
{
	case 2: { _strings #0 };
	case 3: { _strings #1 };
	default { '-1:' };
};

parseNumber (_result select [0, (count _result) - 1])
