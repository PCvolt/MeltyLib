//
// Created by PC_volt on 01/04/2022.
//

#ifndef MELTYLIB_CPAUSEMENU_NORMALELEMENT_H
#define MELTYLIB_CPAUSEMENU_NORMALELEMENT_H

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
    char displayedName[16];
    char pad2[16];
    char name[16];
};

#endif //MELTYLIB_CPAUSEMENU_NORMALELEMENT_H
