// by ALIAS
// nul = [] execVM "AL_snowstorm\alias_hunt.sqf";

if (!isServer) exitWith {};

// TODO: shouldn't this run on a different thread? 
// Does it do so? 
while {true} do 
{
	_allunits = [];
	{
		if (alive _x) then
		{
			_allunits pushBack _x;
		};
		// TODO: also I don't like this if statement inside the loop. 
		// Can't we do function pointers in Arma?
	} foreach (if (isMultiplayer) then {playableUnits} else {switchableUnits});
	hunt_alias = _allunits call BIS_fnc_selectRandom;
	publicVariable "hunt_alias";
	sleep 60;
};