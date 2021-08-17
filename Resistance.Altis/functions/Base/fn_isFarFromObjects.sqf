params ["_unit", "_objects", "_distance"];

_objects findIf { _x distance _unit <= _distance } == -1