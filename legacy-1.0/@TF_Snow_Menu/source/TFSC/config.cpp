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