//
// Created by PC_volt on 01/04/2022.
//

#ifndef MELTYLIB_MENU_H
#define MELTYLIB_MENU_H

// 0xE8 or 0xe0 ? size of Menu
// 0x78 size of TrainingMenu
// 0x?? SpaceElement size
// 0x58 NormalElement size
// 0x80 SelectElement size
// 0x70 size of RecordingSlot
// 0x3C SelectedElement size

/*
 * Presented here the simplified version of all the Menu/MenuSet/MenuElement classes
 * */

namespace MeltyLib {
    struct SelectItem {
        int *pRessources; //wrong type
        char label[24];
        int *pEffect; //wrong type
        int behaviourCode;
        // probably more fields
    };

    struct MenuElement {
        void *vftable;
        int elementType;
        int isHovered;
        int canHover;
        int timeHovered;
        int timeNotHovered;
        int marginBottom;
        int textOpacity;
        char pad[4];
        char label[24];
        char pad2[8];
        char name[24];
        int selectionIndex;
        int selectedItemLabelXOffset;
        char pad4[4];
        SelectItem *selectItemList;
        SelectItem *selectItemListEnd;
        char pad5[16];
    };

    struct InformationMenu {
        int mode;
        int timeResetOnChange;
        int pad[4];
        char label[24];
        // probably more fields
    };

    struct MenuSet {
        void *vftable;
        int *pMenu; //(Menu *), but Menu is the one to init MenuSet
        char pad[60];
        int currHoveredItemIndex;
        int prevHoveredItemIndex;
        char pad2[4];
        MenuElement **pElementsList;
        MenuElement **pElementsListEnd;
        char pad3[20];
        int hasFinishedDrawing;
        int timeActive;
        char pad4[4];
        int willClose;
    };

    struct Menu {
        void *vftable;
        int isMenuDisabled;
        int prevIsMenuDisabled;
        char pad[4];
        MenuSet **ppMenuSet;
        char pad2[44];
        int backgroundXOffset;
        int yOffset;
        char pad3[4];
        int xOffset;
        char pad4[16];
        char label[28];
        int isRootMenu;
        int timeOpened;
        int openSubmenuIndex;
        int timeSubmenuOpened;
        float closeAnimProgression;
        float opacity;
        float progressionRate;
        float degressionRate;
        int isBlurred;
        char pad5[4];
        int isMenuBackgroundDisplayed;
        int u_layer;
        int paragraphMode;
        char pad6[4];
        int xStretch;
        int yStretch;
        int isMenuLit;
        float dimScreenPercentage;
        Menu *pYesNoMenu;
        Menu *pBattleSettingsMenu;
        Menu *pEnemyStatusMenu;
        Menu *pTrainingDisplayMenu;
        Menu *pDummySettingsMenu;
        int hiddenMenuFlag;
        InformationMenu *pInformationMenu;
    };

    //extern Menu *&trainingMenu;
    //extern Menu *&mainMenu;
    //extern Menu *&optionsMenu;
}
#endif //MELTYLIB_MENU_H
