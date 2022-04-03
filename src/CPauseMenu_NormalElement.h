//
// Created by PC_volt on 01/04/2022.
//

#ifndef MELTYLIB_CPAUSEMENU_NORMALELEMENT_H
#define MELTYLIB_CPAUSEMENU_NORMALELEMENT_H

struct CPauseMenu_NormalElement //Size: 0x60
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
    char pad[8];
    int selectionIndex;
};

#endif //MELTYLIB_CPAUSEMENU_NORMALELEMENT_H
