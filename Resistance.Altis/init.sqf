#include "script_component.hpp"

#define ENABLE_3D_ICONS _icon3D == 1
#define LOAD_SERVER_SAVE _loadSave == 1

LOG("[Resistance] | Info | %1 Started")

if (hasInterface) then {

/*
    ████████╗███████╗    ██████╗  █████╗ ██████╗ ██╗ ██████╗
    ╚══██╔══╝██╔════╝    ██╔══██╗██╔══██╗██╔══██╗██║██╔═══██╗
       ██║   █████╗      ██████╔╝███████║██║  ██║██║██║   ██║
       ██║   ██╔══╝      ██╔══██╗██╔══██║██║  ██║██║██║   ██║
       ██║   ██║         ██║  ██║██║  ██║██████╔╝██║╚██████╔╝
       ╚═╝   ╚═╝         ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚═╝ ╚═════╝
*/

	// tf_radio_channel_name = "Resistance";
	// tf_radio_channel_password = "2112";

/*
    ██╗ ██████╗ ██████╗ ███╗   ██╗    ██████╗ ██████╗
    ██║██╔════╝██╔═══██╗████╗  ██║    ╚════██╗██╔══██╗
    ██║██║     ██║   ██║██╔██╗ ██║     █████╔╝██║  ██║
    ██║██║     ██║   ██║██║╚██╗██║     ╚═══██╗██║  ██║
    ██║╚██████╗╚██████╔╝██║ ╚████║    ██████╔╝██████╔╝
    ╚═╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝    ╚═════╝ ╚═════╝
*/
	private _icon3D = "icon3D" call BIS_fnc_getParamValue;

	if (ENABLE_3D_ICONS) then {
		[] spawn RES_fnc_unconsciousIcon;
	};
};

if (isServer) then {
	private _loadSave = "loadSave" call BIS_fnc_getParamValue;

	if (LOAD_SERVER_SAVE) then {
		[] call RES_fnc_loadServer;
	};
};


LOG("[Resistance] | Info | %1 Finished")
