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

    struct InputsHistory {
        bool isPressed;
        short duration;
    };


    struct CharacterObject { //size: 0xAFC
        int isInitialized; //0x00
        int u_characterAndPlayer;
        int u_paletteAndPlayer;
        int moon;
        Action action;
        int animCounter;
        int spriteCounter;
        int animSubcounter; //0x1C
        char pad1[48];

        int u_perfect; //0x50
        char pad2[16];

        int u_canMove; //0x64
        int u_frameCountWeird;
        int u_10IfInHitstun; //0x6C
        char pad3[64];

        int u_ExGuardFlag; //0xB0
        char pad4[8];

        // Resources offsets
        int health; //0xBC
        int redHealth; //0xC0
        float guardGauge; //0xC4 //1: normal, 2: broken
        char pad5[4];

        int guardState; //0xCC
        int timerBeforeGuardRegen;
        int timerGuardQualityRegen;
        float guardGaugeQuality; //0xD8
        char pad6[4];

        int meter; //0xE0
        int heatTime; //0xE4
        char pad7[8];

        int u_frameCount; //F0
        char pad8[20];

        // Movement offsets
        int xPosNext; //0x108
        int yPosNext; //0x10C
        char pad9[4];
        int xPos; //0x114
        int yPos;
        int xVel;
        int yVel;
        short xAcceleration;
        short yAcceleration; //0x126
        char pad10[79];

        char u_deathFlag; //0x177
        int u_attackActives; //0x178
        char pad11[12];

        int u_timeSpentAirborne; //0x188 hex
        char pad12[24];

        int hitstop;//0x1A4
        int hitstunCountUp; //0x1A8
        int hitstunOnGround; //0x1AC
        int u_hitstunFlags; //0x1B0
        char pad13[280];

        CharacterObject *pItselfPlus0x4; //0x2CC
        char pad14[24];

        int inputDirection; //0x2E8 hex
        int inputButtons; //0x2EC hex
        char pad15[4];
        int u_nbCommandsEntered; //0x2F4
        char pad16[8];

        int spriteRotation; //0x300 type?
        char pad17[8];

        short inputEvent; //0x30C
        char pad174[6];
        char facingLeftFlag; //0x314
        char pad175[3];
        int stanceFlag; //0x318 type?
        int *pCurrentSequence; //0x31C type?
        int *currentTexture; //0x320 type?
        int u_attackActives2; //0x324
        CharacterObject *pItself; //0x328
        char pad18[8];

        int timeSpentInSequence; //0x334
        char pad19[160];

        int inputCommandId; //0x3D8
        char pad195[4];

        int nbChainedAttacks; //0x3E0
        char pad20[4];

        short nbInputsMvt; //0x3E8
        InputsHistory inputsHistoryMvt[64]; //0x3EA
        short nbInputsA; //0x4EA
        InputsHistory inputsHistoryA[64]; //0x4EC
        short nbInputsB; //0x5EC
        InputsHistory inputsHistoryB[64]; //0ex5EE
        short nbInputsC; //0x6EE
        InputsHistory inputsHistoryC[64]; //0x6F0
        short nbInputsD; //0x7F0
        InputsHistory inputsHistoryD[64]; //0x7F2
        short nbInputsABC; //0x8F2
        InputsHistory inputsHistoryABC[64]; //0x8F4
        char padEnd[264]; //0xAF8 - 0x9F4
    };

    extern CharacterObject &character1;
    extern CharacterObject &character2;
    extern CharacterObject &character3;
    extern CharacterObject &character4;
}


#endif //MELTYLIB_CHARACTER_H
