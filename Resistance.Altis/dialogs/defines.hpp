// Control types
#define CT_STATIC           0
#define CT_BUTTON           1
#define CT_EDIT             2
#define CT_SLIDER           3
#define CT_COMBO            4
#define CT_LISTBOX          5
#define CT_TOOLBOX          6
#define CT_CHECKBOXES       7
#define CT_PROGRESS         8
#define CT_HTML             9
#define CT_STATIC_SKEW      10
#define CT_ACTIVETEXT       11
#define CT_TREE             12
#define CT_STRUCTURED_TEXT  13
#define CT_CONTEXT_MENU     14
#define CT_CONTROLS_GROUP   15
#define CT_SHORTCUTBUTTON   16
#define CT_XKEYDESC         40
#define CT_XBUTTON          41
#define CT_XLISTBOX         42
#define CT_XSLIDER          43
#define CT_XCOMBO           44
#define CT_ANIMATED_TEXTURE 45
#define CT_OBJECT           80
#define CT_OBJECT_ZOOM      81
#define CT_OBJECT_CONTAINER 82
#define CT_OBJECT_CONT_ANIM 83
#define CT_LINEBREAK        98
#define CT_USER             99
#define CT_MAP              100
#define CT_MAP_MAIN         101
#define CT_LISTNBOX         102

// Static styles
#define ST_POS            0x0F
#define ST_HPOS           0x03
#define ST_VPOS           0x0C
#define ST_LEFT           0x00
#define ST_RIGHT          0x01
#define ST_CENTER         0x02
#define ST_DOWN           0x04
#define ST_UP             0x08
#define ST_VCENTER        0x0C
#define ST_GROUP_BOX       96
#define ST_GROUP_BOX2      112
#define ST_ROUNDED_CORNER  ST_GROUP_BOX + ST_CENTER
#define ST_ROUNDED_CORNER2 ST_GROUP_BOX2 + ST_CENTER

#define ST_TYPE           0xF0
#define ST_SINGLE         0x00
#define ST_MULTI          0x10
#define ST_TITLE_BAR      0x20
#define ST_PICTURE        0x30
#define ST_FRAME          0x40
#define ST_BACKGROUND     0x50
#define ST_GROUP_BOX      0x60
#define ST_GROUP_BOX2     0x70
#define ST_HUD_BACKGROUND 0x80
#define ST_TILE_PICTURE   0x90
#define ST_WITH_RECT      0xA0
#define ST_LINE           0xB0

#define ST_SHADOW         0x100
#define ST_NO_RECT        0x200
#define ST_KEEP_ASPECT_RATIO  0x800

#define ST_TITLE          ST_TITLE_BAR + ST_CENTER

// Slider styles
#define SL_DIR            0x400
#define SL_VERT           0
#define SL_HORZ           0x400

#define SL_TEXTURES       0x10

// progress bar
#define ST_VERTICAL       0x01
#define ST_HORIZONTAL     0

// Listbox styles
#define LB_TEXTURES       0x10
#define LB_MULTI          0x20

// Tree styles
#define TR_SHOWROOT       1
#define TR_AUTOCOLLAPSE   2

// MessageBox styles
#define MB_BUTTON_OK      1
#define MB_BUTTON_CANCEL  2
#define MB_BUTTON_USER    4

class RscText {
	access = 0;
	idc = -1;
	type = CT_STATIC;
	style = ST_MULTI;
	linespacing = 1;
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	text = "";
	shadow = 2;
	font = "PuristaMedium";
	SizeEx = 0.02300;
	fixedWidth = 0;
	x = 0;
	y = 0;
	h = 0;
	w = 0;
};

class RscPicture {
	access = 0;
	idc = -1;
	type = CT_STATIC;
	style = ST_PICTURE;
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	font = "PuristaMedium";
	sizeEx = 0;
	lineSpacing = 0;
	text = "";
	fixedWidth = 0;
	shadow = 0;
	x = 0;
	y = 0;
	w = 0.2;
	h = 0.15;
};

