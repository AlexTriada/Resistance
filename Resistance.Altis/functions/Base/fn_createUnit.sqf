#define UNITS_CONFIG missionConfigFile >> "Resistance" >> "CustomUnit"

params ["_group", "_type", "_position", ["_markers", []], ["_placement", 0], ["_special", "NONE"]];

private _unitConfig = UNITS_CONFIG >> _type;
private _unit = objNull;

if (isClass _unitConfig) then
{
	private _configType = (_unitConfig >> "type") call BIS_fnc_getCfgData;
	private _loadouts = (_unitConfig >> "loadouts") call BIS_fnc_getCfgDataArray;
	private _traits = (_unitConfig >> "traits") call BIS_fnc_getCfgDataArray;

	_unit = _group createUnit  [_configType, _position, _markers, _placement, _special];
	_unit setUnitLoadout (selectRandom _loadouts);

	{ _unit setUnitTrait _x; } forEach _traits;
}
else
{
	_unit = _group createUnit  [_type, _position, _markers, _placement, _special];
};

_unit setVariable ["unitType", _type, true];
_unit setSkill 1;

_unit