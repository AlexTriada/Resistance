#define RUIN_SLEEP_TIME 5
#define DAMAGED_SLEEP_TIME 0

#define BUILDING 'building'

#define IS_TERRAIN 'isTerrain'
#define IS_EDEN 'isEden'

#define DAMAGED_OBJECT 'damagedObject'

params ['_previousObject', '_newObject', '_isRuin'];

if (isObjectHidden _newObject) exitWith {};
if (isObjectHidden _previousObject) exitWith { _previousObject setDamage [0, false]; };
if (isNull _previousObject) exitWith {};
if (isNull _newObject) exitWith {};

private ['_building'];

_building = _previousObject getVariable [BUILDING, _previousObject];
_building setVariable [DAMAGED_OBJECT, _newObject];
_previousObject setVariable [BUILDING, _building];
_newObject setVariable [BUILDING, _building];

_this spawn
{
	scopeName 'main';

	params ['_previousObject', '_newObject', '_isRuin'];

	if !(isNull _previousObject) then
	{
		_previousObject hideObjectGlobal true;
		_previousObject allowDamage false;
	};

	private ['_createdObject', '_position', '_hitPointDamages', '_building'];

	toFixed 20;

	if (_isRuin) then
	{
		sleep RUIN_SLEEP_TIME;

		_building = _previousObject getVariable
			[BUILDING, (nearestObjects [_previousObject, [], 5]) #1];
	}
	else
	{
		sleep DAMAGED_SLEEP_TIME;

		if (damage _newObject >= 1) then
		{
			sleep RUIN_SLEEP_TIME;

			if (_previousObject getVariable [IS_TERRAIN, true]) then
			{
				sleep DAMAGED_SLEEP_TIME;

				_previousObject hideObjectGlobal true;
				_previousObject enableSimulationGlobal false;
				_previousObject setDamage [0, false];
			}
			else
			{
				deleteVehicle _previousObject;
			};

			breakOut "main";
		};

		_building = _previousObject getVariable [BUILDING, _previousObject];
	};

	_building setVariable [IS_EDEN, [_building] call RES_fnc_isEdenObject];

	_createdObject = [_newObject, _isRuin] call RES_fnc_createClone;

	_building setVariable [DAMAGED_OBJECT, _createdObject];
	_createdObject setVariable [BUILDING, _building];

	toFixed -1;

	if (isNull _previousObject) exitWIth {};
	if (_previousObject getVariable [IS_EDEN, false]) exitWith {};

	deleteVehicle _previousObject;
};
