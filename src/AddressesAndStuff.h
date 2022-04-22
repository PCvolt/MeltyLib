//
// Created by PC_volt on 19/04/2021.
//

#ifndef UNTITLED_ADDRESSESANDSTUFF_H
#define UNTITLED_ADDRESSESANDSTUFF_H

#endif //UNTITLED_ADDRESSESANDSTUFF_H


/*
CSceneBattle 0x535BD4
CSceneCharaSelect 0x535C50

CGAME_MENU_ELEMENT, CGAME_MENU_NORMALELEMENT, CGAME_MENU_SELECTELEMENT, CGAME_MENU_SPACEELEMENT, CGAME_MENU_FOLDERELEMENT, CGAME_MENU_EXITELEMENT
CPAUSEMENU: NORMAL_ELEMENT, SELECT_ELEMENT, SPACE_ELEMENT, FOLDER_ELEMENT, EXIT_ELEMENT

in_EAX + 0x324 sprite ?

 462780: noop this function to get the funny results

 67bde8

 451720 = practice mode ?

 0054EEE8 game mode (1 practice mode, 20 chara select, (4 bytes)
 0074D900 moon selector (4 bytes)
 0074D904 color selector (4 bytes)

 0055D208 slowdown timer (2 bytes)
 0055D1D4 world timer (4 bytes)
 00562A40 real timer (4 bytes)


 0055D203 pause flag (byte)
 00562A64 training mode paused (4 bytes)
 0x774974 GameState pointer (4 bytes)
 0x767440 menu state counter (4 bytes)

 54D048

 54EB70: zoom 1
 54EB74: zoom 2
 54EB78: scale
 564B14: camera X
 564B18: camera Y

 55D20B: intro state (byte)
 563948: outro state

 - Frame advantage
 - Hitbox viewer without slowdown
 - Macro
 - If the macro starts by a jump, the dummy will always jump
 - Fix dummy "block first attack"
 - Winning in training mode make you lose any control


 435c878
*/


/*
Hime initializes a partner (Arcueid) just for her loss animation.

 SHIELD BEHAVIOUR
 check c-arc 2[D] not 60F

 C moon standing: 12% (0.2% per frame: 60F)
 H moons: 0%
 F moon: 25% (1% per frame: 25F)

 C arc:
 - 2D: 2% 10F
 - dash 2D: 4.4% 22F

 F arc: 2D 10% 10F
 */