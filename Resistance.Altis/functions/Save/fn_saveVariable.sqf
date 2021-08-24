params ["_variableName"];

private _savedVariableName = format ["%1%2%3%4%5", "Resistance", worldName, _variableName];
private _variableValue = missionNamespace getVariable _variableName;

profileNameSpace setVariable [_savedVariableName, _variableValue];
