#include "defineCommon.inc"

private ["_flag","_typeX"];

if (!hasInterface) exitWith {};

_flag = _this select 0;
_typeX = _this select 1;

switch _typeX do
	{
	case "take":
		{
		removeAllActions _flag;
		_actionX = _flag addAction ["<t>Взять флаг<t> <img image='\A3\ui_f\data\igui\cfg\actions\takeflag_ca.paa' size='1.8' shadow=2 />", RES_fnc_mrkWIN,nil,6,true,true,"","(isPlayer _this) and (_this == _this getVariable ['owner',objNull])",4];
		_flag setUserActionText [_actionX,"Взять флаг","<t size='2'><img image='\A3\ui_f\data\igui\cfg\actions\takeflag_ca.paa'/></t>"];
		};
	case "unit": {_flag addAction ["НАНЯТЬ ботов", {if ([player,300] call RES_fnc_enemyNearCheck) then {hint "You cannot recruit units while there are enemies near you"} else { [] spawn RES_fnc_unit_recruit; };},nil,0,false,true,"","(isPlayer _this) and (_this == _this getVariable ['owner',objNull])",4]};
	case "vehicle": {_flag addAction ["КУПИТЬ машину", {if ([player,300] call RES_fnc_enemyNearCheck) then {hint "You cannot buy vehicles while there are enemies near you"} else { createDialog "vehicle_option"; };},nil,0,false,true,"","(isPlayer _this) and (_this == _this getVariable ['owner',objNull])",4]};
	case "mission": {
		petros addAction ["ЗАПРОС ЗАДАНИЙ", { CreateDialog "mission_menu"; },nil,0,false,true,"","(isPlayer _this) and (_this == _this getVariable ['owner',objNull]) and ([_this] call RES_fnc_isMember) and (petros == leader group petros)",4];
		petros addAction ["МЕНЮ ШТАБА", RES_fnc_dialogHQ,nil,0,false,true,"","(_this == theBoss) and (petros == leader group petros)", 4];
	};
	case "truckX": {actionX = _flag addAction ["<t>ПЕРЕМЕСТИТЬ ящик в машину<t> <img image='\A3\ui_f\data\igui\cfg\actions\unloadVehicle_ca.paa' size='1.8' shadow=2 />", RES_fnc_transfer,nil,6,true,true,"","(isPlayer _this) and (_this == _this getVariable ['owner',objNull])"]};
	case "heal": {
				if (player != _flag) then
					{
					if ([_flag] call RES_fnc_fatalWound) then
						{
						_actionX = _flag addAction [format ["<t>Оживить %1 </t> <img size='1.8' <img image='\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_reviveMedic_ca.paa' />",name _flag], RES_fnc_actionRevive,nil,6,true,true,"","!(_this getVariable [""helping"",false]) and (isNull attachedTo _target)",4];
						_flag setUserActionText [_actionX,format ["Оживить %1",name _flag],"<t size='2'><img image='\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_reviveMedic_ca.paa'/></t>"];
						}
					else
						{
						_actionX = _flag addAction [format ["<t>Оживить %1 </t> <img size='1.8' <img image='\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_revive_ca.paa' />",name _flag], RES_fnc_actionRevive,nil,6,true,true,"","!(_this getVariable [""helping"",false]) and (isNull attachedTo _target)",4];
						_flag setUserActionText [_actionX,format ["Оживить %1",name _flag],"<t size='2'><img image='\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_revive_ca.paa'/></t>"];
						};
					};
				};
	case "heal1":
		{
		if (player != _flag) then
			{
			if ([_flag] call RES_fnc_fatalWound) then
				{
				_actionX = _flag addAction [format ["<t>Оживить %1</t> <img size='1.8' <img image='\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_reviveMedic_ca.paa' />",name _flag], RES_fnc_actionRevive,nil,6,true,false,"","!(_this getVariable [""helping"",false]) and (isNull attachedTo _target)",4];

				_flag setUserActionText [_actionX,format ["Оживить %1",name _flag],"<t size='2'><img image='\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_reviveMedic_ca.paa'/></t>"];
				}
			else
				{
				_actionX = _flag addAction [format ["<t>Оживить %1</t> <img size='1.8' <img image='\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_revive_ca.paa' />",name _flag], RES_fnc_actionRevive,nil,6,true,false,"","!(_this getVariable [""helping"",false]) and (isNull attachedTo _target)",4];
				_flag setUserActionText [_actionX,format ["Оживить %1",name _flag],"<t size='2'><img image='\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_revive_ca.paa'/></t>"];
				};

			_actionX = _flag addAction [format ["<t>Тащить %1</t> <img image='\A3\ui_f\data\igui\cfg\actions\take_ca.paa' size='1.6' shadow=2 />",name _flag], RES_fnc_carry,nil,5,true,false,"","(isPlayer _this) and (_this == _this getVariable ['owner',objNull]) and (isNull attachedTo _target) and !(_this getVariable [""helping"",false]);",4];
			_flag setUserActionText [_actionX,format ["Тащить %1",name _flag],"<t size='2'><img image='\A3\ui_f\data\igui\cfg\actions\take_ca.paa'/></t>"];
			[_flag] call jn_fnc_logistics_addActionLoad;
			};
		};
	case "moveS": {_flag addAction ["Переместить предмет", RES_fnc_moveHQObject,nil,0,false,true,"","(_this == theBoss)"]};
	case "remove":
		{
		if (player == _flag) then
			{
			if (isNil "actionX") then
				{
				removeAllActions _flag;
				if (player == player getVariable ["owner",player]) then {[] call SA_Add_PlayeRES_Tow_Actions};
				}
			else
				{
				_flag removeAction actionX;
				};
			}
		else
			{
			removeAllActions _flag
			};
		};
	case "refugee": {_flag addAction ["<t>Liberate</t> <img image='\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_unbind_ca.paa' size='1.6' shadow=2 />", RES_fnc_liberaterefugee,nil,6,true,true,"","(isPlayer _this) and (_this == _this getVariable ['owner',objNull])",4]};//"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_unbind_ca.paa"
	case "prisonerX": {_flag addAction ["<t>ОСВОБОДИТЬ пленного</t> <img image='\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_unbind_ca.paa' size='1.6' shadow=2 />", RES_fnc_liberatePOW,nil,6,true,true,"","(isPlayer _this) and (_this == _this getVariable ['owner',objNull])",4]};
	case "interrogate": {_flag addAction ["Interrogate", RES_fnc_interrogate,nil,0,false,true,"","(isPlayer _this) and (_this == _this getVariable ['owner',objNull])",4]};
	case "captureX": {_flag addAction ["<t>ОТПУСТИТЬ пленного</t> <img image='\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_unbind_ca.paa' size='1.6' shadow=2 />", RES_fnc_captureX,nil,6,true,true,"","(isPlayer _this) and (_this == _this getVariable ['owner',objNull])",4]};
	case "buildHQ": {_flag addAction ["Поставить ШТАБ тут", RES_fnc_buildHQ,nil,0,false,true,"","(isPlayer _this) and (_this == _this getVariable ['owner',objNull])",4]};
	case "seaport": {_flag addAction ["Купить лодку", { [vehSDKBoat] spawn RES_fnc_addFIAVeh; },nil,0,false,true,"","(isPlayer _this) and (_this == _this getVariable ['owner',objNull])",4]};
	case "steal": {_flag addAction ["Steal Static", RES_fnc_stealStatic,nil,0,false,true,"","(isPlayer _this) and (_this == _this getVariable ['owner',objNull])",4]};
	case "garage":
		{
		if (isMultiplayer) then
			{
			_flag addAction ["ЛИЧНЫЙ гараж", { [GARAGE_PERSONAL] spawn RES_fnc_garage; },nil,0,false,true,"","(isPlayer _this) and (_this == _this getVariable ['owner',objNull])"];
			_flag addAction ["ОБЩИЙ гараж", { [GARAGE_FACTION] spawn RES_fnc_garage; },nil,0,false,true,"","(isPlayer _this) and (_this == _this getVariable ['owner',objNull])"];
			}
		else
			{
			_flag addAction ["ОБЩИЙ гараж", { [GARAGE_FACTION] spawn RES_fnc_garage; },nil,0,false,true,"","(isPlayer _this) and (_this == _this getVariable ['owner',objNull])"]
			};
		};
	case "fireX":
		{
		fireX addAction ["Пропустить 8 часов", RES_fnc_skiptime,nil,0,false,true,"","(_this == theBoss)",4];
		fireX addAction ["Очистить территорию рядом", RES_fnc_clearForest,nil,0,false,true,"","(_this == theBoss)",4];
		fireX addAction ["Убрать туман", { [10,0] remoteExec ["setFog",2]; },nil,0,false,true,"","(_this == theBoss)",4];
		fireX addAction ["Переместить предмет", RES_fnc_moveHQObject,nil,0,false,true,"","(_this == theBoss)"];
		};

	case "SDKFlag":
		{
		removeAllActions _flag;
		_flag addAction ["НАНЯТЬ ботов", {if ([player,300] call RES_fnc_enemyNearCheck) then {hint "You cannot recruit units while there are enemies near you"} else { [] spawn RES_fnc_unit_recruit; };},nil,0,false,true,"","(isPlayer _this) and (_this == _this getVariable ['owner',objNull])",4];
		_flag addAction ["КУПИТЬ машину", {if ([player,300] call RES_fnc_enemyNearCheck) then {hint "You cannot buy vehicles while there are enemies near you"} else { createDialog "vehicle_option"; };},nil,0,false,true,"","(isPlayer _this) and (_this == _this getVariable ['owner',objNull])",4];
		if (isMultiplayer) then
			{
			_flag addAction ["ЛИЧНЫЙ гараж", { [GARAGE_PERSONAL] spawn RES_fnc_garage; },nil,0,false,true,"","(isPlayer _this) and (_this == _this getVariable ['owner',objNull])",4];
			_flag addAction ["ОБЩИЙ гараж", { [GARAGE_FACTION] spawn RES_fnc_garage; },nil,0,false,true,"","(isPlayer _this) and (_this == _this getVariable ['owner',objNull])",4];
			}
		else
			{
			_flag addAction ["ОБЩИЙ гараж", { [GARAGE_FACTION] spawn RES_fnc_garage; },nil,0,false,true,"","(isPlayer _this) and (_this == _this getVariable ['owner',objNull])",4]
			};
		};
	};
