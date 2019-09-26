if (hasInterface) then {
  [] spawn RES_fnc_loadPlayer;
};

if (!isMultiplayer) then {
  [] spawn RES_fnc_loadServer;
};
