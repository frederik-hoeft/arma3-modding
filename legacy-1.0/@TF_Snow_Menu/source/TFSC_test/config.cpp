class CfgPatches 
{
	class TF_Snow_Console
	{
		units[] = {};
		weapons[] = {};
		worlds[] = {};
		requiredAddons[] = {};
		requiredVersion = 0.1;
		author[] = {"Th3_Fr3d"};
		authorUrl = "http://steamcommunity.com/id/th3_fr3d/";
	};
	class TF_Snow_Module
	{
		units[]={"TF_Snow_Module"};
		requiredVersion=0.1;
		requiredAddons[]={"A3_Modules_F"};
		version="1";
	};
};

class CfgFactionClasses
{
	class Effects;
	class TF_Snow_Module: Effects
	{
		displayName="Snow Storm Module";
	};
};

class CfgVehicles
{
	class Logic;
	class Module_F: Logic
	{
		class ArgumentsBaseUnits
		{
			class Units;
		};
		class ModuleDescription
		{
			class AnyPerson;
		};
	};
	class TF_Snow_Module: Module_F
	{
		displayName 		= "Snow Storm Module";
		scope				= 2;
		icon				= "TFSC\TFSSM_logo.paa";
		category			= "Effects";
		function			= "TFSC_fnc_snowStormModule";
		functionPriority	= 1;
		isGlobal			= 1;
		isTriggerActivated	= 1;
		isDisposable		= 0;
		curatorInfoType 	= "RscDisplayAttributeModuleSnowStorm";
		class Arguments: ArgumentsBaseUnits
		{
			class Units: Units {};
			class Int_Snow_Intensity
			{
				displayName 	= "Snow intensity";
				description 	= "(INTEGER; valid range 1 to 100) higher value results in more snowflakes but less frames. Values below 25 are recommended.";
				typeName 		= "NUMBER";
				defaultValue 	= "25";
			}
			class Int_Snow_Wind_Dir
			{
				displayName		= "Snow storm direction";
				description		= "INTEGER; from 0 to 360, direction towards the wind blows expressed in compass degrees.";
				typeName		= "NUMBER";
				defaultValue	= "360";
			};
			class Int_Snow_Duration
			{
				displayName		= "Snow storm duration";
				description		= "INTEGER; duration how long the storm will last expressed in minutes.";
				typeName		= "NUMBER";
				defaultValue	= "10";
			};
			class Bool_Effect_On_Objects
			{
				displayName		= "Effect on Objects";
				description		= "BOOLEAN; if is true occasionally a random object will be thrown in the air. Set 'Effect on Units' to false to prevent Units from being thrown in the air aswell :D";
				typeName		= "BOOL";
				defaultValue	= "false";
			};
			class Int_Ambient_Sound_Delay
			{
				displayName		= "Ambient sound delay";
				description		= "INTEGER; Maximum delay in minutes between random ambient sounds. minimum delay is set to one minute. Also determines interval at which snow gusts are generated.";
				typeName		= "NUMBER";
				defaultValue	= "1";
			};
			class Bool_Breath
			{
				displayName		= "Breath Vapors";
				description		= "BOOLEAN; Will enable breath vapors for all units, however if you have many units in your mission you should disable this to deminish the impact on frames.";
				typeName		= "BOOL";
				defaultValue	= "true";
			};
			class Bool_Snow_Burst_Server
			{
				displayName		= "Execute gusts on server";
				description		= "BOOLEAN; Enable for full-on blizzard effects. NOTE: don't execute gusts on both server and client.";
				typeName		= "BOOL";
				defaultValue	= "true";
			}
			class Bool_Snow_Burst_Client
			{
				displayName		= "Execute gusts on client";
				description		= "BOOLEAN; Enable for full-on blizzard effects. NOTE: don't execute gusts on both server and client.";
				typeName		= "BOOL";
				defaultValue	= "false";
			}
			class Bool_Change_Fog
			{
				displayName		= "Execute gusts on client";
				description		= "BOOLEAN; If true fog will be managed by script, otherwise the values will remain unchanged.";
				typeName		= "BOOL";
				defaultValue	= "true";
			}
			class Bool_Hover_Unit
			{
				displayName		= "Effect on Units";
				description		= "BOOLEAN; If true and Effect on Objects is true as well units will also be thrown in the air (Recommended to set to false :D).";
				typeName		= "BOOL";
				defaultValue	= "false";
			}
			class Bool_No_Snow_Indoor
			{
				displayName		= "Forbid snow indoors";
				description		= "BOOLEAN; If true snow will no longer appear inside of buildings when the player is inside als well. You may want to disable this option in bigger scenarios to save on performace.";
				typeName		= "BOOL";
				defaultValue	= "true";
			}
			class Bool_Local_Fog
			{
				displayName		= "Local fog";
				description		= "BOOLEAN; If true particles will be used to create sort of waves of fog and snow. May reduce performance in bigger scenarios.";
				typeName		= "BOOL";
				defaultValue	= "true";
			}
			class Bool_Ambient_Cough
			{
				displayName		= "Ambient coughing & shivering";
				description		= "BOOLEAN; If true units will cough an shiver every once in a while. Delay is set by 'Ambient sound delay'.";
				typeName		= "BOOL";
				defaultValue	= "true";
			}
			class Int_Fog_Value
			{
				displayName		= "Fog intensity";
				description		= "INTEGER; valid range 1 to 100; (Only if fog is allowed to be managed by mod -> check settings above) higher fog percentage will result in more authentic snow storm effect by worse visibility conditions.";
				typeName		= "NUMBER";
				defaultValue	= "65";
			}
			class Int_Overcast_Value
			{
				displayName		= "Fog intensity";
				description		= "INTEGER; valid range 1 to 100; higher percentage results in denser clouds. leave it as is if your fine with current weather conditions.";
				typeName		= "NUMBER";
				defaultValue	= "65";
			}
		};
		class ModuleDescription: ModuleDescription
		{
			description = "Changes overall weather to snow storm.";
			sync[] = {"EmptyDetector"};
		};
	};
};

