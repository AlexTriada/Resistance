private _aliveCivilians = call CIV_fnc_getAliveCivilians;
private _headlessClients = entities "HeadlessClient_F";
private _humanPlayers = allPlayers - _headlessClients;

{
	if ([_x, _humanPlayers, CIV_DISTANCE] call BASE_fnc_isFarFromObjects) then
	{
		deleteVehicle _x;
	};
} forEach _aliveCivilians;