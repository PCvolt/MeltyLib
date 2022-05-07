//
// Created by PC_volt on 01/04/2022.
//

#ifndef MELTYLIB_MENU_H
#define MELTYLIB_MENU_H

#include <string>
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

    enum ElementType {
        NORMAL_ELEMENT,
        SELECT_ELEMENT,
        SPACE_ELEMENT,
        FOLDER_ELEMENT,
        EXIT_ELEMENT
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
        char label[16];
        int labelLength;
        int labelMaxLength;
        char pad2[4];
        char name[16];
        int nameLength;
        int nameMaxLength;
        int selectionIndex;
        int selectedItemLabelXOffset;
        char pad4[4];
        SelectItem *selectItemList;
        SelectItem *selectItemListEnd;
        char pad5[16];

        MenuElement(ElementType type) {
            this->textOpacity = 1;

            switch (type) {
                case NORMAL_ELEMENT:
                    this->vftable = (void *) 0x53604C;
                    this->elementType = 1;
                    this->canHover = 1;
                    strcpy_s(this->label, "NORMAL SETTINGS");
                    strcpy_s(this->name, "NORMAL_SETTINGS");
                    this->marginBottom = 18;
                    break;
                case SELECT_ELEMENT:
                    this->vftable = (void *) 0x536654;
                    this->elementType = 1;
                    this->canHover = 1;
                    strcpy_s(this->label, "SELECT SETTINGS");
                    strcpy_s(this->name, "SELECT_SETTINGS");
                    this->marginBottom = 18;
                    break;
                case SPACE_ELEMENT:
                    this->vftable = (void *) 0x536094;
                    this->elementType = 2;
                    this->canHover = 0;
                    this->marginBottom = 8;
                    break;
                case FOLDER_ELEMENT:
                    break;
                case EXIT_ELEMENT:
                    break;
                default:
                    break;
            }

        }
    };

    struct InformationMenu {
        int mode;
        int timeResetOnChange;
        int pad[4];
        char label[24];
        // probably more fields
    };

    struct Menu; // Forward declaration

    struct MenuSet {
        void *vftable;
        Menu *pMenu;
        char pad[56];
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
