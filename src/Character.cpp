//
// Created by PC_volt on 19/04/2021.
//

#include "Character.h"
#include "Address.h"

namespace MeltyLib {
    CharacterObject &character1 = *reinterpret_cast<CharacterObject *>(ADDR_CHARACTER_1);
    CharacterObject &character2 = *reinterpret_cast<CharacterObject *>(ADDR_CHARACTER_2);
    CharacterObject &character3 = *reinterpret_cast<CharacterObject *>(ADDR_CHARACTER_3); // Teamed with character1
    CharacterObject &character4 = *reinterpret_cast<CharacterObject *>(ADDR_CHARACTER_4); // Teamed with character2
}