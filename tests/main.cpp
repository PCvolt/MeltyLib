#include <iostream>
#include <MeltyLib.h>

#define assert_equal(value1, value2) if ((value1) != (value2)) \
    std::cout << "Assertion failed. File " << __FILE__ \
              << " line " << __LINE__ << " in function " << __FUNCTION__ << ": "\
              << #value1 << " is " << value1 << " but was expected to be " << value2 << "(" << #value2 << ")" << std::endl\

#define check_offset(v, field, expected) assert_equal((int)&v->field - (int)v, expected)

void testCharacterObjectOffsets()
{
    auto *chr = (MeltyLib::CharacterObject *)nullptr;

    check_offset(chr, offset_0x20, 0x20);
    check_offset(chr, offset_0x00, 0);
    check_offset(chr, smtg, 0xC);
    check_offset(chr, action, 0x10);
    check_offset(chr, animCounter, 0x14);
    check_offset(chr, u_SpriteNumber, 0x18);
    check_offset(chr, animSubCounter, 0x1C);
    check_offset(chr, yellowLife, 0xBC);
    check_offset(chr, redLife, 0xC0);
    check_offset(chr, guardGauge, 0xC4);
    check_offset(chr, guardState, 0xCC);
    check_offset(chr, timerBeforeGuardRegen, 0xD0);
    check_offset(chr, meterAfterHeat, 0xE0);
    check_offset(chr, heatTimer, 0xE4);
    check_offset(chr, xPosNext, 0x108);
    check_offset(chr, xPosCurr, 0x114);
    check_offset(chr, gravity, 0x118);
    check_offset(chr, xVel, 0x11C);
    check_offset(chr, yVel, 0x120);
    check_offset(chr, hitstop, 0x1A4);
    check_offset(chr, hitstunGrounded, 0x1AC);
    check_offset(chr, smtg1, 0x164);
    check_offset(chr, smtg2, 0x328);
    check_offset(chr, currentMeter, 0xF064);
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
    testCharacterObjectOffsets();
    testActionsValues();
    return 0;
}
