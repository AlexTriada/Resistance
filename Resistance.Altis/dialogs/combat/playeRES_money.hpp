class playeRES_money {
	idd = -1;
	movingenable = false;

	class controls {

		class HQ_box: BOX {
			idc = -1;
			text = $STR_antistasi_dialogs_generic_box_text;
			x = 0.244979 * safezoneW + safezoneX;
			y = 0.223941 * safezoneH + safezoneY;
			w = 0.445038 * safezoneW;
			h = 0.30 * safezoneH;
		};

		class HQ_frame: RscFrame {
			idc = -1;
			text = "Player and Money Interaction"; //--- ToDo: Localize;
			x = 0.254979 * safezoneW + safezoneX;
			y = 0.233941 * safezoneH + safezoneY;
			w = 0.425038 * safezoneW;
			h = 0.28 * safezoneH;
		};

		class HQ_button_back: RscButton {
			idc = -1;
			text = $STR_antistasi_dialogs_generic_button_back_text;
			x = 0.61 * safezoneW + safezoneX;
			y = 0.251941 * safezoneH + safezoneY;
			w = 0.06 * safezoneW;//0.175015
			h = 0.05 * safezoneH;
			action = "closeDialog 0; createDialog ""radio_comm"";";
		};

		class HQ_button_mortar: RscButton {
			idc = -1;
			text = "Add Server Member"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Use this option to add the player which you are currently looking to the member's list";
			action = "
				if (isMultiplayer) then {
					closeDialog 0;
					[""add""] call RES_fnc_memberAdd;
				} else {
					hint ""This function is MP only"";
				};
			";
		};

		class HQ_button_MG: RscButton {
			idc = -1;
			text = "Remove Server Member"; //--- ToDo: Localize;
			x = 0.272481 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "Use this option to remove the player which you are currently looking to the member's list";
			action = "
				if (isMultiplayer) then {
					closeDialog 0;
					[""remove""] call RES_fnc_memberAdd;
				} else {
					hint ""This function is MP only"";
				};
			";
		};

		class HQ_button_AT: RscButton {
			idc = -1;
			text = "Donate 100 € to player"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.317959 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			action = "[true] call RES_fnc_donateMoney;";
		};

		class HQ_button_AA: RscButton {
			idc = -1;
			text = "Donate 100 € to Faction"; //--- ToDo: Localize;
			x = 0.482498 * safezoneW + safezoneX;
			y = 0.415981 * safezoneH + safezoneY;
			w = 0.175015 * safezoneW;
			h = 0.0560125 * safezoneH;
			tooltip = "It will increase your prestige among your faction";
			action = "[] call RES_fnc_donateMoney;";
		};
	};
};
