#define SLEEP_TIME 5

call CIV_fnc_deleteAwayCivilians;
call CIV_fnc_addRandomCivilians;

sleep SLEEP_TIME;

[] spawn CIV_fnc_ambientCivilians;
