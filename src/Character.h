//
// Created by PC_volt on 19/04/2021.
//

#ifndef MELTYLIB_CHARACTER_H
#define MELTYLIB_CHARACTER_H

#include "Action.h"

namespace MeltyLib {
    enum HeatMode : unsigned short {
        NORMAL,
        HEAT,
        MAX,
        BLODDHEAT,
        UNKNOWN,
        UNLIMITED
    };

#pragma deprecated(UNKNOWN)

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
        short buttonPressed;
        short duration;
    };


    struct CharacterSubObject { //size: 0xAFC - 0x4 (every member found is offset by 0x4, due to CharObj being a nested struct)
        //int isInitialized; //0x00
        char graphicAssetsIndex;
        char character;
        char u_characterAgain;
        char team;
        char player;
        char pad[1];
        short palette;
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

        int ExGuardFlag; //0xB0
        int timeHoldingBack;
        char pad4[4];

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
        int heat; //0xE4
        int heatMode; //0xE8
        char pad7[4];

        int u_frameCount; //0xF0
        char pad8[12];
        short brokenCircuitTimer; //0x100
        char pad85[6];

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
        char pad10[68];

        char shieldHeldTime; //0x16C
        char pad101[3];
        char shieldType; //0x170
        char pad102[1];
        short stopFrames; //0x172
        char pad103[2];

        char u_throwFlag; //0x176
        char u_deathFlag; //0x177
        char u_activeMeleeAttack; //0x178
        char pad11[1];
        char isWhiffing; //0x17A
        char pad111[1];
        char willDefend; //0x17C
        char pad112[1];
        char hardBounces; //0x17E
        char pad113[1];
        char u_softOTG; //0x180
        char jumpCancel; //0x181
        char u_thrown; //0x182
        char pad114[3];

        char timeNotThrowable; //0x186
        char wakeupFlag; //0x187 //not reliable on crossups
        char prejump; //0x188
        char pad115[1];
        char timeSpentAirborne; //0x18A
        char pad116[1];
        char timeThrown; //0x18C
        char pad12[12];

        short reversedControlsTimer; //0x19A
        short unknownTimer;
        char pad121[6];

        int hitstop;//0x1A4
        int hitstunCountUp; //0x1A8
        int hitstunOnGround; //0x1AC
        int knockdownFlag; //0x1B0
        char pad125;
        char u_hitstunFlag2;
        char pad13[278];

        CharacterSubObject *pItselfCSO; //0x2CC
        char pad14[26];

        char inputDirectionCorrected; //0x2EA
        char inputDirectionRaw; //0x2EB
        char buttonsJustPressed; //0x2EC
        char buttonsPressed; //0x2ED
        char macroPressed; //0x2EE
        char pad141[1];
        int buttonsReleased; //0x2F0
        char teamImmunity; //0x2F4
        char pad15[1];
        short u_nbCommandsEntered; //0x2F6
        char pad16[8];

        int spriteRotation; //0x300
        int xScale; //0x304
        int yScale; //0x308
        short inputEvent; //0x30C
        char pad174[6];
        char facingLeftFlag; //0x314
        char opponentIsLeftToMe; //0x315
        char pad175[2];
        int stanceFlag; //0x318 type?
        int *pCurrentSequence; //0x31C type?
        int *currentTexture; //0x320 type?
        int u_attackActives2; //0x324
        struct CharacterObject *pItselfCO; //0x328
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

    struct CharacterObject
    {
        int isInitialized; //0x00
        CharacterSubObject CSO;
    };

    extern CharacterObject &character1;
    extern CharacterObject &character2;
    extern CharacterObject &character3;
    extern CharacterObject &character4;
}


#endif //MELTYLIB_CHARACTER_H
