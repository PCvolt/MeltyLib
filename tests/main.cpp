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

void testCharacterObjectOffsets()
{
    auto *chr = (MeltyLib::CharacterObject *)nullptr;
    auto *cso = (MeltyLib::CharacterSubObject *)nullptr;

    check_offset(chr, isInitialized, 0x0);

    check_offset(cso, graphicAssetsIndex, 0x0);
    check_offset(cso, character, 0x1);
    check_offset(cso, u_characterAgain, 0x2);
    check_offset(cso, team, 0x3);
    check_offset(cso, player, 0x4);
    check_offset(cso, palette, 0x6);
    check_offset(cso, moon, 0x8);

    check_offset(cso, action, 0xC);
    check_offset(cso, spriteIndex, 0x10);
    check_offset(cso, nextSpriteIndex, 0x14);
    check_offset(cso, timePerSprite, 0x18);
    check_offset(cso, spriteOrActionChange, 0x1C);

    check_offset(cso, u_perfect, 0x4C);

    check_offset(cso, u_canMove, 0x60);
    check_offset(cso, u_frameCountWeird, 0x64);
    check_offset(cso, u_10IfInHitstun, 0x68);

    check_offset(cso, ExGuardFlag, 0xAC);
    check_offset(cso, timeHoldingBack, 0xB0);

    check_offset(cso, health, 0xB8);
    check_offset(cso, redHealth, 0xBC);
    check_offset(cso, guardGauge, 0xC0);

    check_offset(cso, guardState, 0xC8);
    check_offset(cso, timerBeforeGuardRegen, 0xCC);
    check_offset(cso, timerGuardQualityRegen, 0xD0);
    check_offset(cso, guardGaugeQuality, 0xD4);

    check_offset(cso, meter, 0xDC);
    check_offset(cso, heat, 0xE0);
    check_offset(cso, heatMode, 0xE4);

    check_offset(cso, u_frameCount, 0xEC);

    check_offset(cso, brokenCircuitTimer, 0xFC);

    check_offset(cso, xPosNext, 0x104);
    check_offset(cso, yPosNext, 0x108);

    check_offset(cso, xPos, 0x110);
    check_offset(cso, yPos, 0x114);
    check_offset(cso, xVel, 0x118);
    check_offset(cso, yVel, 0x11C);
    check_offset(cso, xAcceleration, 0x120);
    check_offset(cso, yAcceleration, 0x122);

    check_offset(cso, shieldHeldTime, 0x168);
    check_offset(cso, shieldType, 0x16C);
    check_offset(cso, stopFrames, 0x16E);

    check_offset(cso, u_throwFlag, 0x172);
    check_offset(cso, u_deathFlag, 0x173);
    check_offset(cso, u_activeMeleeAttack, 0x174);

    check_offset(cso, isWhiffing, 0x176);
    check_offset(cso, willDefend, 0x178);
    check_offset(cso, hardBounces, 0x17A);

    check_offset(cso, u_softOTG, 0x17C);
    check_offset(cso, jumpCancel, 0x17D);
    check_offset(cso, u_thrown, 0x17E);

    check_offset(cso, timeNotThrowable, 0x182);
    check_offset(cso, wakeupFlag, 0x183);
    check_offset(cso, prejump, 0x184);
    check_offset(cso, timeSpentAirborne, 0x186);

    check_offset(cso, timeThrown, 0x188);

    check_offset(cso, reversedControlsTimer, 0x196);

    check_offset(cso, hitstop, 0x1A0);
    check_offset(cso, hitstunCountUp, 0x1A4);
    check_offset(cso, hitstunOnGround, 0x1A8);
    check_offset(cso, knockdownFlag, 0x1AC);

    check_offset(cso, pItselfCSO, 0x2C8);

    check_offset(cso, inputDirectionCorrected, 0x2E6);
    check_offset(cso, inputDirectionRaw, 0x2E7);
    check_offset(cso, buttonsJustPressed, 0x2E8);
    check_offset(cso, buttonsPressed, 0x2E9);
    check_offset(cso, macroPressed, 0x2EA);

    check_offset(cso, buttonsReleased, 0x2EC);

    check_offset(cso, teamImmunity, 0x2F0);

    check_offset(cso, u_nbCommandsEntered, 0x2F2);

    check_offset(cso, spriteRotation, 0x2FC);
    check_offset(cso, xScale, 0x300);
    check_offset(cso, yScale, 0x304);
    check_offset(cso, inputEvent, 0x308);

    check_offset(cso, facingLeftFlag, 0x310);
    check_offset(cso, opponentIsLeftToMe, 0x311);
    check_offset(cso, stanceFlag, 0x314);
    check_offset(cso, pCurrentSequence, 0x318);
    check_offset(cso, texture, 0x31C);
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

void testMenuElementOffset()
{
    auto *menuElement = (MeltyLib::MenuElement *)nullptr;

    check_offset(menuElement, vftable, 0x0);
    check_offset(menuElement, elementType, 0x4);
    check_offset(menuElement, isHovered, 0x8);
    check_offset(menuElement, canHover, 0xC);
    check_offset(menuElement, timeHovered, 0x10);
    check_offset(menuElement, timeNotHovered, 0x14);
    check_offset(menuElement, marginBottom, 0x18);
    check_offset(menuElement, textOpacity, 0x1C);

    check_offset(menuElement, label, 0x24);
    check_offset(menuElement, labelLength, 0x34);
    check_offset(menuElement, labelMaxLength, 0x38);

    check_offset(menuElement, name, 0x40);
    check_offset(menuElement, nameLength, 0x50);
    check_offset(menuElement, nameMaxLength, 0x54);
    check_offset(menuElement, selectionIndex, 0x58);
    check_offset(menuElement, selectedItemLabelXOffset, 0x5C);

    check_offset(menuElement, pSelectItemList, 0x64);
    check_offset(menuElement, pSelectItemListEnd, 0x68);
}

void testMenuOffsets()
{
    auto *menu = (MeltyLib::Menu *)nullptr;

    check_offset(menu, vftable, 0x0);
    check_offset(menu, isMenuDisabled, 0x4);
    check_offset(menu, prevIsMenuDisabled, 0x8);

    check_offset(menu, ppMenuSet, 0x10);
    check_offset(menu, currentElementName, 0x24);
    check_offset(menu, currentElementNameLength, 0x34);
    check_offset(menu, currentElementNameMaxLength, 0x38);

    check_offset(menu, yOffset, 0x44);

    check_offset(menu, xOffset, 0x4C);

    check_offset(menu, label, 0x60);
    check_offset(menu, labelLength, 0x70);
    check_offset(menu, labelMaxLength, 0x74);

    check_offset(menu, isRootMenu, 0x7C);
    check_offset(menu, timeOpened, 0x80);
    check_offset(menu, openSubmenuIndex, 0x84);
    check_offset(menu, timeSubmenuOpened, 0x88);
    check_offset(menu, closeAnimProgression, 0x8C);
    check_offset(menu, opacity, 0x90);
    check_offset(menu, progressionRate, 0x94);
    check_offset(menu, degressionRate, 0x98);
    check_offset(menu, isBlurred, 0x9C);

    check_offset(menu, isMenuBackgroundDisplayed, 0xA4);
    check_offset(menu, u_layer, 0xA8);
    check_offset(menu, paragraphMode, 0xAC);

    check_offset(menu, xStretch, 0xB4);
    check_offset(menu, yStretch, 0xB8);
    check_offset(menu, isMenuLit, 0xBC);
    check_offset(menu, dimScreenPercentage, 0xC0);
    check_offset(menu, pYesNoMenu, 0xC4);
    check_offset(menu, pBattleSettingsMenu, 0xC8);
    check_offset(menu, pEnemyStatusMenu, 0xCC);
    check_offset(menu, pTrainingDisplayMenu, 0xD0);
    check_offset(menu, pDummySettingsMenu, 0xD4);
    check_offset(menu, hiddenMenuFlag, 0xD8);
    check_offset(menu, pInformationMenu, 0xDC);
}

void testMenuSetOffsets()
{
    auto *menuSet = (MeltyLib::MenuSet *)nullptr;

    check_offset(menuSet, vftable, 0x0);
    check_offset(menuSet, pMenu, 0x4);

    check_offset(menuSet, currHoveredItemIndex, 0x40);
    check_offset(menuSet, prevHoveredItemIndex, 0x44);

    check_offset(menuSet, pElementsList, 0x4C);
    check_offset(menuSet, pElementsListEnd, 0x50);

    check_offset(menuSet, hasFinishedDrawing, 0x68);
    check_offset(menuSet, timeActive, 0x6C);

    check_offset(menuSet, willClose, 0x74);
}

void testTextureOffsets()
{
    auto *texture = (MeltyLib::Texture *)nullptr;

    check_offset(texture, spriteIndex, 0x2);
    check_offset(texture, u_assetsIndex, 0x3);
    check_offset(texture, xOffset, 0x4);
    check_offset(texture, yOffset, 0x8);
    check_offset(texture, red, 0x18);
    check_offset(texture, green, 0x19);
    check_offset(texture, blue, 0x1A);
    check_offset(texture, xScale, 0x30);
    check_offset(texture, yScale, 0x34);
    check_offset(texture, hurtboxCount, 0x42);
    check_offset(texture, hitboxCount, 0x43);
    check_offset(texture, hurtboxList, 0x50);
    check_offset(texture, hitboxList, 0x54);
}

void testObjectsSize()
{
    assert_equal(sizeof(MeltyLib::CharacterObject), 0xAFC);
}

int main() {
    testObjectsSize();
    testCharacterObjectOffsets();
    testComboInfoOffsets();
    testActionsValues();
    testTextureOffsets();

    testMenuSetOffsets();
    testMenuOffsets();
    testMenuElementOffset();

    return 0;
}
