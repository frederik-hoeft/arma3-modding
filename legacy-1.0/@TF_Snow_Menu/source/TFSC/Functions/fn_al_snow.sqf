// by ALIAS
// SNOW STORM SCRIPT DEMO- For vanilla terrains
// Tutorial: https://www.youtube.com/user/aliascartoons

if (!isServer) exitWith {};

_name_terr = worldName;

start_effect_proces = false;
publicVariable "start_effect_proces";

if (_name_terr == "Altis" or _name_terr == "Stratis" or _name_terr == "Tanoa") then 
{
	terrain_type_vanilla = true;
	publicVariable "terrain_type_vanilla";
} 
else 
{
	terrain_type_vanilla = false;
	publicVariable "terrain_type_vanilla";
};
//hint str _name_terr;

_direction_snowstorm	= _this select 0;
_duration_snowstorm		= _this select 1;
_effect_on_objects		= _this select 2;


ambient_sounds_al =_this select 3;
publicVariable "ambient_sounds_al";

breath_vapors_units = _this select 4;
publicVariable "breath_vapors_units";

snow_burst_server_side	= _this select 5;
publicVariable "snow_burst_server_side";

snow_burst_client_side	= _this select 6;
publicVariable "snow_burst_client_side";

al_fog_snow	= _this select 7;
publicVariable "al_fog_snow";

_hoverUnit	= _this select 8;

al_snow_indoor = _this select 9;
publicVariable "al_snow_indoor";

al_local_fog_snow = _this select 10;
publicVariable "al_local_fog_snow";

ambient_sounds_cough = _this select 11;
publicVariable "ambient_sounds_cough";

ambient_sounds_cracks = _this select 12;
publicVariable "ambient_sounds_cracks";

_fogValue = _this select 13;
_overcastValue = _this select 14;


//null = [] execVM "AL_snowstorm\alias_hunt.sqf";
//null = [] execvm "AL_snowstorm\umblator.sqf";
[] spawn TFSC_fnc_alias_hunt;
[] spawn TFSC_fnc_umblator;
//[TFSC_fnc_alias_hunt,'BIS_fnc_spawn',true,true,false] call BIS_fnc_MP;
//[TFSC_fnc_umblator,'BIS_fnc_spawn',true,true,false] call BIS_fnc_MP;

al_snowstorm_om = true;
publicVariable "al_snowstorm_om";

// - memoreaza parametri actuali
al_lightninglevel 	= lightnings;
al_rainlevel 		= rain;
al_foglevel			= fog;
al_windlevel		= wind;
al_overcastlevel	= overcast;
publicVariable "al_lightninglevel";
publicVariable "al_rainlevel";
publicVariable "al_foglevel";
publicVariable "al_windlevel";
publicVariable "al_overcastlevel";

sleep 0.1;

durationHandle = [_duration_snowstorm] spawn 
{
	x_duration_snowstorm = _this select 0;
	if (x_duration_snowstorm<0) then {al_snowstorm_om = true;publicVariable "al_snowstorm_om";} 
	else {
	sleep x_duration_snowstorm;
	
	al_snowstorm_om = false;
	publicVariable "al_snowstorm_om";
	
	finishRotocol = false;
	publicVariable "finishRotocol";
	};
};

[] spawn 
{
	WaitUntil{!al_snowstorm_om};
	terminate durationHandle;
	// restaureaza parametri vreme
	60 setFog al_foglevel;
	setWind [al_windlevel select 0, al_windlevel select 1, true];
	60 setRain al_rainlevel;
	60 setLightnings al_lightninglevel;
	sleep 60;
	1800 setOvercast al_overcastlevel;
};

_currentOvercast = [(overcast * 100),0] call BIS_fnc_cutDecimals;
if(_currentOvercast != _overcastValue) then 
{
	84500 setOvercast _overcastValue;
	60 setRain 0;
	60 setLightnings 0;
	forceweatherchange;
	cloudhandle = [_duration_snowstorm, _overcastValue] spawn {
		_duration_snowstorm_Used = _this select 0;
		_overcastValueUsed 		 = _this select 1;
		_duration_snowstorm_Used setOvercast _overcastValueUsed;
	};
	[] spawn {
		while{al_snowstorm_om} do {
			60 setRain 0;
			60 setLightnings 0;
		};
		terminate cloudhandle;
	};
};

