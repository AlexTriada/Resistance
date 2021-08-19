missionNamespace setVariable ["sleepDogs", []];
private _sleepDogs = missionNamespace getVariable "sleepDogs";

while { true } do
{
	sleep 1;

	if (count _sleepDogs > 0) then
	{
		{
			if (time > _x #3) then
			{
				[_forEachIndex] spawn Base_fnc_restartFunction;
			};
		} forEach _sleepDogs;
	};
};