#define SKILL_CONFIG missionConfigFile >> "Resistance" >> "Civilian" >> "skill"
private _skill = (SKILL_CONFIG) call BIS_fnc_getCfgData;

params ["_unit"];

_unit setSkill _skill;
[_unit, "NoVoice"] remoteExec ["setSpeaker", 0, _unit];
_unit disableAI "TARGET";
_unit disableAI "AUTOTARGET";

_unit addEventHandler ["HandleDamage", RES_fnc_hCivilianDamage];
_unit addEventHandler ["killed", RES_fnc_hCivilianKilled];
