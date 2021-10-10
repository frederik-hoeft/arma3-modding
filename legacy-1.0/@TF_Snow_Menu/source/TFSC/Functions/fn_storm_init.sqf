// TODO: uhhhhhm.... Yeah this suxx..
_BoolArray = [false,true];

_EffectOnObjects_I = lbCurSel 2100;
_Breath_I = lbCurSel 2101;
_SnowBurstServer_I = lbCurSel 2102;
_ChangeFog_I = lbCurSel 2103;
_NoSnowIndoor_I = lbCurSel 2104;
_BoolAmbientCough_I = lbCurSel 2105;
_LocalFog_I = lbCurSel 2106;
_BoolAmbientCrack_I = lbCurSel 2107;

_IntSnowWindDir = sliderposition 1900;
_IntSnowDuration = sliderposition 1901;
_IntAmbientSoundDelay = sliderposition 1902;
_fulg_p_drop_I = sliderposition 1903;
_IntFogValue = sliderPosition 1904;
//_IntFogValue = 0.65;
_IntOvercastValue = sliderPosition 1905;
//_IntOvercastValue = 0.8;

_fulg_p_drop_I = [_fulg_p_drop_I,0] call BIS_fnc_cutDecimals;
fulg_p_drop = 1/_fulg_p_drop_I;
publicVariable "fulg_p_drop";

BoolBreath = _BoolArray select _Breath_I;
BoolChangeFog = _BoolArray select _ChangeFog_I;
BoolNoSnowIndoor = _BoolArray select _NoSnowIndoor_I;
//BoolNoSnowIndoor = true;
BoolLocalFog = _BoolArray select _LocalFog_I;
//BoolLocalFog = true;
BoolAmbientCough = _BoolArray select _BoolAmbientCough_I;
//BoolAmbientCough = true;
BoolAmbientCrack = _BoolArray select _BoolAmbientCrack_I;
//BoolAmbientCrack = true;

if (_SnowBurstServer_I == 2) then
{
	BoolSnowBurstServer = false;
	BoolSnowBurstClient = false;
}
else
{
	// TODO: is there really no ternary operator in sqf?
	if (_SnowBurstServer_I == 1) then 
	{
		BoolSnowBurstServer = true;
		BoolSnowBurstClient = false;
	}
	else
	{
		BoolSnowBurstServer = false;
		BoolSnowBurstClient = true;
	};
};

if (_EffectOnObjects_I == 0) then
{
	BoolEffectOnObjects = false;
	BoolHoverUnit = false;
}
else
{
	if (_EffectOnObjects_I == 1) then 
	{
		BoolEffectOnObjects = true;
		BoolHoverUnit = false;
	}
	else
	{
		BoolEffectOnObjects = true;
		BoolHoverUnit = true;
	};
};

_IntSnowWindDir = [_IntSnowWindDir,0] call BIS_fnc_cutDecimals;
_IntSnowDuration = [_IntSnowDuration,0] call BIS_fnc_cutDecimals;
_IntAmbientSoundDelay = [_IntAmbientSoundDelay,0] call BIS_fnc_cutDecimals;


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
		], TFSC_fnc_al_snow
	], 'BIS_fnc_spawn', true, true, false
] call BIS_fnc_MP;