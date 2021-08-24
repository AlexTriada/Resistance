#define VARIABLES_CFG missionConfigFile >> "Resistance" >> "Variables"

#define PARAMS_CFG VARIABLES_CFG >> "Params"
#define CAMPAIN_CFG VARIABLES_CFG >> "Campain"

private _propertiesCfgs = configProperties [PARAMS_CFG];

private ["_propertyCfg", "_propertyName"];

{
	_propertyCfg = _x;
	_propertyName = configName _propertyCfg;

	missionNamespace setVariable [_propertyName, _propertyName call BIS_fnc_getParamValue];

} forEach _propertiesCfgs;

_propertiesCfgs = configProperties [CAMPAIN_CFG];

{
	_propertyCfg = _x;
	_propertyName = configName _propertyCfg;
	_property = _propertyCfg call BIS_fnc_getCfgData;

	missionNamespace setVariable [_propertyName, _property];

} forEach _propertiesCfgs;
