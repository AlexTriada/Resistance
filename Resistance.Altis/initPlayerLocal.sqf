#define TITLE "Разведка"
#define TEXT_INTEL "Вражеская база <marker name='Вражеская база'>161170</marker>"

if !(isMultiplayer) then
{
	{ deleteVehicle _x; } forEach (switchableUnits select { _x != player });
};

player createDiaryRecord ["Diary", [TITLE, TEXT_INTEL]];
