//
// Created by PC_volt on 07/05/2021.
//

#ifndef MELTYLIB_COMBOINFO_H
#define MELTYLIB_COMBOINFO_H

namespace MeltyLib {
    struct ComboInfo { //size: 0x???
        int totalHits;
        int maxLengthThisReset;
        char pad1[4];

        int maxLength; //0xC
        int maxDamage;
        int maxCombo; //0x14
        char pad2[20];

        int length; //0x2C
        int lengthToo;
        int damage;
        int rawDamage;
        int redDamage; //0x3C
        char pad3[4];

        int length2; //0x44
        int lengthToo2;
        int damage2;
        int rawDamage2;
        int redDamage2; //0x54
        char pad4[8];

        int firstComboLength;//0x60
        int firstComboDamage;
        char pad5[4];
        int correctionValue;
    };

    extern ComboInfo &comboInfo;
}

#endif //MELTYLIB_COMBOINFO_H
