
[] spawn {
	waitUntil {time > 2};
	systemChat "Press 'Shift + F2' to access the TF SnowStromSpawnMenu";
	adminVar = vehicleVarName player;
	if (adminVar == "" or isNil "adminVar") then
	{
		adminVar = format ["AdminID_%1", getPlayerUID player];
		player SetVehicleVarName adminVar;
		player Call Compile Format ["%1=_this; PublicVariable ""%1""", adminVar];
	};
	[[player, (vehicleVarName player)], "TFSC_fnc_setVehicleVarName", false, false] spawn BIS_fnc_MP;
	//null = [80,240,false,40,true,true,false,true] execvm "AL_snowstorm\al_snow.sqf";
	//[80,240,false,40,true,true,false,true] spawn TFSC_fnc_al_snow;
	[] spawn {
		waitUntil {sleep 0.5; !isNull (findDisplay 46)};
		(findDisplay 46) displayAddEventHandler ["KeyDown", "_this call TFSC_fnc_keyPressed"];
	};
	
};
