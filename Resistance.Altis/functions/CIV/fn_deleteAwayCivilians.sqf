#define CIVILIAN_CONFIG missionConfigFile >> "Resistance" >> "Civilian"

private _maxDistanceToPlayer = (CIVILIAN_CONFIG  >> "maxDistanceToPlayer") call BIS_fnc_getCfgData;
private _aliveCivilians = call Civ_fnc_getAliveCivilians;
private _headlessClients = entities "HeadlessClient_F";
private _players = allPlayers - _headlessClients;

{
	if ([_x, _players, _maxDistanceToPlayer] call BASE_fnc_isFarFromObjects) then
	{
		deleteVehicle _x;
	};
} forEach _aliveCivilians;