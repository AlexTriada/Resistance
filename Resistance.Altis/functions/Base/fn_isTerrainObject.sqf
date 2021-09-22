/*
	This function checking is this object is terrain object,
	working in all positions and states

	paramsters:
		_object - object to check;

	return: true, if the object is terrain object
			false, in all other stances

*/

params ["_object"];

private _nearTerrainObjects = nearestTerrainObjects [_object, [], 1];

(count _nearTerrainObjects > 0) && { _object == _nearTerrainObjects #0 }
