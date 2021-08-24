params ["_variableName"];

private _savedVariableName = format ["%1%2%3%4%5", "Resistance", worldName, _variableName];

profileNameSpace getVariable [_savedVariableName, 45];
