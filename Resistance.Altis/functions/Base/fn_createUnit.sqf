#define UNIT_CONFIG missionConfigFile >> "Resistance" >> "CustomUnit"

params ["_group", "_resistanceUnitType", "_position", ["_markers", []], ["_placement", 0], ["_special", "NONE"]];

private _unitCfg = UNIT_CONFIG >> _resistanceUnitType;
private _unit = objNull;

if (isClass _unitCfg) then
{
	private _unitType = (_unitCfg >> "type") call BIS_fnc_getCfgData;
	private _loadouts = (_unitCfg >> "loadouts") call BIS_fnc_getCfgDataArray;
	private _traits = (_unitCfg >> "traits") call BIS_fnc_getCfgDataArray;

	_unit = _group createUnit  [_unitType, _position, _markers, _placement, _special];
	_unit setUnitLoadout (selectRandom _loadouts);

	{ _unit setUnitTrait _x; } forEach _traits;
}
else
{
	_unit = _group createUnit  [_resistanceUnitType, _position, _markers, _placement, _special];
};

_unit setVariable ["unitType", _resistanceUnitType, true];
_unit setSkill 1;

_unit