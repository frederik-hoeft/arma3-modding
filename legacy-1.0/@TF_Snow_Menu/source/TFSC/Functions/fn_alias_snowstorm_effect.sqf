// by ALIAS
// Tutorial: https://www.youtube.com/user/aliascartoons

if (!hasInterface) exitWith {};

//_name_terr = worldName;
if (al_snow_indoor) then 
{
	circle_snow =0;
	// function by Killzone Kid and adapted by ALIAS
	KK_fnc_inHouse = 
	{
		_house = lineIntersectsSurfaces [
			getPosWorld _this, 
			getPosWorld _this vectorAdd [0, 0, 50], 
			_this, objNull, true, 1, "GEOM", "NONE"
		];
		if (((_house select 0) select 3) isKindOf "house") exitWith 
		{
			in_da_house = true;
			missionNamespace setVariable ["under_cover_snow", true, false];
			//player sideChat (format ["%1",in_da_house]);
			cladire = ((_house select 0) select 3);
			//hint str (getposatl cladire);
			casa = typeOf ((_house select 0) select 3);
			raza_snow = sizeof casa;
			//hint str raza_snow;
		};
		in_da_house = false;
		missionNamespace setVariable ["under_cover_snow", false, false];
		//player sideChat (format ["%1",in_da_house]);
	};
	
	[] spawn 
	{
		while {true} do
		{
			while {al_snowstorm_om} do 
			{
				player call KK_fnc_inHouse;
				sleep 0.2;
			};
			waitUntil {al_snowstorm_om};
		};
	}
};

sleep 5;

start_effect_proces = true;
publicVariable "start_effect_proces";

enableCamShake true;

[] spawn 
{
	while {al_snowstorm_om} do 
	{
		addCamShake [0.3,14,19];
		_tremurici = ["tremurat_1","tremurat_2","NoSound","tremurat_3","tremurat_4","rafala_8"] call BIS_fnc_selectRandom;
		playSound _tremurici;
		// >>>>  tweak the sleep value to increase or decrease time between player's shivering
		sleep 60+random ambient_sounds_al;
	};
};

