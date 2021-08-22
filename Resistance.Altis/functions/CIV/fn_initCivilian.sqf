#define CIVIL_CONFIG missionConfigFile >> "Resistance" >> "Civilian"

#define SKILL_CONFIG CIVIL_CONFIG >> "skill"
#define UNIFORMS_CONFIG CIVIL_CONFIG >> "uniforms"
#define HEADGEARS_CONFIG CIVIL_CONFIG >> "headgears"

private _skill = (SKILL_CONFIG) call BIS_fnc_getCfgData;
private _uniforms = (UNIFORMS_CONFIG) call BIS_fnc_getCfgDataArray;
private _headgears = (HEADGEARS_CONFIG) call BIS_fnc_getCfgDataArray;

params ["_unit"];

_unit setSkill _skill;

_unit setUnitLoadout (configFile >> "EmptyLoadout");
_unit forceAddUniform (selectRandom _uniforms);
_unit addHeadgear (selectRandom _headgears);

_unit disableAI "TARGET";
_unit disableAI "AUTOTARGET";

[_unit, "NoVoice"] remoteExec ["setSpeaker", 0, _unit];

_unit addEventHandler ["HandleDamage", Civ_fnc_hCivilianDamage];
_unit addEventHandler ["killed", Civ_fnc_hCivilianKilled}];
