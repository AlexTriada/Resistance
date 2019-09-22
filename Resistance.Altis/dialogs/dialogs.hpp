#include "defines.hpp"

//  ██████╗ ██████╗ ███╗   ███╗██████╗  █████╗ ████████╗
// ██╔════╝██╔═══██╗████╗ ████║██╔══██╗██╔══██╗╚══██╔══╝
// ██║     ██║   ██║██╔████╔██║██████╔╝███████║   ██║
// ██║     ██║   ██║██║╚██╔╝██║██╔══██╗██╔══██║   ██║
// ╚██████╗╚██████╔╝██║ ╚═╝ ██║██████╔╝██║  ██║   ██║
//  ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚═════╝ ╚═╝  ╚═╝   ╚═╝

#include "combat\radio_comm.hpp"
#include "combat\vehicle_manager.hpp"
#include "combat\veh_query.hpp"
#include "combat\squad_manager.hpp"
#include "combat\AI_management.hpp"
#include "combat\commandeRES_comm.hpp"
#include "combat\carpet_bombing.hpp"
#include "combat\dismiss_menu.hpp"
#include "combat\construction_menu.hpp"
#include "combat\bunkeRES_menu.hpp"
#include "combat\squad_recruit.hpp"
#include "combat\playeRES_money.hpp"
#include "combat\garage_sell.hpp"
#include "combat\garage_check.hpp"
#include "combat\bombing.hpp"
#include "combat\mortaRES_type.hpp"
#include "combat\rounds_number.hpp"
#include "combat\strike_type.hpp"
#include "combat\NATO_player.hpp"
#include "combat\mbt_type.hpp"
#include "combat\squad_options.hpp"
#include "combat\diff_menu.hpp"

//  ██████╗ ██████╗ ███╗   ███╗███╗   ███╗ ██████╗ ███╗   ██╗
// ██╔════╝██╔═══██╗████╗ ████║████╗ ████║██╔═══██╗████╗  ██║
// ██║     ██║   ██║██╔████╔██║██╔████╔██║██║   ██║██╔██╗ ██║
// ██║     ██║   ██║██║╚██╔╝██║██║╚██╔╝██║██║   ██║██║╚██╗██║
// ╚██████╗╚██████╔╝██║ ╚═╝ ██║██║ ╚═╝ ██║╚██████╔╝██║ ╚████║
//  ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═══╝

#include "common\first_load.hpp"
#include "common\mission_menu.hpp"
#include "common\gameMode_menu.hpp"

// ███████╗██╗      █████╗  ██████╗
// ██╔════╝██║     ██╔══██╗██╔════╝
// █████╗  ██║     ███████║██║  ███╗
// ██╔══╝  ██║     ██╔══██║██║   ██║
// ██║     ███████╗██║  ██║╚██████╔╝
// ╚═╝     ╚══════╝╚═╝  ╚═╝ ╚═════╝

#include "flag\vehicle_option.hpp"
#include "flag\mil_vehicle.hpp"
#include "flag\civ_vehicle.hpp"
#include "flag\unit_recruit.hpp"

// ██╗  ██╗ ██████╗
// ██║  ██║██╔═══██╗
// ███████║██║   ██║
// ██╔══██║██║▄▄ ██║
// ██║  ██║╚██████╔╝
// ╚═╝  ╚═╝ ╚══▀▀═╝

#include "hq\hq_menu.hpp"
#include "hq\build_menu.hpp"
#include "hq\garrison_recruit.hpp"
#include "hq\minebuild_menu.hpp"

// ███╗   ███╗ █████╗ ██████╗
// ████╗ ████║██╔══██╗██╔══██╗
// ██╔████╔██║███████║██████╔╝
// ██║╚██╔╝██║██╔══██║██╔═══╝
// ██║ ╚═╝ ██║██║  ██║██║
// ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝

#include "map\game_option.hpp"
#include "map\fps_limiter.hpp"
#include "map\spawn_config.hpp"
#include "map\civ_config.hpp"
