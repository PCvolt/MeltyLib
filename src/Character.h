//
// Created by PC_volt on 19/04/2021.
//

#ifndef MELTYLIB_CHARACTER_H
#define MELTYLIB_CHARACTER_H

#include "Action.h"

namespace MeltyLib {
    enum Character : unsigned short {
        SION,
        ARCUEID,
        CIEL,
        AKIHA,
        MAIDS,
        HISUI,
        KOHAKU,
        SHIKI,
        MIYAKO,
        WARACHIA,
        NERO,
        VSION,
        RED_ARCUEID,
        VAKIHA,
        MECH_HISUI,
        NANAYA,
        AKIHA_GIANT, //INVALID CHARACTER
        SATSUKI,
        LEN,
        POWERD_CIEL,
        NECO_ARC,

        AOKO = 22,
        WLEN,

        NAC = 25,

        KOUMA = 28,
        SEIFUKU,
        RIESBYFE,
        ROA,
        OSIRIS, //BOSS
        RYOUGI,
        NECO_MECH,
        KOHA_MECH,

        HIME = 51,

        RANDOM_SELECT = 99
    };

    #pragma deprecated(AKIHA_GIANT)

    //p1 MBAA.exe+155458 (00555130)
    //p2 MBAA.exe+155f54 (00555C2C)
    struct CharacterObject {
        char offset_0x00[0xC];

        // Anim offsets
        short smtg; //0xC short ? pTexture ???
        Action action; //0x10
        int animCounter; //0x14
        int u_SpriteNumber; //0x18
        int animSubCounter; //0x1C
        char offset_0x20[0x9C];

        // Resources offsets
        int yellowLife; //0xBC
        int redLife; //0xC0
        float guardGauge; //0xC4
        int guardState; //0xCC
        int timerBeforeGuardRegen; //0xD0
        int meterAfterHeat; //0xE0

        int heatTimer; //0xE4

        //0xC0
        //0xEC

        // Movement offsets
        int xPosNext; //0x108
        //0x10C

        int xPosCurr; //0x114
        int gravity; //0x118
        int xVel; //0x11C
        int yVel; //0x120

        int hitstop;//0x1A4
        int hitstunGrounded; //0x1AC

        short smtg1; //0x164 assigned at 128
        //0x166
        //0x2CC
        //0x2D4
        //0x2D8

        //0x304 is set at 1 065 353 216
        //0x308 is set at 1 065 353 216
        //0x315
        //0x324 linked to hitboxes
        short smtg2; //0x328
        //0x330
        //0x354
        //0x800

        int currentMeter; //0xF064 probably not part of the character object
    };

    extern CharacterObject &player1;
    extern CharacterObject &player2;
}


#endif //MELTYLIB_CHARACTER_H
