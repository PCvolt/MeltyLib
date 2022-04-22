//
// Created by PC_volt on 01/04/2022.
//

#ifndef MELTYLIB_CPAUSEMENU_NORMALELEMENT_H
#define MELTYLIB_CPAUSEMENU_NORMALELEMENT_H

// 0xE8 size of GameMenuManager of TrainingMenu
// 0x78 size of TrainingMenu
// 0x?? SpaceElement size
// 0x58 NormalElement size
// 0x80 SelectElement size
// 0x70 size of RecordingSlot
// 0x3C SelectedElement size

// 0x534f8A for spaceElement
/*
 * 53604C is the class address from which it does new (NormalElement)
 *
 * */
struct CPauseMenu_NormalElement
{
    int* pDestructorFct();
    int elementType;
    int isHovered;
    int canHover;
    int timeHovered;
    int timeNotHovered;
    int marginBottom;
    int textOpacity;
    char pad[4];
    char label[16];
    char pad2[16];
    char name[16];
    char pad3[8];
    int selectionIndex;
};

#endif //MELTYLIB_CPAUSEMENU_NORMALELEMENT_H
