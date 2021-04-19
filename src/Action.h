//
// Created by PC_volt on 19/04/2021.
//

#ifndef MELTYLIB_ACTION_H
#define MELTYLIB_ACTION_H

enum Action : unsigned int {
    ACTION_IDLE,
    ACTION_5A,
    ACTION_5B,
    ACTION_5C,
    ACTION_2A,
    ACTION_2B,
    ACTION_2C,
    ACTION_jA,
    ACTION_jB,
    ACTION_jC,

    ACTION_WALK,
    ACTION_BACKWALK,
    ACTION_STAND2CROUCH,
    ACTION_CROUCH,
    ACTION_CROUCH2STAND,

    ACTION_STANDBLOCK = 17,
    ACTION_CROUCHBLOCK,
    ACTION_AIRBLOCK,

    ACTION_HIT_AIR = 26,
    ACTION_AIRTECH = 28,
    ACTION_SWEPT,
    ACTION_HIT_LAUNCH,
    ACTION_GROUNDTECH,
    ACTION_WAKEUP_FACEDOWN,
    ACTION_WAKEUP_FACEUP,

    ACTION_j9 = 35,
    ACTION_j8,
    ACTION_j7,
    ACTION_dj9,
    ACTION_dj8,
    ACTION_dj7,

    ACTION_AIRDASH = 43,
    ACTION_AIRBACKDASH,
    ACTION_DODGE,

    ACTION_SHIELD_HIGH = 54,
    ACTION_SHIELD_LOW,

    ACTION_sj9 = 58,

    ACTION_DASH = 60,
    ACTION_BACKDASH,

    ACTION_SHIELD_BUNKER = 96,

    ACTION_HEAT = 260,
    ACTION_CIRCUIT_SPARK = 262,
    ACTION_AIR_CIRCUIT_SPARK,

    ACTION_AIRTHROW_WHIFF = 271,
    ACTION_AIRTHROW = 273,
    ACTION_THROW_TECH = 280,
    ACTION_THROW_TECH_RECOVERY,

    ACTION_AIR_THROWN = 350,

    HITSTUN_LIGHT_LEANBACK = 900,
    HITSTUN_LIGHT_LEANFORWARD = 901,
    //902 ?
    HITSTUN_MEDIUM_LEANBACK = 903,
    HITSTUN_MEDIUM_LEANFORWARD = 904,
    // 905 ?
    HITSTUN_HEAVY_LEANBACK = 906,
    HITSTUN_HEAVY_LEANFORWARD = 907,
    HITSTUN_HEAVY_LEANANY = 907
};


#endif //MELTYLIB_ACTION_H
