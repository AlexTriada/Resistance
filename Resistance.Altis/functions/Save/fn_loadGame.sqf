#define VARIABLES_CFG missionConfigFile >> "Resistance" >> "Variables"

private _classesCfgs = "true" configClasses (VARIABLES_CFG);

private ["_classCfg", "_classPropertiesCfgs"];

{
	_classCfg = _x;
	_classPropertiesCfgs = configProperties [_classCfg];

	private ["_classPropertyCfg", "_variableName", "_variableValue"];

	{
		_classPropertyCfg = _x;
		_variableName = configName _classPropertyCfg;
		_variableValue = [_variableName] call Save_fnc_loadVariable;

		missionNamespace setVariable [_variableName, _variableValue];

	} forEach _classPropertiesCfgs;

} forEach _classesCfgs;
