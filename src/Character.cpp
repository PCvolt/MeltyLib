//
// Created by PC_volt on 19/04/2021.
//

#include "Character.h"
#include "Address.h"

namespace MeltyLib
{
    CharacterObject &player1 = *reinterpret_cast<CharacterObject *>(ADDR_PLAYER_1);
    CharacterObject &player2 = *reinterpret_cast<CharacterObject *>(ADDR_PLAYER_2);
}