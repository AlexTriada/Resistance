private _headlessClients = entities "HeadlessClient_F";
private _humanPlayers = allPlayers - _headlessClients;

selectRandom _humanPlayers
