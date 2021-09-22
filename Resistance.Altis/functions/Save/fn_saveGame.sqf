#define VARIABLES_CFG missionConfigFile >> "Resistance" >> "Variables"
#define SAVED_TEXT "Game saved"

params [["_isNewGame", false]];

if !(_isNewGame) then
{
	if ("SaveDestruction" call BIS_fnc_getParamValue == 1) then
	{
		call RES_fnc_saveDamage;
	};
};

private _classesCfgs = "true" configClasses (VARIABLES_CFG);

private ["_classCfg", "_classPropertiesCfgs"];

{
	_classCfg = _x;
	_classPropertiesCfgs = configProperties [_classCfg];

	private ["_classPropertyCfg", "_variableName", "_variableValue"];

	{
		_classPropertyCfg = _x;
		_variableName = configName _classPropertyCfg;
		[_variableName] call RES_fnc_saveVariable;

	} forEach _classPropertiesCfgs;

} forEach _classesCfgs;

[SAVED_TEXT] remoteExecCall ["hint", 0];
