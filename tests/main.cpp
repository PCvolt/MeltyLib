#include <iostream>
#include <MeltyLib.h>

#define assert_equal(value1, value2) if ((value1) != (value2)) \
    std::cout << "Assertion failed. File " << __FILE__ \
              << " line " << __LINE__ << " in function " << __FUNCTION__ << ": "\
              << #value1 << " is offset " << value1 << " in the struct but was expected to be " << value2 << "(" << #value2 << ")" << std::endl\

#define check_offset(v, field, expected) assert_equal((int)&v->field - (int)v, expected)

void testObjectsSize()
{
    assert_equal(sizeof(MeltyLib::CharacterObject), 0xAFC);
}

void testCharacterObjectOffsets()
{
    auto *chr = (MeltyLib::CharacterObject *)nullptr;

    check_offset(chr, isInitialized, 0x0);
    check_offset(chr, u_characterAndPlayer, 0x4);
    check_offset(chr, u_paletteAndPlayer, 0x8);
    check_offset(chr, moon, 0xC);

    check_offset(chr, action, 0x10);
    check_offset(chr, animCounter, 0x14);
    check_offset(chr, spriteCounter, 0x18);
    check_offset(chr, animSubcounter, 0x1C);

    check_offset(chr, u_perfect, 0x50);

    check_offset(chr, u_canMove, 0x64);
    check_offset(chr, u_frameCountWeird, 0x68);
    check_offset(chr, u_10IfInHitstun, 0x6C);

    check_offset(chr, u_ExGuardFlag, 0xB0);

    check_offset(chr, health, 0xBC);
    check_offset(chr, redHealth, 0xC0);
    check_offset(chr, guardGauge, 0xC4);

    check_offset(chr, guardState, 0xCC);
    check_offset(chr, timerBeforeGuardRegen, 0xD0);
    check_offset(chr, timerGuardQualityRegen, 0xD4);
    check_offset(chr, guardGaugeQuality, 0xD8);

    check_offset(chr, meter, 0xE0);
    check_offset(chr, heatTime, 0xE4);

    check_offset(chr, u_frameCount, 0xF0);

    check_offset(chr, xPosNext, 0x108);
    check_offset(chr, yPosNext, 0x10C);

    check_offset(chr, xPos, 0x114);
    check_offset(chr, yPos, 0x118);
    check_offset(chr, xVel, 0x11C);
    check_offset(chr, yVel, 0x120);
    check_offset(chr, xAcceleration, 0x124);
    check_offset(chr, yAcceleration, 0x126);

    check_offset(chr, u_deathFlag, 0x177);
    check_offset(chr, u_attackActives, 0x178);

    check_offset(chr, u_timeSpentAirborne, 0x188);

    check_offset(chr, hitstop, 0x1A4);
    check_offset(chr, hitstunCountUp, 0x1A8);
    check_offset(chr, hitstunOnGround, 0x1AC);
    check_offset(chr, u_hitstunFlags, 0x1B0);

    check_offset(chr, pItselfPlus0x4, 0x2CC);

    check_offset(chr, inputDirection, 0x2E8);
    check_offset(chr, inputButtons, 0x2EC);

    check_offset(chr, u_nbCommandsEntered, 0x2F4);

    check_offset(chr, spriteRotation, 0x300);

    check_offset(chr, facingLeftFlag, 0x314);

    check_offset(chr, facingLeftFlag, 0x314);
    check_offset(chr, stanceFlag, 0x318);
    check_offset(chr, pCurrentSequence, 0x31C);
    check_offset(chr, currentTexture, 0x320);
    check_offset(chr, u_attackActives2, 0x324);
    check_offset(chr, pItself, 0x328);

    check_offset(chr, timeSpentInSequence, 0x334);

    check_offset(chr, inputCommandId, 0x3D8);

    check_offset(chr, nbChainedAttacks, 0x3E0);

    check_offset(chr, nbInputsMvt, 0x3E8);
    check_offset(chr, inputsHistoryMvt, 0x3EA);
    check_offset(chr, nbInputsA, 0x4EA);
    check_offset(chr, inputsHistoryA, 0x4EC);
    check_offset(chr, nbInputsB, 0x5EC);
    check_offset(chr, inputsHistoryB, 0x5EE);
    check_offset(chr, nbInputsC, 0x6EE);
    check_offset(chr, inputsHistoryC, 0x6F0);
    check_offset(chr, nbInputsD, 0x7F0);
    check_offset(chr, inputsHistoryD, 0x7F2);
    check_offset(chr, nbInputsABC, 0x8F2);
    check_offset(chr, inputsHistoryABC, 0x8F4);
}

