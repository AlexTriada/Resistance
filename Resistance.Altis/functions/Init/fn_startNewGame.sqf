missionNamespace setVariable ["trafficRate", "trafficRate" call BIS_fnc_getParamValue];
missionNamespace setVariable ["maxUnits", "maxUnits" call BIS_fnc_getParamValue];

private _serverID = profileNameSpace getVariable ["ss_ServerID", nil];