params ["_object"];

(allMissionObjects "") findIf { _x == _object } != -1
