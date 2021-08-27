#define SKILL_CONFIG missionConfigFile >> "Resistance" >> "Civilian" >> "skill"
private _skill = (SKILL_CONFIG) call BIS_fnc_getCfgData;

params ["_unit"];

_unit setSkill _skill;
[_unit, "NoVoice"] remoteExec ["setSpeaker", 0, _unit];
_unit disableAI "TARGET";
_unit disableAI "AUTOTARGET";

// _unit addEventHandler ["HandleDamage", Civ_fnc_hCivilianDamage];
// _unit addEventHandler ["killed", Civ_fnc_hCivilianKilled}];
