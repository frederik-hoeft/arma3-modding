// Argument 0 is module logic
_logic = [_this,0,objNull,[objNull]] call BIS_fnc_param;
// Argument 1 is list of affected units (affected by value selected in the 'class Units' argument))
_units = [_this,1,[],[[]]] call BIS_fnc_param;
// True when the module was activated, false when it's deactivated (i.e., synced triggers are no longer active)
_activated = [_this,2,true,[true]] call BIS_fnc_param;
// Module specific behavior. Function can extract arguments from logic and use them.
if (_activated) then {


_IntSnowIntensity 		= _logic getVariable ["Int_Snow_Intensity", 25];//percent
_IntSnowWindDir 		= _logic getVariable ["Int_Snow_Wind_Dir", 360];//degree
_IntSnowDuration		= _logic getVariable ["Int_Snow_Duration", 10];//Minutes
BoolEffectOnObjects		= _logic getVariable ["Bool_Effect_On_Objects", false];//boolean
_IntAmbientSoundDelay	= _logic getVariable ["Int_Ambient_Sound_Delay", 1];//Minutes
BoolBreath				= _logic getVariable ["Bool_Breath", true];//boolean
BoolSnowBurstServer		= _logic getVariable ["Bool_Snow_Burst_Server", true];//boolean
BoolSnowBurstClient		= _logic getVariable ["Bool_Snow_Burst_Client", false];//boolean
BoolChangeFog			= _logic getVariable ["Bool_Change_Fog", true];//boolean
BoolHoverUnit			= _logic getVariable ["Bool_Hover_Unit", false];//boolean
BoolNoSnowIndoor		= _logic getVariable ["Bool_No_Snow_Indoor", true];//boolean
BoolLocalFog			= _logic getVariable ["Bool_Local_Fog", true];//boolean
BoolAmbientCough		= _logic getVariable ["Bool_Ambient_Cough", true];//boolean
_IntFogValue			= _logic getVariable ["Int_Fog_Value", 65];//percent
_IntOvercastValue		= _logic getVariable ["Int_Overcast_Value", Overcast];//percent

fulg_p_drop = 1 / (_IntSnowIntensity * 50);
publicVariable "fulg_p_drop";

_IntSnowDuration = _IntSnowDuration * 60;
_IntAmbientSoundDelay = _IntAmbientSoundDelay * 60;
_IntFogValue = _IntFogValue / 100;

//null = [_direction_storm,_duration_storm,_effect_on_objects,_ambient_sounds_al,_breath_vapors] execvm "\AL_snowstorm\al_snow.sqf";
[
	[
		[
			_IntSnowWindDir,
			_IntSnowDuration,
			BoolEffectOnObjects,
			_IntAmbientSoundDelay,
			BoolBreath,
			BoolSnowBurstServer,
			BoolSnowBurstClient,
			BoolChangeFog,
			BoolHoverUnit,
			BoolNoSnowIndoor,
			BoolLocalFog,
			BoolAmbientCough,
			BoolAmbientCrack,
			_IntFogValue,
			_IntOvercastValue
		],TFSC_fnc_al_snow
	],'BIS_fnc_spawn',true,true,false
] call BIS_fnc_MP;

}; // if activated
// Fin
true;
