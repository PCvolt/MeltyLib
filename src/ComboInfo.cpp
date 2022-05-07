//
// Created by PC_volt on 07/05/2021.
//

#include "ComboInfo.h"
#include "Address.h"

namespace MeltyLib {
    ComboInfo &comboInfo = *reinterpret_cast<ComboInfo *>(ADDR_COMBO_INFO);
}