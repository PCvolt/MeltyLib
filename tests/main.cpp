#include <Windows.h>
#include <conio.h>
#include <tlhelp32.h>
#include <string>
#include <psapi.h>

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
    auto *cso = (MeltyLib::CharacterSubObject *)nullptr;

    check_offset(chr, isInitialized, 0x0);
    check_offset(cso, u_characterAndPlayer, 0x0);
    check_offset(cso, u_paletteAndPlayer, 0x4);
    check_offset(cso, moon, 0x8);

    check_offset(cso, action, 0xC);
    check_offset(cso, animCounter, 0x10);
    check_offset(cso, spriteCounter, 0x14);
    check_offset(cso, animSubcounter, 0x18);

    check_offset(cso, u_perfect, 0x4C);

    check_offset(cso, u_canMove, 0x60);
    check_offset(cso, u_frameCountWeird, 0x64);
    check_offset(cso, u_10IfInHitstun, 0x68);

    check_offset(cso, u_ExGuardFlag, 0xAC);

    check_offset(cso, health, 0xB8);
    check_offset(cso, redHealth, 0xBC);
    check_offset(cso, guardGauge, 0xC0);

    check_offset(cso, guardState, 0xC8);
    check_offset(cso, timerBeforeGuardRegen, 0xCC);
    check_offset(cso, timerGuardQualityRegen, 0xD0);
    check_offset(cso, guardGaugeQuality, 0xD4);

    check_offset(cso, meter, 0xDC);
    check_offset(cso, heatTime, 0xE0);

    check_offset(cso, u_frameCount, 0xEC);

    check_offset(cso, xPosNext, 0x104);
    check_offset(cso, yPosNext, 0x108);

    check_offset(cso, xPos, 0x110);
    check_offset(cso, yPos, 0x114);
    check_offset(cso, xVel, 0x118);
    check_offset(cso, yVel, 0x11C);
    check_offset(cso, xAcceleration, 0x120);
    check_offset(cso, yAcceleration, 0x122);

    check_offset(cso, u_deathFlag, 0x173);
    check_offset(cso, u_attackActives, 0x174);

    check_offset(cso, u_timeSpentAirborne, 0x184);

    check_offset(cso, hitstop, 0x1A0);
    check_offset(cso, hitstunCountUp, 0x1A4);
    check_offset(cso, hitstunOnGround, 0x1A8);
    check_offset(cso, knockdownFlag, 0x1AC);

    check_offset(cso, pItselfCSO, 0x2C8);

    check_offset(cso, inputDirection, 0x2E4);
    check_offset(cso, inputButtons, 0x2E8);

    check_offset(cso, u_nbCommandsEntered, 0x2F0);

    check_offset(cso, spriteRotation, 0x2FC);

    check_offset(cso, inputEvent, 0x308);

    check_offset(cso, facingLeftFlag, 0x310);
    check_offset(cso, stanceFlag, 0x314);
    check_offset(cso, pCurrentSequence, 0x318);
    check_offset(cso, currentTexture, 0x31C);
    check_offset(cso, u_attackActives2, 0x320);
    check_offset(cso, pItselfCO, 0x324);

    check_offset(cso, timeSpentInSequence, 0x330);

    check_offset(cso, inputCommandId, 0x3D4);

    check_offset(cso, nbChainedAttacks, 0x3DC);

    check_offset(cso, nbInputsMvt, 0x3E4);
    check_offset(cso, inputsHistoryMvt, 0x3E6);
    check_offset(cso, nbInputsA, 0x4E6);
    check_offset(cso, inputsHistoryA, 0x4E8);
    check_offset(cso, nbInputsB, 0x5E8);
    check_offset(cso, inputsHistoryB, 0x5EA);
    check_offset(cso, nbInputsC, 0x6EA);
    check_offset(cso, inputsHistoryC, 0x6EC);
    check_offset(cso, nbInputsD, 0x7EC);
    check_offset(cso, inputsHistoryD, 0x7EE);
    check_offset(cso, nbInputsABC, 0x8EE);
    check_offset(cso, inputsHistoryABC, 0x8F0);
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
    assert_equal(ACTION_TURNAROUND, 15);

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
    assert_equal(ACTION_AIRTHROW_ATTEMPT, 271);
    assert_equal(ACTION_AIRTHROW_CONNECT, 273);
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