[] spawn 
{
	if (snow_burst_server_side) then 
	{
		while {al_snowstorm_om} do 
		{
			//["bcg_wind","playSound"] call BIS_fnc_MP;
			["bcg_wind"] remoteExec ["playSound"];
			sleep 42;
		};
	} 
	else 
	{
		while {al_snowstorm_om} do 
		{
			//["bcg_wind_mild","playSound"] call BIS_fnc_MP;
			["bcg_wind_mild"] remoteExec ["playSound"];
			sleep 42;
		};
	};
};

if(ambient_sounds_cough) then 
{
	[] spawn 
	{
		sleep 10;
		while {al_snowstorm_om} do 
		{
			_tuse = ["tuse_1","tuse_2","tuse_3","tuse_4","tuse_5","tuse_6"] call BIS_fnc_selectRandom;
			//[[hunt_alias, _tuse], "say3d", true] call BIS_fnc_MP;
			[hunt_alias,[_tuse,100]] remoteExec ["say3d"];
			// >> you can tweak sleep value if you want to hear playable units coughing more or less often	
			sleep 60+ random ambient_sounds_al;//60+random 180;
		};	
	};
};
// tree cracks
if(ambient_sounds_cracks) then 
{
	[] spawn 
	{
		sleep 20;
		treecrack= "Land_HelipadEmpty_F" createVehicle [0,0,0];
		while {al_snowstorm_om} do 
		{	
			_treesu = ["tree_crack_1","tree_crack_2","tree_crack_3","tree_crack_4","tree_crack_5","tree_crack_6","tree_crack_7","tree_crack_8","tree_crack_9"] call BIS_fnc_selectRandom;
			pos_tree = [hunt_alias,3+random 10, random 360] call BIS_fnc_relPos;
			treecrack setpos [pos_tree select 0,pos_tree select 1,3 + random 20];
			//[[treecrack, _treesu], "say3d", true] call BIS_fnc_MP;
			[treecrack,[_treesu,100]] remoteExec ["say3d"];
			// >> you can tweak sleep value if you want to hear trees cracking more or less often	
			sleep 31+random ambient_sounds_al;
		};
	};
};