class RscButton {
	access = 0;
	type = CT_BUTTON;
	text = "";
	colorText[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,1};
	colorBackground[] =  {0.247,0.243,0.243,1};
	colorBackgroundDisabled[] = {0,0.0,0};
	colorBackgroundActive[] = {0.247,0.243,0.243,1};
	colorFocused[] = {0.247,0.243,0.243,1};
	colorShadow[] = {0.023529,0,0.0313725,1};
	colorBorder[] = {0.023529,0,0.0313725,1};
	soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
	soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
	soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
	soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
	style = 2;
	x = 0;
	y = 0;
	w = 0.055589;
	h = 0.039216;
	shadow = 2;
	font = "PuristaMedium";
	sizeEx = 0.05;
	offsetX = 0.003;
	offsetY = 0.003;
	offsetPressedX = 0.002;
	offsetPressedY = 0.002;
	borderSize = 0;
	onMouseEnter = "(_this select 0) ctrlSetTextColor [1,0.969,0,1]";
	onMouseExit = "(_this select 0) ctrlSetTextColor [1,1,1,1]";
};

class RscFrame {
	type = CT_STATIC;
	idc = -1;
	style = ST_FRAME;
	shadow = 2;
	colorBackground[] = {1,1,1,1};//{1,1,1,1}
	colorText[] = {1,1,1,0.9};
	font = "PuristaMedium";
	sizeEx = 0.03;
	text = "";
};

class BOX {
	type = CT_STATIC;
	idc = -1;
	style = ST_CENTER;
	shadow = 2;
	colorText[] = {1,1,1,1};
	font = "PuristaMedium";
	sizeEx = 0.02;
	colorBackground[] = { 0.2,0.2,0.2, 0.9 };
	text = "";
};

class RscListBox {
	 access = 0;
	 type = 5;
	 style = 0;
	 w = 0.4;
	 h = 0.4;
	 font = "TahomaB";
	 sizeEx = 0.04;
	 rowHeight = 0;
	 colorText[] = {1,1,1,1};
	 colorScrollbar[] = {1,1,1,1};
	 colorSelect[] = {0,0,0,1};
	 colorSelect2[] = {1,0.5,0,1};
	 colorSelectBackground[] = {0.6,0.6,0.6,1};
	 colorSelectBackground2[] = {0.2,0.2,0.2,1};
	 colorBackground[] = {0.2,0.2,0.2,0.9};
	 maxHistoryDelay = 1.0;
	 soundSelect[] = {"",0.1,1};
	 period = 1;
	 autoScrollSpeed = -1;
	 autoScrollDelay = 5;
	 autoScrollRewind = 0;
	 arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
	 arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
	 shadow = 0;

	 class ListScrollBar {
		  color[] = {1,1,1,0.6};
		  colorActive[] = {1,1,1,1};
		  colorDisabled[] = {1,1,1,0.3};
		  thumb = "#(argb,8,8,3)color(1,1,1,1)";
		  arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
		  arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
		  border = "#(argb,8,8,3)color(1,1,1,1)";
		  shadow = 0;
	 };
};

class RscTitles {

	class Default {
	   idd = -1;
	   fadein = 0;
	   fadeout = 0;
	   duration = 0;
	};

	class H8erHUD {
		idd = 745;
		movingEnable =  0;
		enableSimulation = 1;
		enableDisplay = 1;
		duration     =  10e10;
		fadein       =  0;
		fadeout      =  0;
		name = "H8erHUD";
		onLoad = "with uiNameSpace do { H8erHUD = _this select 0 }";
		class controls {
			class structuredText {
				access = 0;
				type = 13;
				idc = 1001;
				style = 0x00;
				lineSpacing = 1;
				x = 0.103165 * safezoneW + safezoneX;
				y = 0.007996 * safezoneH + safezoneY;//0.757996
				w = 0.778208 * safezoneW;
				h = 0.0660106 * safezoneH;
				size = 0.055;//0.020
				colorBackground[] = {0, 0, 0, 0};
				colorText[] = {0.34, 0.33, 0.33, 0};// {1, 1, 1, 1}
				text = "";
				font = "PuristaSemiBold";
				class Attributes {
					font = "PuristaSemiBold";
					color = "#C1C0BB";//"#FFFFFF";
					align = "CENTER";
					valign = "top";
					shadow = true;
					shadowColor = "#000000";
					underline = false;
					size = "4";//4
				};
			};
		};
	};
};
