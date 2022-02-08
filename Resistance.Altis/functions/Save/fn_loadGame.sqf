/* ---------------------------------------------------------------------------------------------- */
/*                                Макросы и директивы препроцессора                               */
/* ---------------------------------------------------------------------------------------------- */

#define VARIABLES_CFG missionConfigFile >> "Resistance" >> "Variables"

/* ---------------------------------------------------------------------------------------------- */
/*                                   Подготовка исходных данных                                   */
/* ---------------------------------------------------------------------------------------------- */

private _classesCfgs = "true" configClasses (VARIABLES_CFG);

/* ---------------------------------------------------------------------------------------------- */
/*                                          Начало работы                                         */
/* ---------------------------------------------------------------------------------------------- */

private ["_classCfg", "_classPropertiesCfgs"];

{
	_classCfg = _x;
	_classPropertiesCfgs = configProperties [_classCfg];

	private ["_classPropertyCfg", "_variableName", "_variableValue"];

	{
		_classPropertyCfg = _x;
		_variableName = configName _classPropertyCfg;
		_variableValue = [_variableName] call RES_fnc_loadVariable;

		missionNamespace setVariable [_variableName, _variableValue];

	} forEach _classPropertiesCfgs;

} forEach _classesCfgs;

if ("SaveDestruction" call BIS_fnc_getParamValue != 1) exitWith {};

[] spawn RES_fnc_loadDamage;
