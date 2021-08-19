#define MAX_DISTANCE_TO_PLAYER_CONFIG (missionConfigFile >> "Resistance" >> "Civilian" >> "maxDistanceToPlayer")

private _maxDistanceToPlayer = MAX_DISTANCE_TO_PLAYER_CONFIG call BIS_fnc_getCfgData;
private _aliveCivilians = call Civ_fnc_getAliveCivilians;
private _headlessClients = entities "HeadlessClient_F";
private _players = allPlayers - _headlessClients;

{
	if ([_x, _players, _maxDistanceToPlayer] call BASE_fnc_isFarFromObjects) then
	{
		deleteVehicle _x;
	};
} forEach _aliveCivilians;