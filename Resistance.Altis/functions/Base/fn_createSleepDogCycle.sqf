missionNamespace setVariable ["sleepDogs", []];

while { true } do
{
	sleep 1;

	if (count sleepDogs > 0) then
	{
		{
			if (time > _x #1) then
			{
				[_x, _forEachIndex] spawn Base_fnc_restartFunction;
			};
		} forEach sleepDogs;
	};
};