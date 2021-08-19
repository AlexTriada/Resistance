#define CIVIL_CONFIG missionConfigFile >> "Resistance" >> "Civilian"
#define UNIFORMS_CONFIG CIVIL_CONFIG >> "uniforms"
#define HEADGEARS_CONFIG CIVIL_CONFIG >> "headgears"

params ["_unit"];

_unit setSkill 0;

private _uniforms = UNIFORMS_CONFIG call BIS_fnc_getCfgDataArray;
private _headgears = HEADGEARS_CONFIG call BIS_fnc_getCfgDataArray;

_unit setUnitLoadout (configFile >> "EmptyLoadout");
_unit forceAddUniform (selectRandom _uniforms);
_unit addHeadgear (selectRandom _headgears);

_unit disableAI "TARGET";
_unit disableAI "AUTOTARGET";

[_unit, "NoVoice"] remoteExec ["setSpeaker", 0, _unit];

_unit addEventHandler ["HandleDamage", Civ_fnc_civilianHandleDamage];

_unit addEventHandler
[
	"killed",
	{
		_victim = _this select 0;
		_killer = _this select 1;
		if (time - (_victim getVariable ["lastInjuredByPlayer", 0]) < 120) then
		{
			_killer = _victim getVariable ["injuredByPlayer", _killer];
		};
		if (isNull _killer) then
		{
			_killer	= _victim;
		};
		if (_victim == _killer) then
		{
			_nul = [-1,-1,getPos _victim] remoteExec ["A3A_fnc_citySupportChange",2];
		}
		else
		{
			if (isPlayer _killer) then
			{
				if (_victim getVariable "unitType" == "C_man_w_worker_F") then {_killer addRating 1000};
				[-10,_killer] call A3A_fnc_playerScoreAdd;
			};
			_multiplier = 1;
			if ((_victim getVariable "unitType") == "C_journalist_F") then {_multiplier = 3};
			//Must be group, in case they're undercover.
			if (side group _killer == teamPlayer) then
			{
                Debug("aggroEvent | Rebels killed a civilian");
				[Occupants, 10 * _multiplier, 60] remoteExec ["A3A_fnc_addAggression",2];
				[1,0,getPos _victim] remoteExec ["A3A_fnc_citySupportChange",2];
			}
			else
			{
				if (side group _killer == Occupants) then
				{
					[Occupants, -5 * _multiplier, 60] remoteExec ["A3A_fnc_addAggression",2];
					[0,1,getPos _victim] remoteExec ["A3A_fnc_citySupportChange",2];
				}
				else
				{
					if (side group _killer == Invaders) then
					{
						[-1,1,getPos _victim] remoteExec ["A3A_fnc_citySupportChange",2];
					};
				};
			};
		};
	}
];
