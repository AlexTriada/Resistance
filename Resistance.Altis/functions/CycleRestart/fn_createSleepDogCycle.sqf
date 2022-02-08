private _sleepDogs = missionNamespace getVariable "sleepDogs";
private ["_i", "_sleepDog"];

while { true } do
{
	sleep 1;

	_i = 0;

	while { _i < count _sleepDogs } do
	{
		_sleepDog = _sleepDogs # _i;
		_sleepDog params ["_args", "_scriptName", "_handle", "_dogTime"];

		if (time > _dogTime) then
		{
			terminate _handle;
			_sleepDogs deleteAt _i;

			_args spawn _scriptName;

			continue;
		};

		_i = _i + 1;
	};
};
