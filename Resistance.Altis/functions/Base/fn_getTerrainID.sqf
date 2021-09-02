private _object = param [0, objNull];

if (isNull _object) exitWith { -1 };

private _objectStr = str _object;
private _startID = (_objectStr find "#") + 2;

if (_startID < 0) exitWith { -1 };

private _length = (_objectStr find ":") - _startID;

parseNumber (_objectStr select [_startID, _length])
