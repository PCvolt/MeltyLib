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
        float textOpacity;
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
        SelectItem *pSelectItemList;
        SelectItem *pSelectItemListEnd;
        char pad5[16];

        void InitNormalElement(const char *label, const char *name)
        {
            this->vftable = (void *) 0x53604C;
            this->elementType = 1;
            this->isHovered = 0;
            this->canHover = 1;
            strcpy_s(this->label, label);
            this->labelLength = 0;
            this->labelMaxLength = 15;
            strcpy_s(this->name, name);
            this->nameLength = 0;
            this->nameMaxLength = 15;
            this->marginBottom = 18;
        }

        MenuElement(ElementType type, const char *label, const char *name) {
            this->textOpacity = 1;
            this->timeHovered = 0;
            this->timeNotHovered = 999999;
            this->labelMaxLength = 15; //check how menu element is init and mimic it
            this->nameMaxLength = 15;

            switch (type) {
                case NORMAL_ELEMENT:
                    InitNormalElement(label, name);
                    break;
                case SELECT_ELEMENT:
                    InitNormalElement(label, name);
                    this->vftable = (void *) 0x536654;
                    this->selectedItemLabelXOffset = 128;
                    this->selectionIndex = 0;
                    this->pSelectItemList = 0;
                    this->pSelectItemListEnd = 0;
                    break;
                case SPACE_ELEMENT:
                    InitNormalElement("", "");
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
        char pad1[16];
        char currentElementName[16]; //How does it deal with longer names? It shows 32 as Max length
        int currentElementNameLength;
        int currentElementNameMaxLength;
        char pad2[8];
        int yOffset;
        char pad3[4];
        int xOffset;
        char pad4[16];
        char label[16];
        int labelLength;
        int labelMaxLength;
        char pad5[4];
        int isRootMenu;
        int timeOpened;
        int openSubmenuIndex;
        int timeSubmenuOpened;
        float closeAnimProgression;
        float opacity;
        float progressionRate;
        float degressionRate;
        int isBlurred;
        char pad6[4];
        int isMenuBackgroundDisplayed;
        int u_layer;
        int paragraphMode;
        char pad7[4];
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

        Menu()
        {
            this->vftable = (void *) 0x53d3c0; //base menu, changes for all inherited menu class
            this->ppMenuSet = 0;
            this->isMenuDisabled = 0;

            this->currentElementName[0] = '\0';
            this->currentElementNameLength = 0;
            this->currentElementNameMaxLength = 15;
            this->xOffset = 340; //266 in training menu
            this->label[0] = '\0';
            this->labelLength = 0;
            this->labelMaxLength = 15;

            this->u_layer = 752; //figure what this is
            this->isRootMenu = 0;
            this->timeOpened = 0;
            this->openSubmenuIndex = 0;
            this->timeSubmenuOpened = 0;

            this->closeAnimProgression = 0;
            this->opacity = 1;
            this->progressionRate = 0.06250000;
            this->degressionRate = -0.06250000;
            this->isBlurred = 1;
            this->isMenuBackgroundDisplayed = 1;
            this->paragraphMode = 0;
            this->xStretch = 16;
            this->yStretch = 16;

            this->isMenuLit = 1;
            this->dimScreenPercentage = 0;
        }
    };

    //extern Menu *&trainingMenu;
    //extern Menu *&mainMenu;
    //extern Menu *&optionsMenu;
}
#endif //MELTYLIB_MENU_H
