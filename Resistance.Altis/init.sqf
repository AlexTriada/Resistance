#include "script_component.hpp"

LOG("[Resistance] | Info | %1 Started")

if (isServer) then {

	private _loadSave = [false, true] select ("loadSave" call BIS_fnc_getParamValue);
	private "_campaignID";

	if (_loadSave) then {
		_campaignID = profileNameSpace getVariable ["RES_CampaignID", ""];
		[] call RES_fnc_loadServer;
	} else {
		_campaignID = str(round((random(100000)) + random 10000));
		profileNameSpace setVariable ["RES_CampaignID", _campaignID];
	};

	serverInitDone = true;
	publicVariable "serverInitDone";
};

if (hasInterface) then {
	//code
	waitUntil { sleep 1; if (serverInitDone) exitWith {true}; false };
	//code
};

private _gameMode = profileNamespace getVariable ["gameMode", ""];
private _frendEastWest = 0;

switch (_gameMode) do {
	case 1: { _frendEastWest = 0; };
	case 2: { _frendEastWest = 1; };
	case 3: { _frendEastWest = 1; "CSAT_carrier" setMarkerAlpha 0; };
	case 4: { _frendEastWest = 1; "NATO_carrier" setMarkerAlpha 0; };
};

WEST setFriend [EAST, _frendEastWest]; // надо проверить для JIP
EAST setFriend [WEST, _frendEastWest]; // надо проверить для JIP

/*
████████╗███████╗    ██████╗  █████╗ ██████╗ ██╗ ██████╗
╚══██╔══╝██╔════╝    ██╔══██╗██╔══██╗██╔══██╗██║██╔═══██╗
   ██║   █████╗      ██████╔╝███████║██║  ██║██║██║   ██║
   ██║   ██╔══╝      ██╔══██╗██╔══██║██║  ██║██║██║   ██║
   ██║   ██║         ██║  ██║██║  ██║██████╔╝██║╚██████╔╝
   ╚═╝   ╚═╝         ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚═╝ ╚═════╝
*/
tf_radio_channel_name = "Resistance";
tf_radio_channel_password = "2112";

LOG("[Resistance] | Info | %1 Finished")
