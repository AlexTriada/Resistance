private _unit = _this select 0;
_dam = _this select 2;
_proy = _this select 4;
_injurer = _this select 3;

if(!isNil "_injurer" && isPlayer _injurer) then
{
	_unit setVariable ["injuredByPlayer", _injurer, true];
	_unit setVariable ["lastInjuredByPlayer", time, true];
};

if (_proy == "") then
{
	if ((_dam > 0.95) and (!isPlayer _injurer)) then {_dam = 0.9};
};

_dam