[] spawn 
{
	sleep 5;
	if (snow_burst_server_side) then 
	{
		_rotocol= "Land_HelipadEmpty_F" createVehicle [0,0,0];
		_rotocol_1= "Land_HelipadEmpty_F" createVehicle [0,0,0];
		
		while {al_snowstorm_om} do 
		{
			finishRotocol = true;
			publicVariable "finishRotocol";
		
			if (terrain_type_vanilla) then 
			{
				drop_int_rot = 0.001 + random 0.01;
				publicVariable "drop_int_rot";		
				life_part_rot = 1+random 3;
				publicVariable "life_part_rot";
				//fulg_p_drop	= 0.001;	//<--- droprate
				//publicVariable "fulg_p_drop";			
			} 
			else 
			{
				//fulg_p_drop	= 0.0001;	//<--- droprate
				//publicVariable "fulg_p_drop";		
				life_part_rot = 5+random 5;
				publicVariable "life_part_rot";	
				drop_int_rot = 0.001;
				publicVariable "drop_int_rot";			
			};
			
			_fct = [1,-1] call BIS_fnc_selectRandom;
			vitx = 5*_fct;
			publicVariable "vitx";
			vity = 5*_fct;
			publicVariable "vity";		
			
			//hint "agitat";		
			_rafale = ["rafala_1","rafala_2","rafala_6","rafala_7","rafala_9"] call BIS_fnc_selectRandom;
			switch (_rafale) do 
			{
				case "rafala_1":{dist=8};
				case "rafala_2":{dist=4};
				case "rafala_6":{dist=14};
				case "rafala_7":{dist=11};
				case "rafala_9":{dist=27};
			};
			
			[_rafale] remoteExec ["playSound"];
			
			size_rotocol=1+random 9;
			publicVariable "size_rotocol";
			
			_dir = ["x","y"] call BIS_fnc_selectRandom;
			_vect = [0.01,-0.01] call BIS_fnc_selectRandom;
			[[[_dir,dist,_vect],TFSC_fnc_rotocol],'BIS_fnc_spawn',true,true,false] call BIS_fnc_MP;
			
			_dir_1 = ["x","y"] call BIS_fnc_selectRandom;
			_vect_1 = [0.01,-0.01] call BIS_fnc_selectRandom;
			[[[_dir_1,dist,_vect_1],TFSC_fnc_rotocol],'BIS_fnc_spawn',true,true,false] call BIS_fnc_MP;
			
			sleep dist;
			
			vitx = 0;
			publicVariable "vitx";
			vity = 0;
			publicVariable "vity";
			//fulg_p_drop	= 0.001+random 0.01;
			//fulg_p_drop	= 0.006;
			//publicVariable "fulg_p_drop";	
			finishRotocol = false;
			publicVariable "finishRotocol";
			// >> you can tweak sleep value if you want to have gusts more or less often		
			sleep 60+random ambient_sounds_al;
		};
		deleteVehicle _rotocol;
		deleteVehicle _rotocol_1;
	} 
	else 
	{
		if (snow_burst_client_side) then 
		{
			while {al_snowstorm_om} do 
			{
				finishRotocol = true;
				publicVariable "finishRotocol";
			
				if (terrain_type_vanilla) then 
				{
					drop_int_rot = 0.001 + random 0.01;
					publicVariable "drop_int_rot";		
					life_part_rot = 1+random 3;
					publicVariable "life_part_rot";
					//fulg_p_drop	= 0.01;
					//publicVariable "fulg_p_drop";
				} 
				else 
				{
					//fulg_p_drop	= 0.001;
					//publicVariable "fulg_p_drop";		
					life_part_rot = 5+random 5;
					publicVariable "life_part_rot";	
					drop_int_rot = 0.001;
					publicVariable "drop_int_rot";			
				};
				
				_fct = [1,-1] call BIS_fnc_selectRandom;
				vitx = 5*_fct;
				publicVariable "vitx";
				vity = 5*_fct;
				publicVariable "vity";		
				
				//hint "agitat";		
				_rafale = ["rafala_1","rafala_2","rafala_6","rafala_7","rafala_9"] call BIS_fnc_selectRandom;
				switch (_rafale) do 
				{
					case "rafala_1":{dist=8};
					case "rafala_2":{dist=4};
					case "rafala_6":{dist=14};
					case "rafala_7":{dist=11};
					case "rafala_9":{dist=27};
				};
				[_rafale] remoteExec ["playSound"];
				
				size_rotocol=1+random 9;
				publicVariable "size_rotocol";

				//[[[],"AL_snowstorm\rotocol.sqf"],"BIS_fnc_execVM",true,true] spawn BIS_fnc_MP;
				//[[],"AL_snowstorm\rotocol_client.sqf"] remoteExec ["execVM"];
				//[] spawn TFSC_fnc_rotocol_client;
				[TFSC_fnc_rotocol_client,'BIS_fnc_spawn',true,true,false] call BIS_fnc_MP;
				
				sleep dist;
				
				vitx = 0;
				publicVariable "vitx";
				vity = 0;
				publicVariable "vity";
				//fulg_p_drop	= 0.001+random 0.01;
				//fulg_p_drop	= 0.006;
				//publicVariable "fulg_p_drop";	
				finishRotocol = false;
				publicVariable "finishRotocol";
		// >> you can tweak sleep value if you want to have gusts more or less often		
				sleep 60+random ambient_sounds_al;
			};
		} 
		else 
		{
			while {al_snowstorm_om} do 
			{
				finishRotocol = true;
				publicVariable "finishRotocol";
			
				_fct = [1,-1] call BIS_fnc_selectRandom;
				vitx = 5*_fct;
				publicVariable "vitx";
				vity = 5*_fct;
				publicVariable "vity";	
					
				sleep 60+random ambient_sounds_al;
				//hint "schimb";
				//fulg_p_drop	= 0.001;
				//publicVariable "fulg_p_drop";
				
				finishRotocol = false;
				publicVariable "finishRotocol";
				sleep 60+random ambient_sounds_al;
			};
		};
	};
};


if (al_fog_snow) then 
{
	//<-- Optional: change fog density
	60 setFog [/*fogValue _fogValue*/ 0.65,/*fogDecay*/0.01,/*fogBase*/0.5]; 
	//	[] spawn {_ifog=0; while {_ifog <0.5} do {	_ifog=_ifog+0.001; 0 setFog _ifog; sleep 0.01;		};	};
};

// seteaza wind storm functie de directie

raport = 360/_direction_snowstorm;
raport = round (raport * (10 ^ 2)) / (10 ^ 2);
//hint str raport;

