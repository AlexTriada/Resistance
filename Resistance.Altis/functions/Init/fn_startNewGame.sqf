missionNamespace setVariable ["trafficRate", "TrafficRate" call BIS_fnc_getParamValue];
missionNamespace setVariable ["maxUnits", "MaxUnits" call BIS_fnc_getParamValue];

private _serverID = profileNameSpace getVariable ["ss_ServerID", nil];