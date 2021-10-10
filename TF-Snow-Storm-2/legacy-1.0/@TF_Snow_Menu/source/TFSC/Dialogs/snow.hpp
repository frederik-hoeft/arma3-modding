class menu{
	idd = 1000;
	movingEnable = 1;
	onLoad = "[] spawn TFSC_fnc_menuOnload;";
	class Controls
	{
		class c_objects
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = 2100; // Control identification (without it, the control won't be displayed)
			type = CT_COMBO; // Type is 4
			style = ST_LEFT + LB_TEXTURES; // Style
			default = 0; // Control selected by default (only one within a display can be used)
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

			x = 0.422656 * safezoneW + safezoneX;
			y = 0.313 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;

			colorBackground[] = {0,0,0,1}; // Fill color
			colorSelectBackground[] = {1,1,1,1}; // Selected item fill color

			sizeEx = 0.02/ (getResolution select 5);
			font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
			shadow = 0; // Shadow (0 - none, 1 - N/A, 2 - black outline)
			colorText[] = {1,1,1,1}; // Text and frame color
			colorDisabled[] = {1,1,1,0.5}; // Disabled text color
			colorSelect[] = {0,0,0,1}; // Text selection color

			pictureColor[] = {1,0.5,0,1}; // Picture color
			pictureColorSelect[] = {1,1,1,1}; // Selected picture color
			pictureColorDisabled[] = {1,1,1,0.5}; // Disabled picture color

			tooltip = ""; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color

			arrowEmpty = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_ca.paa"; // Expand arrow
			arrowFull = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_active_ca.paa"; // Collapse arrow

			wholeHeight = 5 * GUI_GRID_CENTER_H; // Maximum height of expanded box (including the control height)
			maxHistoryDelay = 1; // Time since last keyboard type search to reset it

			soundExpand[] = {"\A3\ui_f\data\sound\RscCombo\soundExpand",0.1,1}; // Sound played when the list is expanded
			soundCollapse[] = {"\A3\ui_f\data\sound\RscCombo\soundCollapse",0.1,1}; // Sound played when the list is collapsed
			soundSelect[] = {"\A3\ui_f\data\sound\RscCombo\soundSelect",0.1,1}; // Sound played when an item is selected

			// Scrollbar configuration (applied only when LB_TEXTURES style is used)
			class ComboScrollBar
			{
				width = 0; // width of ComboScrollBar
				height = 0; // height of ComboScrollBar
				scrollSpeed = 0.01; // scrollSpeed of ComboScrollBar

				arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa"; // Arrow
				arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa"; // Arrow when clicked on
				border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa"; // Slider background (stretched vertically)
				thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa"; // Dragging element (stretched vertically)

				color[] = {1,1,1,1}; // Scrollbar color
			};
		};
		class c_breath
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = 2101; // Control identification (without it, the control won't be displayed)
			type = CT_COMBO; // Type is 4
			style = ST_LEFT + LB_TEXTURES; // Style
			default = 0; // Control selected by default (only one within a display can be used)
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

			x = 0.644375 * safezoneW + safezoneX;
			y = 0.313 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;

			colorBackground[] = {0,0,0,1}; // Fill color
			colorSelectBackground[] = {1,1,1,1}; // Selected item fill color

			sizeEx = 0.02/ (getResolution select 5);
			font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
			shadow = 0; // Shadow (0 - none, 1 - N/A, 2 - black outline)
			colorText[] = {1,1,1,1}; // Text and frame color
			colorDisabled[] = {1,1,1,0.5}; // Disabled text color
			colorSelect[] = {0,0,0,1}; // Text selection color

			pictureColor[] = {1,0.5,0,1}; // Picture color
			pictureColorSelect[] = {1,1,1,1}; // Selected picture color
			pictureColorDisabled[] = {1,1,1,0.5}; // Disabled picture color

			tooltip = ""; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color

			arrowEmpty = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_ca.paa"; // Expand arrow
			arrowFull = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_active_ca.paa"; // Collapse arrow

			wholeHeight = 5 * GUI_GRID_CENTER_H; // Maximum height of expanded box (including the control height)
			maxHistoryDelay = 1; // Time since last keyboard type search to reset it

			soundExpand[] = {"\A3\ui_f\data\sound\RscCombo\soundExpand",0.1,1}; // Sound played when the list is expanded
			soundCollapse[] = {"\A3\ui_f\data\sound\RscCombo\soundCollapse",0.1,1}; // Sound played when the list is collapsed
			soundSelect[] = {"\A3\ui_f\data\sound\RscCombo\soundSelect",0.1,1}; // Sound played when an item is selected

			// Scrollbar configuration (applied only when LB_TEXTURES style is used)
			class ComboScrollBar
			{
				width = 0; // width of ComboScrollBar
				height = 0; // height of ComboScrollBar
				scrollSpeed = 0.01; // scrollSpeed of ComboScrollBar

				arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa"; // Arrow
				arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa"; // Arrow when clicked on
				border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa"; // Slider background (stretched vertically)
				thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa"; // Dragging element (stretched vertically)

				color[] = {1,1,1,1}; // Scrollbar color
			};
		};
		class c_clientserver
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = 2102; // Control identification (without it, the control won't be displayed)
			type = CT_COMBO; // Type is 4
			style = ST_LEFT + LB_TEXTURES; // Style
			default = 0; // Control selected by default (only one within a display can be used)
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

			x = 0.422656 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;

			colorBackground[] = {0,0,0,1}; // Fill color
			colorSelectBackground[] = {1,1,1,1}; // Selected item fill color

			sizeEx = 0.02/ (getResolution select 5);
			font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
			shadow = 0; // Shadow (0 - none, 1 - N/A, 2 - black outline)
			colorText[] = {1,1,1,1}; // Text and frame color
			colorDisabled[] = {1,1,1,0.5}; // Disabled text color
			colorSelect[] = {0,0,0,1}; // Text selection color

			pictureColor[] = {1,0.5,0,1}; // Picture color
			pictureColorSelect[] = {1,1,1,1}; // Selected picture color
			pictureColorDisabled[] = {1,1,1,0.5}; // Disabled picture color

			tooltip = ""; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color

			arrowEmpty = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_ca.paa"; // Expand arrow
			arrowFull = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_active_ca.paa"; // Collapse arrow

			wholeHeight = 5 * GUI_GRID_CENTER_H; // Maximum height of expanded box (including the control height)
			maxHistoryDelay = 1; // Time since last keyboard type search to reset it

			soundExpand[] = {"\A3\ui_f\data\sound\RscCombo\soundExpand",0.1,1}; // Sound played when the list is expanded
			soundCollapse[] = {"\A3\ui_f\data\sound\RscCombo\soundCollapse",0.1,1}; // Sound played when the list is collapsed
			soundSelect[] = {"\A3\ui_f\data\sound\RscCombo\soundSelect",0.1,1}; // Sound played when an item is selected

			// Scrollbar configuration (applied only when LB_TEXTURES style is used)
			class ComboScrollBar
			{
				width = 0; // width of ComboScrollBar
				height = 0; // height of ComboScrollBar
				scrollSpeed = 0.01; // scrollSpeed of ComboScrollBar

				arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa"; // Arrow
				arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa"; // Arrow when clicked on
				border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa"; // Slider background (stretched vertically)
				thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa"; // Dragging element (stretched vertically)

				color[] = {1,1,1,1}; // Scrollbar color
			};
		};
		class c_fog
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = 2103; // Control identification (without it, the control won't be displayed)
			type = CT_COMBO; // Type is 4
			style = ST_LEFT + LB_TEXTURES; // Style
			default = 0; // Control selected by default (only one within a display can be used)
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

			x = 0.644375 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;

			colorBackground[] = {0,0,0,1}; // Fill color
			colorSelectBackground[] = {1,1,1,1}; // Selected item fill color

			sizeEx = 0.02/ (getResolution select 5);
			font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
			shadow = 0; // Shadow (0 - none, 1 - N/A, 2 - black outline)
			colorText[] = {1,1,1,1}; // Text and frame color
			colorDisabled[] = {1,1,1,0.5}; // Disabled text color
			colorSelect[] = {0,0,0,1}; // Text selection color

			pictureColor[] = {1,0.5,0,1}; // Picture color
			pictureColorSelect[] = {1,1,1,1}; // Selected picture color
			pictureColorDisabled[] = {1,1,1,0.5}; // Disabled picture color

			tooltip = ""; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color

			arrowEmpty = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_ca.paa"; // Expand arrow
			arrowFull = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_active_ca.paa"; // Collapse arrow

			wholeHeight = 5 * GUI_GRID_CENTER_H; // Maximum height of expanded box (including the control height)
			maxHistoryDelay = 1; // Time since last keyboard type search to reset it

			soundExpand[] = {"\A3\ui_f\data\sound\RscCombo\soundExpand",0.1,1}; // Sound played when the list is expanded
			soundCollapse[] = {"\A3\ui_f\data\sound\RscCombo\soundCollapse",0.1,1}; // Sound played when the list is collapsed
			soundSelect[] = {"\A3\ui_f\data\sound\RscCombo\soundSelect",0.1,1}; // Sound played when an item is selected

			// Scrollbar configuration (applied only when LB_TEXTURES style is used)
			class ComboScrollBar
			{
				width = 0; // width of ComboScrollBar
				height = 0; // height of ComboScrollBar
				scrollSpeed = 0.01; // scrollSpeed of ComboScrollBar

				arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa"; // Arrow
				arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa"; // Arrow when clicked on
				border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa"; // Slider background (stretched vertically)
				thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa"; // Dragging element (stretched vertically)

				color[] = {1,1,1,1}; // Scrollbar color
			};
		};
		class c_no_snow_indoor
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = 2104; // Control identification (without it, the control won't be displayed)
			type = CT_COMBO; // Type is 4
			style = ST_LEFT + LB_TEXTURES; // Style
			default = 0; // Control selected by default (only one within a display can be used)
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

			x = 0.422656 * safezoneW + safezoneX;
			y = 0.379 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;

			colorBackground[] = {0,0,0,1}; // Fill color
			colorSelectBackground[] = {1,1,1,1}; // Selected item fill color

			sizeEx = 0.02/ (getResolution select 5);
			font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
			shadow = 0; // Shadow (0 - none, 1 - N/A, 2 - black outline)
			colorText[] = {1,1,1,1}; // Text and frame color
			colorDisabled[] = {1,1,1,0.5}; // Disabled text color
			colorSelect[] = {0,0,0,1}; // Text selection color

			pictureColor[] = {1,0.5,0,1}; // Picture color
			pictureColorSelect[] = {1,1,1,1}; // Selected picture color
			pictureColorDisabled[] = {1,1,1,0.5}; // Disabled picture color

			tooltip = ""; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color

			arrowEmpty = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_ca.paa"; // Expand arrow
			arrowFull = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_active_ca.paa"; // Collapse arrow

			wholeHeight = 5 * GUI_GRID_CENTER_H; // Maximum height of expanded box (including the control height)
			maxHistoryDelay = 1; // Time since last keyboard type search to reset it

			soundExpand[] = {"\A3\ui_f\data\sound\RscCombo\soundExpand",0.1,1}; // Sound played when the list is expanded
			soundCollapse[] = {"\A3\ui_f\data\sound\RscCombo\soundCollapse",0.1,1}; // Sound played when the list is collapsed
			soundSelect[] = {"\A3\ui_f\data\sound\RscCombo\soundSelect",0.1,1}; // Sound played when an item is selected

			// Scrollbar configuration (applied only when LB_TEXTURES style is used)
			class ComboScrollBar
			{
				width = 0; // width of ComboScrollBar
				height = 0; // height of ComboScrollBar
				scrollSpeed = 0.01; // scrollSpeed of ComboScrollBar

				arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa"; // Arrow
				arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa"; // Arrow when clicked on
				border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa"; // Slider background (stretched vertically)
				thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa"; // Dragging element (stretched vertically)

				color[] = {1,1,1,1}; // Scrollbar color
			};
		};
		class c_ambient_cough
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = 2105; // Control identification (without it, the control won't be displayed)
			type = CT_COMBO; // Type is 4
			style = ST_LEFT + LB_TEXTURES; // Style
			default = 0; // Control selected by default (only one within a display can be used)
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

			x = 0.422656 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;

			colorBackground[] = {0,0,0,1}; // Fill color
			colorSelectBackground[] = {1,1,1,1}; // Selected item fill color

			sizeEx = 0.02/ (getResolution select 5);
			font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
			shadow = 0; // Shadow (0 - none, 1 - N/A, 2 - black outline)
			colorText[] = {1,1,1,1}; // Text and frame color
			colorDisabled[] = {1,1,1,0.5}; // Disabled text color
			colorSelect[] = {0,0,0,1}; // Text selection color

			pictureColor[] = {1,0.5,0,1}; // Picture color
			pictureColorSelect[] = {1,1,1,1}; // Selected picture color
			pictureColorDisabled[] = {1,1,1,0.5}; // Disabled picture color

			tooltip = ""; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color

			arrowEmpty = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_ca.paa"; // Expand arrow
			arrowFull = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_active_ca.paa"; // Collapse arrow

			wholeHeight = 5 * GUI_GRID_CENTER_H; // Maximum height of expanded box (including the control height)
			maxHistoryDelay = 1; // Time since last keyboard type search to reset it

			soundExpand[] = {"\A3\ui_f\data\sound\RscCombo\soundExpand",0.1,1}; // Sound played when the list is expanded
			soundCollapse[] = {"\A3\ui_f\data\sound\RscCombo\soundCollapse",0.1,1}; // Sound played when the list is collapsed
			soundSelect[] = {"\A3\ui_f\data\sound\RscCombo\soundSelect",0.1,1}; // Sound played when an item is selected

			// Scrollbar configuration (applied only when LB_TEXTURES style is used)
			class ComboScrollBar
			{
				width = 0; // width of ComboScrollBar
				height = 0; // height of ComboScrollBar
				scrollSpeed = 0.01; // scrollSpeed of ComboScrollBar

				arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa"; // Arrow
				arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa"; // Arrow when clicked on
				border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa"; // Slider background (stretched vertically)
				thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa"; // Dragging element (stretched vertically)

				color[] = {1,1,1,1}; // Scrollbar color
			};
		};
		class c_local_fog
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = 2106; // Control identification (without it, the control won't be displayed)
			type = CT_COMBO; // Type is 4
			style = ST_LEFT + LB_TEXTURES; // Style
			default = 0; // Control selected by default (only one within a display can be used)
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

			x = 0.644375 * safezoneW + safezoneX;
			y = 0.379 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;

			colorBackground[] = {0,0,0,1}; // Fill color
			colorSelectBackground[] = {1,1,1,1}; // Selected item fill color

			sizeEx = 0.02/ (getResolution select 5);
			font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
			shadow = 0; // Shadow (0 - none, 1 - N/A, 2 - black outline)
			colorText[] = {1,1,1,1}; // Text and frame color
			colorDisabled[] = {1,1,1,0.5}; // Disabled text color
			colorSelect[] = {0,0,0,1}; // Text selection color

			pictureColor[] = {1,0.5,0,1}; // Picture color
			pictureColorSelect[] = {1,1,1,1}; // Selected picture color
			pictureColorDisabled[] = {1,1,1,0.5}; // Disabled picture color

			tooltip = ""; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color

			arrowEmpty = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_ca.paa"; // Expand arrow
			arrowFull = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_active_ca.paa"; // Collapse arrow

			wholeHeight = 5 * GUI_GRID_CENTER_H; // Maximum height of expanded box (including the control height)
			maxHistoryDelay = 1; // Time since last keyboard type search to reset it

			soundExpand[] = {"\A3\ui_f\data\sound\RscCombo\soundExpand",0.1,1}; // Sound played when the list is expanded
			soundCollapse[] = {"\A3\ui_f\data\sound\RscCombo\soundCollapse",0.1,1}; // Sound played when the list is collapsed
			soundSelect[] = {"\A3\ui_f\data\sound\RscCombo\soundSelect",0.1,1}; // Sound played when an item is selected

			// Scrollbar configuration (applied only when LB_TEXTURES style is used)
			class ComboScrollBar
			{
				width = 0; // width of ComboScrollBar
				height = 0; // height of ComboScrollBar
				scrollSpeed = 0.01; // scrollSpeed of ComboScrollBar

				arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa"; // Arrow
				arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa"; // Arrow when clicked on
				border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa"; // Slider background (stretched vertically)
				thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa"; // Dragging element (stretched vertically)

				color[] = {1,1,1,1}; // Scrollbar color
			};
		};
		class c_ambient_crack
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = 2107; // Control identification (without it, the control won't be displayed)
			type = CT_COMBO; // Type is 4
			style = ST_LEFT + LB_TEXTURES; // Style
			default = 0; // Control selected by default (only one within a display can be used)
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

			x = 0.644375 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;

			colorBackground[] = {0,0,0,1}; // Fill color
			colorSelectBackground[] = {1,1,1,1}; // Selected item fill color

			sizeEx = 0.02/ (getResolution select 5);
			font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
			shadow = 0; // Shadow (0 - none, 1 - N/A, 2 - black outline)
			colorText[] = {1,1,1,1}; // Text and frame color
			colorDisabled[] = {1,1,1,0.5}; // Disabled text color
			colorSelect[] = {0,0,0,1}; // Text selection color

			pictureColor[] = {1,0.5,0,1}; // Picture color
			pictureColorSelect[] = {1,1,1,1}; // Selected picture color
			pictureColorDisabled[] = {1,1,1,0.5}; // Disabled picture color

			tooltip = ""; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color

			arrowEmpty = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_ca.paa"; // Expand arrow
			arrowFull = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_active_ca.paa"; // Collapse arrow

			wholeHeight = 5 * GUI_GRID_CENTER_H; // Maximum height of expanded box (including the control height)
			maxHistoryDelay = 1; // Time since last keyboard type search to reset it

			soundExpand[] = {"\A3\ui_f\data\sound\RscCombo\soundExpand",0.1,1}; // Sound played when the list is expanded
			soundCollapse[] = {"\A3\ui_f\data\sound\RscCombo\soundCollapse",0.1,1}; // Sound played when the list is collapsed
			soundSelect[] = {"\A3\ui_f\data\sound\RscCombo\soundSelect",0.1,1}; // Sound played when an item is selected

			// Scrollbar configuration (applied only when LB_TEXTURES style is used)
			class ComboScrollBar
			{
				width = 0; // width of ComboScrollBar
				height = 0; // height of ComboScrollBar
				scrollSpeed = 0.01; // scrollSpeed of ComboScrollBar

				arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa"; // Arrow
				arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa"; // Arrow when clicked on
				border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa"; // Slider background (stretched vertically)
				thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa"; // Dragging element (stretched vertically)

				color[] = {1,1,1,1}; // Scrollbar color
			};
		};
		class s_direction
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			type = CT_XSLIDER; // Type
			style = SL_HORZ; // Style
			idc = 1900;
			x = 0.443281 * safezoneW + safezoneX;
			y = 0.456 * safezoneH + safezoneY;
			w = 0.185625 * safezoneW;
			h = 0.022 * safezoneH;
			onSliderPosChanged = "sliderNr = 0; [] spawn TFSC_fnc_setSliderValue; false";
			default = 0; // Control selected by default (only one within a display can be used)
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.
			color[] = {1,1,1,1}; // Text and arrow color
			colorDisabled[] = {1,1,1,0.5}; // Disabled text and arrow color
			colorActive[] = {1,1,1,1}; // Text selection color
			tooltip = ""; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
			arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa"; // Arrow
			arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa"; // Arrow when clicked on
			border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa"; // Fill texture
			thumb = "#(argb,8,8,3)color(1,1,1,1)"; // Dragging element (stretched vertically)
			class Title // Link to a title (obsolete?)
			{
				idc = -1; // Control IDC (has to be defined ABOVE the slider control)
				colorBase[] = {1,1,1,1}; // Text color
				colorActive[] = {1,1,1,1}; // Text color when the slider is active
			};
			class Value // Link to a control which will show slider value
			{
				idc = -1; // Control IDC (has to be defined ABOVE the slider control)
				format = "%.f"; // Text format, value is represented by variable %g (float) or %.f (integer)
				type = SPTPlain; // Format, can be SPTPlain or SPTPercents (multiplies the value by 100)
				colorBase[] = {1,1,1,1}; // Text color
				colorActive[] = {1,1,1,1}; // Text color when the slider is active
			};
		};
		class s_duration
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			type = CT_XSLIDER; // Type
			style = SL_HORZ; // Style
			idc = 1901;
			x = 0.443281 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.185625 * safezoneW;
			h = 0.022 * safezoneH;
			onSliderPosChanged = "sliderNr = 1; [] spawn TFSC_fnc_setSliderValue; false";
			default = 0; // Control selected by default (only one within a display can be used)
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.
			color[] = {1,1,1,1}; // Text and arrow color
			colorDisabled[] = {1,1,1,0.5}; // Disabled text and arrow color
			colorActive[] = {1,1,1,1}; // Text selection color
			tooltip = ""; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
			arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa"; // Arrow
			arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa"; // Arrow when clicked on
			border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa"; // Fill texture
			thumb = "#(argb,8,8,3)color(1,1,1,1)"; // Dragging element (stretched vertically)
			class Title // Link to a title (obsolete?)
			{
				idc = -1; // Control IDC (has to be defined ABOVE the slider control)
				colorBase[] = {1,1,1,1}; // Text color
				colorActive[] = {1,1,1,1}; // Text color when the slider is active
			};
			class Value // Link to a control which will show slider value
			{
				idc = -1; // Control IDC (has to be defined ABOVE the slider control)
				format = "%.f"; // Text format, value is represented by variable %g (float) or %.f (integer)
				type = SPTPlain; // Format, can be SPTPlain or SPTPercents (multiplies the value by 100)
				colorBase[] = {1,1,1,1}; // Text color
				colorActive[] = {1,1,1,1}; // Text color when the slider is active
			};
		};
		class s_delay
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			type = CT_XSLIDER; // Type
			style = SL_HORZ; // Style
			idc = 1902;
			x = 0.443281 * safezoneW + safezoneX;
			y = 0.632 * safezoneH + safezoneY;
			w = 0.185625 * safezoneW;
			h = 0.022 * safezoneH;
			onSliderPosChanged = "sliderNr = 2; [] spawn TFSC_fnc_setSliderValue; false";
			default = 0; // Control selected by default (only one within a display can be used)
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.
			color[] = {1,1,1,1}; // Text and arrow color
			colorDisabled[] = {1,1,1,0.5}; // Disabled text and arrow color
			colorActive[] = {1,1,1,1}; // Text selection color
			tooltip = ""; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
			arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa"; // Arrow
			arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa"; // Arrow when clicked on
			border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa"; // Fill texture
			thumb = "#(argb,8,8,3)color(1,1,1,1)"; // Dragging element (stretched vertically)
			class Title // Link to a title (obsolete?)
			{
				idc = -1; // Control IDC (has to be defined ABOVE the slider control)
				colorBase[] = {1,1,1,1}; // Text color
				colorActive[] = {1,1,1,1}; // Text color when the slider is active
			};
			class Value // Link to a control which will show slider value
			{
				idc = -1; // Control IDC (has to be defined ABOVE the slider control)
				format = "%.f"; // Text format, value is represented by variable %g (float) or %.f (integer)
				type = SPTPlain; // Format, can be SPTPlain or SPTPercents (multiplies the value by 100)
				colorBase[] = {1,1,1,1}; // Text color
				colorActive[] = {1,1,1,1}; // Text color when the slider is active
			};
		};
		class s_snow_intensity
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			type = CT_XSLIDER; // Type
			style = SL_HORZ; // Style
			idc = 1903;
			x = 0.443281 * safezoneW + safezoneX;
			y = 0.588 * safezoneH + safezoneY;
			w = 0.185625 * safezoneW;
			h = 0.022 * safezoneH;
			onSliderPosChanged = "sliderNr = 3; [] spawn TFSC_fnc_setSliderValue; false";
			default = 0; // Control selected by default (only one within a display can be used)
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.
			color[] = {1,1,1,1}; // Text and arrow color
			colorDisabled[] = {1,1,1,0.5}; // Disabled text and arrow color
			colorActive[] = {1,1,1,1}; // Text selection color
			tooltip = ""; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
			arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa"; // Arrow
			arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa"; // Arrow when clicked on
			border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa"; // Fill texture
			thumb = "#(argb,8,8,3)color(1,1,1,1)"; // Dragging element (stretched vertically)
			class Title // Link to a title (obsolete?)
			{
				idc = -1; // Control IDC (has to be defined ABOVE the slider control)
				colorBase[] = {1,1,1,1}; // Text color
				colorActive[] = {1,1,1,1}; // Text color when the slider is active
			};
			class Value // Link to a control which will show slider value
			{
				idc = -1; // Control IDC (has to be defined ABOVE the slider control)
				format = "%.f"; // Text format, value is represented by variable %g (float) or %.f (integer)
				type = SPTPlain; // Format, can be SPTPlain or SPTPercents (multiplies the value by 100)
				colorBase[] = {1,1,1,1}; // Text color
				colorActive[] = {1,1,1,1}; // Text color when the slider is active
			};
		};
		class s_fog_intensity
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			type = CT_XSLIDER; // Type
			style = SL_HORZ; // Style
			idc = 1904;
			x = 0.443281 * safezoneW + safezoneX;
			y = 0.544 * safezoneH + safezoneY;
			w = 0.185625 * safezoneW;
			h = 0.022 * safezoneH;
			onSliderPosChanged = "sliderNr = 4; [] spawn TFSC_fnc_setSliderValue; false";
			default = 0; // Control selected by default (only one within a display can be used)
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.
			color[] = {1,1,1,1}; // Text and arrow color
			colorDisabled[] = {1,1,1,0.5}; // Disabled text and arrow color
			colorActive[] = {1,1,1,1}; // Text selection color
			tooltip = ""; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
			arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa"; // Arrow
			arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa"; // Arrow when clicked on
			border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa"; // Fill texture
			thumb = "#(argb,8,8,3)color(1,1,1,1)"; // Dragging element (stretched vertically)
			class Title // Link to a title (obsolete?)
			{
				idc = -1; // Control IDC (has to be defined ABOVE the slider control)
				colorBase[] = {1,1,1,1}; // Text color
				colorActive[] = {1,1,1,1}; // Text color when the slider is active
			};
			class Value // Link to a control which will show slider value
			{
				idc = -1; // Control IDC (has to be defined ABOVE the slider control)
				format = "%.f"; // Text format, value is represented by variable %g (float) or %.f (integer)
				type = SPTPlain; // Format, can be SPTPlain or SPTPercents (multiplies the value by 100)
				colorBase[] = {1,1,1,1}; // Text color
				colorActive[] = {1,1,1,1}; // Text color when the slider is active
			};
		};
		class s_overcast
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			type = CT_XSLIDER; // Type
			style = SL_HORZ; // Style
			idc = 1905;
			x = 0.443281 * safezoneW + safezoneX;
			y = 0.676 * safezoneH + safezoneY;
			w = 0.185625 * safezoneW;
			h = 0.022 * safezoneH;
			onSliderPosChanged = "sliderNr = 5; [] spawn TFSC_fnc_setSliderValue; false";
			default = 0; // Control selected by default (only one within a display can be used)
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.
			color[] = {1,1,1,1}; // Text and arrow color
			colorDisabled[] = {1,1,1,0.5}; // Disabled text and arrow color
			colorActive[] = {1,1,1,1}; // Text selection color
			tooltip = ""; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
			arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa"; // Arrow
			arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa"; // Arrow when clicked on
			border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa"; // Fill texture
			thumb = "#(argb,8,8,3)color(1,1,1,1)"; // Dragging element (stretched vertically)
			class Title // Link to a title (obsolete?)
			{
				idc = -1; // Control IDC (has to be defined ABOVE the slider control)
				colorBase[] = {1,1,1,1}; // Text color
				colorActive[] = {1,1,1,1}; // Text color when the slider is active
			};
			class Value // Link to a control which will show slider value
			{
				idc = -1; // Control IDC (has to be defined ABOVE the slider control)
				format = "%.f"; // Text format, value is represented by variable %g (float) or %.f (integer)
				type = SPTPlain; // Format, can be SPTPlain or SPTPercents (multiplies the value by 100)
				colorBase[] = {1,1,1,1}; // Text color
				colorActive[] = {1,1,1,1}; // Text color when the slider is active
			};
		};
		class b_close 
		{
			idc = 1600;
			type = CT_BUTTON;
			style = 14;
			default = false;
			sizeEx = GUI_GRID_CENTER_H;
			font = GUI_FONT_BOLD;
			colorBackground[] = {1,1,1,1}; // Fill color
			colorBackgroundDisabled[] = {1,1,1,0.5}; // Disabled fill color
			colorBackgroundActive[] = {0,0,0,1}; // Mouse hover fill color
			colorFocused[] = {0,0,0,1}; // Selected fill color (oscillates between this and colorBackground)
			colorText[] = {0.15,0.25,0.55,1}; // Text color
			colorDisabled[] = {0.15,0.25,0.55,1}; // Disabled text color
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1}; // Sound played after control is activated in format {file, volume, pitch}
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1}; // Sound played when mouse cursor enters the control
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1}; // Sound played when the control is pushed down
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1}; // Sound played when the control is released after pushing down
			x = 0.659844 * safezoneW + safezoneX;
			y = 0.72 * safezoneH + safezoneY;
			w = 0.04125 * safezoneW;
			h = 0.044 * safezoneH;
			borderSize = 0.01; // Left color width (border is a stripe of the control height on the left side)
			colorBorder[] = {1,1,1,1}; // Left border color
			colorShadow[] = {0,0,0,0}; // Background frame color
			offsetX = 0.0075; // Horizontal background frame offset
			offsetY = 0.01; // Vertical background frame offset
			offsetPressedX = 0.0075; // Horizontal background offset when pressed
			offsetPressedY = 0.01; // Horizontal background offset when pressed
			text = "Close";
			tooltip = "Abort / close the Snow Storm Spawn Menu";
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
			action = "closeDialog 0;";
		};
		class b_confirm 
		{
			idc = 1601;
			type = CT_BUTTON;
			style = 14;
			default = false;
			sizeEx = GUI_GRID_CENTER_H;
			font = GUI_FONT_BOLD;
			colorBackground[] = {1,1,1,1}; // Fill color
			colorBackgroundDisabled[] = {1,1,1,0.5}; // Disabled fill color
			colorBackgroundActive[] = {0,0,0,1}; // Mouse hover fill color
			colorFocused[] = {0,0,0,1}; // Selected fill color (oscillates between this and colorBackground)
			colorText[] = {0.15,0.25,0.55,1}; // Text color
			colorDisabled[] = {0.15,0.25,0.55,1}; // Disabled text color
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1}; // Sound played after control is activated in format {file, volume, pitch}
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1}; // Sound played when mouse cursor enters the control
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1}; // Sound played when the control is pushed down
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1}; // Sound played when the control is released after pushing down
			x = 0.474219 * safezoneW + safezoneX;
			y = 0.72 * safezoneH + safezoneY;
			w = 0.0515625 * safezoneW;
			h = 0.044 * safezoneH;
			borderSize = 0.01; // Left color width (border is a stripe of the control height on the left side)
			colorBorder[] = {1,1,1,1}; // Left border color
			colorShadow[] = {0,0,0,0}; // Background frame color
			offsetX = 0.0075; // Horizontal background frame offset
			offsetY = 0.01; // Vertical background frame offset
			offsetPressedX = 0.0075; // Horizontal background offset when pressed
			offsetPressedY = 0.01; // Horizontal background offset when pressed
			text = "Confirm";
			tooltip = "Confirm the settings and initialize snow storm";
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
			action = "[] spawn TFSC_fnc_storm_init; false";
		};
		class b_abort 
		{
			idc = 1602;
			type = CT_BUTTON;
			style = 14;
			default = true;
			sizeEx = GUI_GRID_CENTER_H;
			font = GUI_FONT_BOLD;
			colorBackground[] = {1,1,1,1}; // Fill color
			colorBackgroundDisabled[] = {1,1,1,0.5}; // Disabled fill color
			colorBackgroundActive[] = {0,0,0,1}; // Mouse hover fill color
			colorFocused[] = {0,0,0,1}; // Selected fill color (oscillates between this and colorBackground)
			colorText[] = {0.15,0.25,0.55,1}; // Text color
			colorDisabled[] = {0.15,0.25,0.55,1}; // Disabled text color
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1}; // Sound played after control is activated in format {file, volume, pitch}
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1}; // Sound played when mouse cursor enters the control
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1}; // Sound played when the control is pushed down
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1}; // Sound played when the control is released after pushing down
			x = 0.28 * safezoneW + safezoneX;
			y = 0.72 * safezoneH + safezoneY;
			w = 0.097 * safezoneW;
			h = 0.044 * safezoneH;
			borderSize = 0.01; // Left color width (border is a stripe of the control height on the left side)
			colorBorder[] = {1,1,1,1}; // Left border color
			colorShadow[] = {0,0,0,0}; // Background frame color
			offsetX = 0.0075; // Horizontal background frame offset
			offsetY = 0.01; // Vertical background frame offset
			offsetPressedX = 0.0075; // Horizontal background offset when pressed
			offsetPressedY = 0.01; // Horizontal background offset when pressed
			text = "Terminate snow storm";
			tooltip = "Terminate currently running snow storm";
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
			action = "[] spawn TFSC_fnc_terminateSnow; false";
		};
	};
	class ControlsBackground
	{
		class background
		{
			idc = 1000;
			text = "TFSC\images\tablet.paa";
			access = 0;
			type = CT_STATIC;
			style = 48;//ST_PICTURE
			colorBackground[] = {0,0,0,0};
			colorText[] = {1,1,1,1};
			x = 0.145625 * safezoneW + safezoneX;
			y = 0.14 * safezoneH + safezoneY;
			w = 0.675 * 1.05 * safezoneW;
			h = 0.9 * 0.8 * 1.05 * safezoneH;
			font = "EtelkaMonospacePro";
			sizeEx = 0;
			lineSpacing = 0;
			fixedWidth = 0;
			shadow = 0;
		};
		class t_header_bg
		{
			access = 0;
			type = 0;
			idc = 1002;
			colorBackground[] = {1,1,1,1};
			colorText[] = {1,1,1,1};
			text = "";
			fixedWidth = 0;
			x = 0.4175 * safezoneW + safezoneX;
			y = 0.236 * safezoneH + safezoneY;
			w = 0.165 * safezoneW;
			h = 0.066 * safezoneH;
			style = 2;
			shadow = 2;
			tooltip = ""; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
			font = GUI_FONT_NORMAL;
			sizeEx = "0.02/ (getResolution select 5)";
		};
		class t_header
		{
			access = 0;
			type = 0;
			idc = 1001;
			colorText[] = {1,1,1,1};
			fixedWidth = 0;
			font = GUI_FONT_BOLD;
			colorBackground[] = {0.059,0.098,0.216,1};
			sizeEx = "0.03/ (getResolution select 5)";
			text = "Snow Storm Spawn Menu";
			x = 0.422657 * safezoneW + safezoneX;
			y = 0.247 * safezoneH + safezoneY;
			w = 0.154687 * safezoneW;
			h = 0.044 * safezoneH;
			style = 2;
			shadow = 2;
			tooltip = ""; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
		};
		class t_objects
		{
			access = 0;
			type = 0;
			idc = 1003;
			colorText[] = {1,1,1,1};
			fixedWidth = 0;
			font = GUI_FONT_BOLD;
			colorBackground[] = {0.059,0.098,0.216,0};
			sizeEx = "0.02/ (getResolution select 5)";
			text = "Effect on objects:";
			tooltip = "Occasionally a random object will be thrown in the air (NOTE: Object can also be the player :D)";
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.313 * safezoneH + safezoneY;
			w = 0.12375 * safezoneW;
			h = 0.022 * safezoneH;
			style = ST_LEFT;
			shadow = 2;
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
		};
		class t_breath
		{
			access = 0;
			type = 0;
			idc = 1004;
			colorText[] = {1,1,1,1};
			fixedWidth = 0;
			font = GUI_FONT_BOLD;
			colorBackground[] = {0.059,0.098,0.216,0};
			sizeEx = "0.02/ (getResolution select 5)";
			text = "Breath vapor:";
			tooltip = "Will enable breath vapors for all units, however if you have many units in your mission you should disable this to diminish the impact on frames.";
			x = 0.510312 * safezoneW + safezoneX;
			y = 0.313 * safezoneH + safezoneY;
			w = 0.12375 * safezoneW;
			h = 0.022 * safezoneH;
			style = ST_LEFT;
			shadow = 2;
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
		};
		class t_clientserver
		{
			access = 0;
			type = 0;
			idc = 1005;
			colorText[] = {1,1,1,1};
			fixedWidth = 0;
			font = GUI_FONT_BOLD;
			colorBackground[] = {0.059,0.098,0.216,0};
			sizeEx = "0.02/ (getResolution select 5)";
			text = "Execute gusts on:";
			tooltip = "Enable for full-on blizzard effects.(NOTE: Client/Server are two different effects) If enabled snow will be whirled up by gusts. Will add to server load if executed on server, however gust will be different for each player if executed on client.";
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.12375 * safezoneW;
			h = 0.022 * safezoneH;
			style = ST_LEFT;
			shadow = 2;
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
		};
		class t_fog
		{
			access = 0;
			type = 0;
			idc = 1006;
			colorText[] = {1,1,1,1};
			fixedWidth = 0;
			font = GUI_FONT_BOLD;
			colorBackground[] = {0.059,0.098,0.216,0};
			sizeEx = "0.02/ (getResolution select 5)";
			text = "Change fog settings?";
			tooltip = "If enabled fog will be managed by the script, otherwise the values will remain unchanged.";
			x = 0.510312 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.12375 * safezoneW;
			h = 0.022 * safezoneH;
			style = ST_LEFT;
			shadow = 2;
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
		};
		class t_no_snow_indoor
		{
			access = 0;
			type = 0;
			idc = 1012;
			colorText[] = {1,1,1,1};
			fixedWidth = 0;
			font = GUI_FONT_BOLD;
			colorBackground[] = {0.059,0.098,0.216,0};
			sizeEx = "0.02/ (getResolution select 5)";
			text = "Forbid snow indoors:";
			tooltip = "If enabled snow will no longer appear inside of buildings when the player is inside as well. You may want to disable this option in bigger scenarios to save on performance.";
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.379 * safezoneH + safezoneY;
			w = 0.12375 * safezoneW;
			h = 0.022 * safezoneH;
			style = ST_LEFT;
			shadow = 2;
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
		};
		class t_ambient_cough
		{
			access = 0;
			type = 0;
			idc = 1013;
			colorText[] = {1,1,1,1};
			fixedWidth = 0;
			font = GUI_FONT_BOLD;
			colorBackground[] = {0.059,0.098,0.216,0};
			sizeEx = "0.02/ (getResolution select 5)";
			text = "Ambient coughing/shivering:";
			tooltip = "If enabled, units will cough or shiver every once in a while. Delay is set by 'Ambient sound delay'.";
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.12375 * safezoneW;
			h = 0.022 * safezoneH;
			style = ST_LEFT;
			shadow = 2;
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
		};
		class t_local_fog
		{
			access = 0;
			type = 0;
			idc = 1014;
			colorText[] = {1,1,1,1};
			fixedWidth = 0;
			font = GUI_FONT_BOLD;
			colorBackground[] = {0.059,0.098,0.216,0};
			sizeEx = "0.02/ (getResolution select 5)";
			text = "Enable local fog:";
			tooltip = "If true particles will be used to create sort of waves of fog and snow. May reduce performance in bigger scenarios.";
			x = 0.510312 * safezoneW + safezoneX;
			y = 0.379 * safezoneH + safezoneY;
			w = 0.12375 * safezoneW;
			h = 0.022 * safezoneH;
			style = ST_LEFT;
			shadow = 2;
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
		};
		class t_ambient_crack
		{
			access = 0;
			type = 0;
			idc = 1015;
			colorText[] = {1,1,1,1};
			fixedWidth = 0;
			font = GUI_FONT_BOLD;
			colorBackground[] = {0.059,0.098,0.216,0};
			sizeEx = "0.02/ (getResolution select 5)";
			text = "Ambient sounds: cracks";
			tooltip = "If enabled branches will crack occasionally.";
			x = 0.510312 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.12375 * safezoneW;
			h = 0.022 * safezoneH;
			style = ST_LEFT;
			shadow = 2;
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
		};
		class t_direction
		{
			access = 0;
			type = 0;
			idc = 1007;
			colorText[] = {1,1,1,1};
			fixedWidth = 0;
			font = GUI_FONT_BOLD;
			colorBackground[] = {0.059,0.098,0.216,0};
			sizeEx = "0.02/ (getResolution select 5)";
			text = "Snow storm direction:";
			tooltip = "From 1 to 360, direction towards the wind blows expressed in compass degrees.";
			x = 0.293749 * safezoneW + safezoneX;
			y = 0.445 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.033 * safezoneH;
			style = ST_LEFT;
			shadow = 2;
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
		};
		class t_duration
		{
			access = 0;
			type = 0;
			idc = 1008;
			colorText[] = {1,1,1,1};
			fixedWidth = 0;
			font = GUI_FONT_BOLD;
			colorBackground[] = {0.059,0.098,0.216,0};
			sizeEx = "0.02/ (getResolution select 5)";
			text = "Snow storm duration:";
			tooltip = "Duration how long the snow storm will last expressed in minutes.";
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.033 * safezoneH;
			style = ST_LEFT;
			shadow = 2;
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
		};
		class t_delay
		{
			access = 0;
			type = 0;
			idc = 1009;
			colorText[] = {1,1,1,1};
			fixedWidth = 0;
			font = GUI_FONT_BOLD;
			colorBackground[] = {0.059,0.098,0.216,0};
			sizeEx = "0.02/ (getResolution select 5)";
			text = "Ambient sound delay:";
			tooltip = "Maximum delay in minutes between random ambient sounds. Minimum delay is set to one minute.";
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.621 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.033 * safezoneH;
			style = ST_LEFT;
			shadow = 2;
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
		};
		class t_overcast
		{
			access = 0;
			type = 0;
			idc = 1016;
			colorText[] = {1,1,1,1};
			fixedWidth = 0;
			font = GUI_FONT_BOLD;
			colorBackground[] = {0.059,0.098,0.216,0};
			sizeEx = "0.02/ (getResolution select 5)";
			text = "Overcast:";
			tooltip = "Higher percentage results in denser clouds. Leave it as is if you're fine with current weather conditions.";
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.665 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.033 * safezoneH;
			style = ST_LEFT;
			shadow = 2;
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
		};
		class t_snow_intensity
		{
			access = 0;
			type = 0;
			idc = 1010;
			colorText[] = {1,1,1,1};
			fixedWidth = 0;
			font = GUI_FONT_BOLD;
			colorBackground[] = {0.059,0.098,0.216,0};
			sizeEx = "0.02/ (getResolution select 5)";
			text = "Snow intensity:";
			tooltip = "Snow intensity: Higher percentage results in more snowflakes but fewer frames.(NOTE: values above 25% may reach the maximum amount of particles resulting in snowflakes despawning much faster as well as smoke grenades being less efficient.)";
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.577 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.033 * safezoneH;
			style = ST_LEFT;
			shadow = 2;
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
		};
		class t_fog_intensity
		{
			access = 0;
			type = 0;
			idc = 1011;
			colorText[] = {1,1,1,1};
			fixedWidth = 0;
			font = GUI_FONT_BOLD;
			colorBackground[] = {0.059,0.098,0.216,0};
			sizeEx = "0.02/ (getResolution select 5)";
			text = "Fog intensity:";
			tooltip = "Fog intensity: (ONLY if fog is allowed to be managed by mod -> Check settings above). Higher fog percentage will result in a more authentic snow storm effect but worse visibility conditions.";
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.533 * safezoneH + safezoneY;
			w = 0.139219 * safezoneW;
			h = 0.033 * safezoneH;
			style = ST_LEFT;
			shadow = 2;
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
		};
		class t_s_direction
		{
			access = 0;
			type = 0;
			idc = 19000;
			colorText[] = {1,1,1,1};
			fixedWidth = 0;
			font = GUI_FONT_BOLD;
			colorBackground[] = {0.059,0.098,0.216,0};
			sizeEx = "0.02/ (getResolution select 5)";
			text = "360°";
			tooltip = "";
			x = 0.634062 * safezoneW + safezoneX;
			y = 0.456 * safezoneH + safezoneY;
			w = 0.04125 * safezoneW;
			h = 0.022 * safezoneH;
			style = ST_LEFT;
			shadow = 2;
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
		};
		class t_s_overcast
		{
			access = 0;
			type = 0;
			idc = 19005;
			colorText[] = {1,1,1,1};
			fixedWidth = 0;
			font = GUI_FONT_BOLD;
			colorBackground[] = {0.059,0.098,0.216,0};
			sizeEx = "0.02/ (getResolution select 5)";
			text = "80%";
			tooltip = "";
			x = 0.634062 * safezoneW + safezoneX;
			y = 0.676 * safezoneH + safezoneY;
			w = 0.04125 * safezoneW;
			h = 0.022 * safezoneH;
			style = ST_LEFT;
			shadow = 2;
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
		};
		class t_s_duration
		{
			access = 0;
			type = 0;
			idc = 19001;
			colorText[] = {1,1,1,1};
			fixedWidth = 0;
			font = GUI_FONT_BOLD;
			colorBackground[] = {0.059,0.098,0.216,0};
			sizeEx = "0.02/ (getResolution select 5)";
			tooltip = "";
			text = "5 min";
			x = 0.634062 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.04125 * safezoneW;
			h = 0.022 * safezoneH;
			style = ST_LEFT;
			shadow = 2;
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
		};
		class t_s_delay
		{
			access = 0;
			type = 0;
			idc = 19002;
			colorText[] = {1,1,1,1};
			fixedWidth = 0;
			font = GUI_FONT_BOLD;
			colorBackground[] = {0.059,0.098,0.216,0};
			sizeEx = "0.02/ (getResolution select 5)";
			tooltip = "";
			text = "1 min";
			x = 0.634062 * safezoneW + safezoneX;
			y = 0.632 * safezoneH + safezoneY;
			w = 0.04125 * safezoneW;
			h = 0.022 * safezoneH;
			style = ST_LEFT;
			shadow = 2;
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
		};
		class t_s_snow_intensity
		{
			access = 0;
			type = 0;
			idc = 19003;
			colorText[] = {1,1,1,1};
			fixedWidth = 0;
			font = GUI_FONT_BOLD;
			colorBackground[] = {0.059,0.098,0.216,0};
			sizeEx = "0.02/ (getResolution select 5)";
			tooltip = "";
			text = "25%";
			x = 0.634062 * safezoneW + safezoneX;
			y = 0.588 * safezoneH + safezoneY;
			w = 0.04125 * safezoneW;
			h = 0.022 * safezoneH;
			style = ST_LEFT;
			shadow = 2;
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
		};
		class t_s_fog_intensity
		{
			access = 0;
			type = 0;
			idc = 19004;
			colorText[] = {1,1,1,1};
			fixedWidth = 0;
			font = GUI_FONT_BOLD;
			colorBackground[] = {0.059,0.098,0.216,0};
			sizeEx = "0.02/ (getResolution select 5)";
			tooltip = "";
			text = "65%";
			x = 0.634062 * safezoneW + safezoneX;
			y = 0.544 * safezoneH + safezoneY;
			w = 0.04125 * safezoneW;
			h = 0.022 * safezoneH;
			style = ST_LEFT;
			shadow = 2;
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {0.15,0.25,0.55,1}; // Tooltip frame color
		};
	};
};