if (raport >= 4) then 
{
	fctx = 1; 
	fcty = 1
}
else 
{
	if (raport >= 2) then 
	{
		fctx = 1; 
		fcty = -1
	}
	else 
	{ 
		if (raport >=1.33) then 
		{
			fctx = -1; 
			fcty = -1
		}
		else 
		{
			fctx = -1; 
			fcty = 1
		};
	};
};

if ((raport <= 2) and (raport >= 1.33)) then 
{
	fctx = -1; 
	fcty = -1
};
//hint str fcty;sleep 2;hint str fctx;

_unx = ((_direction_snowstorm - floor(_direction_snowstorm / 90 ) * 90)) * fctx;
//hint str _unx;
//_uny	= 90-_unx;

vx = floor (_unx * 0.6);
vy = (54 - vx)*fcty;

// mareste incremental vantul

inx = 0;
iny = 0;

incr = true;
incrx = false;
incry = false;

while {incr} do 
{
	sleep 0.01;
	if (inx < abs vx) then 
	{
		inx = inx+0.1;
	} 
	else 
	{
		incrx = true
	};
	if (iny < abs vy) then 
	{
		iny = iny+0.1
	} 
	else 
	{
		incry = true
	};
	if (incrx and incry) then 
	{
		incr=false
	};
	winx = floor (inx*fctx);
	winy = floor (iny*fcty);
	setWind [winx / 4, winy / 4, true];
};
	
alias_drop_fog_factor	= 0.01+random 0.1;
publicVariable "alias_drop_fog_factor";
	
//[[[],"AL_snowstorm\alias_snowstorm_effect.sqf"],"BIS_fnc_execVM",true,true] spawn BIS_fnc_MP;
//[] spawn TFSC_fnc_alias_snowstorm_effect;
[TFSC_fnc_alias_snowstorm_effect,'BIS_fnc_spawn',true,true,false] call BIS_fnc_MP;


if (breath_vapors_units) then 
{
	//{[[[_x],"AL_snowstorm\snow_breath.sqf"],"BIS_fnc_execVM",true,true] spawn BIS_fnc_MP;sleep 0.5} forEach allUnits;
	{[[[_x],TFSC_fnc_snow_breath],'BIS_fnc_spawn',true,true,false] call BIS_fnc_MP; sleep 0.5} forEach allUnits;
	//{[[[_x],TFSC_fnc_snow_breath],'BIS_fnc_spawn',true,true,false] call BIS_fnc_MP;sleep 0.5} forEach allUnits;
};

if (_effect_on_objects) then 
{
	while {al_snowstorm_om} do 
	{
		sleep 1;
		
		al_nearobjects = nearestObjects [hunt_alias,[],50];
		ar_obj_eligibl = [];
		if (_hoverUnit) then 
		{
			{
				if ((_x isKindOf "LandVehicle") or (_x isKindOf "Man") or (_x isKindOf "Air") or (_x isKindOf "Wreck")) then 
				{
					ar_obj_eligibl pushBack _x;
				};
			} foreach al_nearobjects;
		}
		else
		{
			{
				if ((_x isKindOf "LandVehicle") or (_x isKindOf "Air") or (_x isKindOf "Wreck")) then 
				{
					ar_obj_eligibl pushBack _x;
				};
			} foreach al_nearobjects;
		};
		
		sleep 1;
		
		// alege obiect
		_blowobj = ar_obj_eligibl call BIS_fnc_selectRandom;

		//durata_rafala = 1+random 5;	sleep 30+random 120;
		sleep 1;

		[] spawn 
		{
			//fulg_p_drop			= 0.001;//+random 0.01;
			//publicVariable "fulg_p_drop";
			alias_drop_fog_factor	= 0.01+random 0.1;
			publicVariable "alias_drop_fog_factor";
			
			_fct = [1,-1] call BIS_fnc_selectRandom;
			vitx = floor(random 10) * _fct;
			vity = floor(random 10) * _fct;
			publicVariable "vitx";
			publicVariable "vity";
		};
		
		if (!isNull _blowobj) then 
		{
			_xblow = 0.1 + random 5;
			_yblow = 0.1 + random 5;
	
			// creste viteza incremental
			_xx = 0;
			_yy = 0;
			
			while {(_xx< _xblow) or (_yy< _yblow)} do 
			{
				_blowobj setvelocity [_xx*fctx,_yy*fcty,random 0.1];
				_xx = _xx + 0.01;
				_yy = _yy + 0.01;
				sleep 0.001;
			};
		};
	};
};