while {true} do 
{
	private ["_alias_local_fog"];
	while {al_snowstorm_om} do 
	{
		effect_screen = ppEffectCreate ["FilmGrain", 2000]; 
		effect_screen ppEffectEnable true;
		effect_screen ppEffectAdjust [0.1,0.1,0.5,0.1,0.1,true];
		effect_screen ppEffectCommit 0;

		if (al_snow_indoor) then 
		{
			if (in_da_house) then 
			{
				if (al_local_fog_snow) then 
				{
					_alias_local_fog = "#particlesource" createVehicleLocal (getpos player);
					if !(isNull objectParent player) then 
					{
						_alias_local_fog attachto [vehicle player];
					} 
					else 
					{
						_alias_local_fog attachto [player];
					};
					_alias_local_fog setParticleCircle [raza_snow, [3, 3, 0]];
					_alias_local_fog setParticleRandom [0, [0, 0, 0], [0, 0, 0],0,0, [0, 0, 0,0], 0, 0];
					_alias_local_fog setParticleParams [["\A3\data_f\cl_basic", 1, 0, 1], "", "Billboard", 1, 12, [0, 0, 0], [-1, -1, 0], 110, 10.15, 7.9, 0.01, [10, 10, 20], [[1, 1, 1, 0.01], [1, 1, 1, 0.05+random 0.05], [1, 1, 1, 0]], [0.08], 1, 0, "", "", player];	
					_alias_local_fog setDropInterval alias_drop_fog_factor;
				};
				
				//_poz_obj_snow = "Sign_Sphere200cm_F" createVehiclelocal [0,0,0];	
				//_poz_obj_snow = "land_helipadempty_f" createVehiclelocal [0,0,0];	
				//_poz_1 = [cladire, 10+raza_snow/2, 0] call BIS_fnc_relPos;
				//_poz_obj_snow_1 = "land_helipadempty_f" createVehiclelocal _poz_1;
				//_poz_obj_snow_1 setPosATL [_poz_1 select 0, _poz_1 select 1, (_poz_1 select 2) + raza_snow/2];
				_fulg_nea_1  = "#particlesource" createVehicle getPosATL cladire;
				//_fulg_nea_1 attachto [_poz_obj_snow_1,[0,0,15]];
				_fulg_nea_1 setDropInterval 0.001;
				_fulg_nea_1 setParticleRandom [6, [6, 6, 6], [0, 0, -1], 0, 0.1, [0, 0, 0, 0.1], 1, 1];
				_fulg_nea_1 setParticleCircle [raza_snow+3, [0, 0, 0]];
				_fulg_nea_1 setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal.p3d", 16, 12, 8], "", "Billboard", 1, 8, [0, 0, 0], [0,0,23], 3, 21, 0.1, 0.05, [0,0,0,0.3], [[1, 1, 1, 0],[1, 1, 1, 0],[1, 1, 1, 0.5],[1, 1, 1, 1]], [0.08], 1, 0, "", "", cladire];
				
				waitUntil {!in_da_house or !al_snowstorm_om};

				deletevehicle _fulg_nea_1;
				if (al_local_fog_snow) then 
				{
					deletevehicle _alias_local_fog
				};
			} 
			else 
			{
				if (al_local_fog_snow) then 
				{
					_alias_local_fog = "#particlesource" createVehicleLocal (getpos vehicle player);
					if !(isNull objectParent player) then 
					{
						_alias_local_fog attachto [vehicle player];
					} 
					else 
					{
						_alias_local_fog attachto [player];
					;
					_alias_local_fog setParticleCircle [30, [3, 3, 0]];
					_alias_local_fog setParticleRandom [10, [5, 5, 0], [1, 1, 0], 1, 1, [0, 0, 0, 0.1], 0, 0];
					_alias_local_fog setParticleParams [["\A3\data_f\cl_basic", 1, 0, 1], "", "Billboard", 1, 12, [0, 0, 0], [-1, -1, 0], 110, 10.15, 7.9, 0.01, [10, 10, 20], [[1, 1, 1, 0.01], [1, 1, 1, 0.05+random 0.05], [1, 1, 1, 0]], [0.08], 1, 0, "", "", vehicle player];	
					_alias_local_fog setDropInterval alias_drop_fog_factor;	
				};
				
				_fulg_nea  = "#particlesource" createVehicle [getposasl hunt_alias select 0,getposasl hunt_alias select 1,(getposasl hunt_alias select 2)+10];
				if !(isNull objectParent player) then 
				{
					_fulg_nea attachto [vehicle player,[0,0,10]];
					_fulg_nea setDropInterval fulg_p_drop;
					_fulg_nea setParticleRandom [5, [25, 25, 5], [vitx, vity, -1], 0, 0.1, [0, 0, 0, 0.1], 1, 1];
					_fulg_nea setParticleCircle [0, [vitx, vity, -1]];
					_fulg_nea setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal.p3d", 16, 12, 8], "", "Billboard", 1, 6, [0, 0, 6], [vity,vitx, 0], 3, 1.6, 1, 0.1, [0.09], [[1, 1, 1, 1]], [0.08], 1, 0, "", "", vehicle player];
					
					waitUntil {in_da_house or !al_snowstorm_om or (isNull objectParent player)};
				} 
				else 
				{
					_fulg_nea attachto [player,[0,0,10]];
					_fulg_nea setDropInterval fulg_p_drop;
					_fulg_nea setParticleRandom [5, [25, 25, 5], [vitx, vity, -1], 0, 0.1, [0, 0, 0, 0.1], 1, 1];
					_fulg_nea setParticleCircle [0, [vitx, vity, -1]];
					_fulg_nea setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal.p3d", 16, 12, 8], "", "Billboard", 1, 6, [0, 0, 6], [vity,vitx, 0], 3, 1.6, 1, 0.1, [0.09], [[1, 1, 1, 1]], [0.08], 1, 0, "", "", vehicle player];		
					waitUntil {in_da_house or !al_snowstorm_om or !(isNull objectParent player)};
				};		
				
				deletevehicle _fulg_nea;
				if (al_local_fog_snow) then 
				{
					deletevehicle _alias_local_fog
				};
			};
		} 
		else 
		{
			while {finishRotocol} do 
			{
				if (al_local_fog_snow) then 
				{
					_alias_local_fog = "#particlesource" createVehicleLocal (getpos vehicle player);
					if !(isNull objectParent player) then 
					{
						_alias_local_fog attachto [vehicle player];
					} 
					else 
					{
						_alias_local_fog attachto [player];
					};
					_alias_local_fog setParticleCircle [25, [3, 3, 0]];
					_alias_local_fog setParticleRandom [10, [5, 5, 0], [1, 1, 0], 1, 1, [0, 0, 0, 0.1], 0, 0];
					_alias_local_fog setParticleParams [["\A3\data_f\cl_basic", 1, 0, 1], "", "Billboard", 1, 12, [0, 0, 0], [-1, -1, 0], 110, 10.15, 7.9, 0.01, [10, 10, 20], [[1, 1, 1, 0.01], [1, 1, 1, 0.05+random 0.05], [1, 1, 1, 0]], [0.08], 1, 0, "", "", vehicle player];	
					_alias_local_fog setDropInterval alias_drop_fog_factor;	
				};	
				_fulg_nea  = "#particlesource" createVehicle [getposasl player select 0,getposasl player select 1,(getposasl player select 2)+10];
				if !(isNull objectParent player) then 
				{
					_fulg_nea attachto [vehicle player,[0,0,10]];
					_fulg_nea setDropInterval fulg_p_drop;
					_fulg_nea setParticleRandom [5, [25, 25, 5], [vitx, vity, -1], 0, 0.1, [0, 0, 0, 0.1], 1, 1];
					_fulg_nea setParticleCircle [0, [vitx, vity, -1]];
					_fulg_nea setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal.p3d", 16, 12, 8], "", "Billboard", 1, 6, [0, 0, 6], [vity,vitx, 0], 3, 1.6, 1, 0.1, [0.09], [[1, 1, 1, 1]], [0.08], 1, 0, "", "", vehicle player];
					waitUntil {isNull objectParent player};
				} 
				else 
				{
					_fulg_nea attachto [player,[0,0,10]];
					_fulg_nea setDropInterval fulg_p_drop;
					_fulg_nea setParticleRandom [5, [25, 25, 5], [vitx, vity, -1], 0, 0.1, [0, 0, 0, 0.1], 1, 1];
					_fulg_nea setParticleCircle [0, [vitx, vity, -1]];
					_fulg_nea setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal.p3d", 16, 12, 8], "", "Billboard", 1, 6, [0, 0, 6], [vity,vitx, 0], 3, 1.6, 1, 0.1, [0.09], [[1, 1, 1, 1]], [0.08], 1, 0, "", "", vehicle player];	
					waitUntil {!(isNull objectParent player)};
				};	
				deletevehicle _fulg_nea;
				if (al_local_fog_snow) then 
				{
					deletevehicle _alias_local_fog
				};			
			};
			while {!finishRotocol} do 
			{
				if (al_local_fog_snow) then 
				{
					_alias_local_fog = "#particlesource" createVehicleLocal (getpos vehicle player);
					if !(isNull objectParent player) then 
					{
						_alias_local_fog attachto [vehicle player];
					} 
					else 
					{
						_alias_local_fog attachto [player];
					};
					_alias_local_fog setParticleCircle [25, [3, 3, 0]];
					_alias_local_fog setParticleRandom [10, [5, 5, 0], [1, 1, 0], 1, 1, [0, 0, 0, 0.1], 0, 0];
					_alias_local_fog setParticleParams [["\A3\data_f\cl_basic", 1, 0, 1], "", "Billboard", 1, 12, [0, 0, 0], [-1, -1, 0], 110, 10.15, 7.9, 0.01, [10, 10, 20], [[1, 1, 1, 0.01], [1, 1, 1, 0.05+random 0.05], [1, 1, 1, 0]], [0.08], 1, 0, "", "", vehicle player];	
					_alias_local_fog setDropInterval alias_drop_fog_factor;	
				};	
				_fulg_nea  = "#particlesource" createVehicle [getposasl player select 0,getposasl player select 1,(getposasl player select 2)+10];
				if !(isNull objectParent player) then 
				{
					_fulg_nea attachto [vehicle player,[0,0,10]];
					_fulg_nea setDropInterval fulg_p_drop;
					_fulg_nea setParticleRandom [5, [25, 25, 5], [vitx, vity, -1], 0, 0.1, [0, 0, 0, 0.1], 1, 1];
					_fulg_nea setParticleCircle [0, [vitx, vity, -1]];
					_fulg_nea setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal.p3d", 16, 12, 8], "", "Billboard", 1, 6, [0, 0, 6], [vity,vitx, 0], 3, 1.6, 1, 0.1, [0.09], [[1, 1, 1, 1]], [0.08], 1, 0, "", "", vehicle player];
					waitUntil {isNull objectParent player};
				} 
				else 
				{
					_fulg_nea attachto [player,[0,0,10]];
					_fulg_nea setDropInterval fulg_p_drop;
					_fulg_nea setParticleRandom [5, [25, 25, 5], [vitx, vity, -1], 0, 0.1, [0, 0, 0, 0.1], 1, 1];
					_fulg_nea setParticleCircle [0, [vitx, vity, -1]];
					_fulg_nea setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal.p3d", 16, 12, 8], "", "Billboard", 1, 6, [0, 0, 6], [vity,vitx, 0], 3, 1.6, 1, 0.1, [0.09], [[1, 1, 1, 1]], [0.08], 1, 0, "", "", vehicle player];	
					waitUntil {!(isNull objectParent player)};
				};	
				deletevehicle _fulg_nea;
				if (al_local_fog_snow) then 
				{
					deletevehicle _alias_local_fog
				};			
			};
		};
	};
	effect_screen ppEffectEnable false;
	ppEffectDestroy effect_screen;
	enableCamShake false;
	waitUntil {al_snowstorm_om};
};