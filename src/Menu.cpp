//
// Created by PC_volt on 23/04/2022.
//

#include "Menu.h"
#include "Address.h"

namespace MeltyLib
{
    Menu &trainingMenu = *reinterpret_cast<Menu *>(ADDR_TRAININGMENU);
    Menu &mainMenu = *reinterpret_cast<Menu *>(ADDR_MAINMENU);
    Menu &optionsMenu = *reinterpret_cast<Menu *>(ADDR_OPTIONSMENU);
}