void testComboInfoOffsets()
{
    auto *comboInfo = (MeltyLib::ComboInfo *)nullptr;
    check_offset(comboInfo, totalHits, 0x0);
    check_offset(comboInfo, maxLengthThisReset, 0x4);

    check_offset(comboInfo, maxLength, 0xC);
    check_offset(comboInfo, maxDamage, 0x10);
    check_offset(comboInfo, maxCombo, 0x14);

    check_offset(comboInfo, length, 0x2C);
    check_offset(comboInfo, lengthToo, 0x30);
    check_offset(comboInfo, damage, 0x34);
    check_offset(comboInfo, rawDamage, 0x38);
    check_offset(comboInfo, redDamage, 0x3C);

    check_offset(comboInfo, length2, 0x44);
    check_offset(comboInfo, lengthToo2, 0x48);
    check_offset(comboInfo, damage2, 0x4C);
    check_offset(comboInfo, rawDamage2, 0x50);
    check_offset(comboInfo, redDamage2, 0x54);

    check_offset(comboInfo, firstComboLength, 0x60);
    check_offset(comboInfo, firstComboDamage, 0x64);

    check_offset(comboInfo, correctionValue, 0x6C);
}

void testActionsValues()
{
    using namespace MeltyLib;
    assert_equal(ACTION_IDLE, 0);
    assert_equal(ACTION_5A, 1);
    assert_equal(ACTION_5B, 2);
    assert_equal(ACTION_5C, 3);
    assert_equal(ACTION_2A, 4);
    assert_equal(ACTION_2B, 5);
    assert_equal(ACTION_2C, 6);
    assert_equal(ACTION_jA, 7);
    assert_equal(ACTION_jB, 8);
    assert_equal(ACTION_jC, 9);
    assert_equal(ACTION_WALK, 10);
    assert_equal(ACTION_BACKWALK, 11);
    assert_equal(ACTION_STAND2CROUCH, 12);
    assert_equal(ACTION_CROUCH, 13);
    assert_equal(ACTION_CROUCH2STAND, 14);
    assert_equal(ACTION_STANDBLOCK, 17);
    assert_equal(ACTION_CROUCHBLOCK, 18);
    assert_equal(ACTION_AIRBLOCK, 19);
    assert_equal(ACTION_HIT_AIR, 26);
    assert_equal(ACTION_AIRTECH, 28);
    assert_equal(ACTION_SWEPT, 29);
    assert_equal(ACTION_HIT_LAUNCH, 30);
    assert_equal(ACTION_GROUNDTECH, 31);
    assert_equal(ACTION_WAKEUP_FACEDOWN, 32);
    assert_equal(ACTION_WAKEUP_FACEUP, 33);
    assert_equal(ACTION_j9, 35);
    assert_equal(ACTION_j8, 36);
    assert_equal(ACTION_j7, 37);
    assert_equal(ACTION_dj9, 38);
    assert_equal(ACTION_dj8, 39);
    assert_equal(ACTION_dj7, 40);
    assert_equal(ACTION_AIRDASH, 43);
    assert_equal(ACTION_AIRBACKDASH, 44);
    assert_equal(ACTION_DODGE, 45);
    assert_equal(ACTION_SHIELD_HIGH, 54);
    assert_equal(ACTION_SHIELD_LOW, 55);
    assert_equal(ACTION_sj9, 58);
    assert_equal(ACTION_DASH, 60);
    assert_equal(ACTION_BACKDASH, 61);
    assert_equal(ACTION_SHIELD_BUNKER, 96);
    assert_equal(ACTION_HEAT, 260);
    assert_equal(ACTION_CIRCUIT_SPARK, 262);
    assert_equal(ACTION_AIR_CIRCUIT_SPARK, 263);
    assert_equal(ACTION_AIRTHROW_WHIFF, 271);
    assert_equal(ACTION_AIRTHROW, 273);
    assert_equal(ACTION_THROW_TECH, 280);
    assert_equal(ACTION_THROW_TECH_RECOVERY, 281);
    assert_equal(ACTION_AIR_THROWN, 350);
    assert_equal(HITSTUN_LIGHT_LEANBACK, 900);
    assert_equal(HITSTUN_LIGHT_LEANFORWARD, 901);
    assert_equal(HITSTUN_MEDIUM_LEANBACK, 903);
    assert_equal(HITSTUN_MEDIUM_LEANFORWARD, 904);
    assert_equal(HITSTUN_HEAVY_LEANBACK, 906);
    assert_equal(HITSTUN_HEAVY_LEANFORWARD, 907);
    assert_equal(HITSTUN_HEAVY_LEANANY, 907);
}

int main() {
    testObjectsSize();
    testCharacterObjectOffsets();
    testComboInfoOffsets();
    testActionsValues();
    return 0;
}
