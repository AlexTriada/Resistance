params ["_ruins"];

private ["_building", "_ruinPosition"];

{
	_ruinPosition = _x #2;
	_building = [_ruinPosition #0, _ruinPosition #1] nearestObject (_x #0);
	_building hideObject true;
	_building enableSimulation false;
} forEach _ruins;