#include "Dialogs\defines.hpp"
#include "Dialogs\snow.hpp"

class CfgFunctions
{
	class TFSC
	{
		class Functions
		{
			file = "TFSC\Functions";
			
			class Init {postInit = 1;};
			
			class snowStormModule {};
			class setVehicleVarName {};
			class storm_init {};
			class adminCheck {};
			class keyPressed {};
			class alias_hunt {};
			class al_snow {};
			class alias_snowstorm_effect {};
			class rotocol_client {};
			class umblator {};
			class snow_breath {};
			class rotocol {};
			class menuOnload {};
			class setSliderValue {};
			class terminateSnow {};
		};
	};
};



class CfgSounds
{
	class bcg_wind
	{
		name = "bcg_wind";
		sound[] = {"TFSC\sound\bcg_wind.ogg", 0.3, 1};
		titles[] = {1, ""};
	};
	class bcg_wind_mild
	{
		name = "bcg_wind_mild";
		sound[] = {"TFSC\sound\bcg_wind_mild.ogg", 0.05, 1};
		titles[] = {1, ""};
	};		
	class rafala_1
	{
		name = "rafala_1";
		sound[] = {"TFSC\sound\rafala_1.ogg", db+10, 1};
		titles[] = {1, ""};
	};	
	class rafala_2
	{
		name = "rafala_2";
		sound[] = {"TFSC\sound\rafala_2.ogg", db+5, 1};
		titles[] = {1, ""};
	};	
	class rafala_6
	{
		name = "rafala_6";
		sound[] = {"TFSC\sound\rafala_6.ogg", db+15, 1};
		titles[] = {1, ""};
	};	
	class rafala_7
	{
		name = "rafala_7";
		sound[] = {"TFSC\sound\rafala_7.ogg", db+10, 1};
		titles[] = {1, ""};
	};	
	class rafala_8
	{
		name = "rafala_8";
		sound[] = {"TFSC\sound\rafala_8.ogg", db+15, 1};
		titles[] = {1, ""};
	};	
	class rafala_9
	{
		name = "rafala_9";
		sound[] = {"TFSC\sound\rafala_9.ogg", db+10, 1};
		titles[] = {1, ""};
	};
	class tree_crack_1
	{
		name = "tree_crack_1";
		sound[] = {"TFSC\sound\tree_crack_1.ogg", db+5, 1};
		titles[] = {1, ""};
	};
	class tree_crack_2
	{
		name = "tree_crack_2";
		sound[] = {"TFSC\sound\tree_crack_2.ogg", db+5, 1};
		titles[] = {1, ""};
	};
	class tree_crack_3
	{
		name = "tree_crack_3";
		sound[] = {"TFSC\sound\tree_crack_3.ogg", db+5, 1};
		titles[] = {1, ""};
	};	
	class tree_crack_4
	{
		name = "tree_crack_4";
		sound[] = {"TFSC\sound\tree_crack_4.ogg", db+5, 1};
		titles[] = {1, ""};
	};
	class tree_crack_5
	{
		name = "tree_crack_5";
		sound[] = {"TFSC\sound\tree_crack_5.ogg", db+5, 1};
		titles[] = {1, ""};
	};
	class tree_crack_6
	{
		name = "tree_crack_6";
		sound[] = {"TFSC\sound\tree_crack_6.ogg", db+5, 1};
		titles[] = {1, ""};
	};	
	class tree_crack_7
	{
		name = "tree_crack_7";
		sound[] = {"TFSC\sound\tree_crack_7.ogg", db+5, 1};
		titles[] = {1, ""};
	};	
	class tree_crack_8
	{
		name = "tree_crack_8";
		sound[] = {"TFSC\sound\tree_crack_8.ogg", db+5, 1};
		titles[] = {1, ""};
	};	
	class tree_crack_9
	{
		name = "tree_crack_9";
		sound[] = {"TFSC\sound\tree_crack_9.ogg", db+5, 1};
		titles[] = {1, ""};
	};
	class lup_01
	{
		name = "lup_01";
		sound[] = {"TFSC\sound\lup_01.ogg", 1, 1};
		titles[] = {};
	};
	class lup_02
	{
		name = "lup_02";
		sound[] = {"TFSC\sound\lup_02.ogg", 1, 1};
		titles[] = {};
	};
	class lup_03
	{
		name = "lup_03";
		sound[] = {"TFSC\sound\lup_03.ogg", 1, 1};
		titles[] = {};
	};
	class tremurat_1
	{
		name = "tremurat_1";
		sound[] = {"TFSC\sound\tremurat_1.ogg", 1, 1};
		titles[] = {1, ""};
	};
	class tremurat_2
	{
		name = "tremurat_2";
		sound[] = {"TFSC\sound\tremurat_2.ogg", 1, 1};
		titles[] = {1, ""};
	};
	class tremurat_3
	{
		name = "tremurat_3";
		sound[] = {"TFSC\sound\tremurat_3.ogg", 1, 1};
		titles[] = {1, ""};
	};
	class tremurat_4
	{
		name = "tremurat_4";
		sound[] = {"TFSC\sound\tremurat_4.ogg", 1, 1};
		titles[] = {1, ""};
	};	
	class NoSound 
	{
		name = "NoSound";
		sound[] = {"", 0, 1};
		titles[] = {0, ""};
	};	
	class tuse_1
	{
		name = "tuse_1";
		sound[] = {"TFSC\sound\tuse_1.ogg", 1, 1};
		titles[] = {1, ""};
	};
	class tuse_2
	{
		name = "tuse_2";
		sound[] = {"TFSC\sound\tuse_2.ogg", 1, 1};
		titles[] = {1, ""};
	};
	class tuse_3
	{
		name = "tuse_3";
		sound[] = {"TFSC\sound\tuse_3.ogg", 1, 1};
		titles[] = {1, ""};
	};
	class tuse_4
	{
		name = "tuse_4";
		sound[] = {"TFSC\sound\tuse_4.ogg", 1, 1};
		titles[] = {1, ""};
	};
	class tuse_5
	{
		name = "tuse_5";
		sound[] = {"TFSC\sound\tuse_5.ogg", 1, 1};
		titles[] = {1, ""};
	};
	class tuse_6
	{
		name = "tuse_6";
		sound[] = {"TFSC\sound\tuse_6.ogg", 1, 1};
		titles[] = {1, ""};
	};	
};