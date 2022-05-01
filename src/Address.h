//
// Created by PC_volt on 19/04/2021.
//

#ifndef MELTYLIB_ADDRESS_H
#define MELTYLIB_ADDRESS_H

namespace MeltyLib
{
    enum MenuIndex {
        UNK = 25, //ref at 0x478657
        PRACTICE = 60,
        OPTIONS = 84,
        RANKINGS = 96,
        MAIN = 108,
        REPLAYS = 216,
        NETWORK = 240
    };

    enum SceneIndex {
        BATTLE_SCENE = 1,
        START_SCREEN_SCENE = 2,
        LOGO_SCREEN_SCENE = 3,
        WIN_SCREEN8SCENE = 5,
        VERSUS_SCREEN_SCENE = 8,
        ARCADE_DIALOGUE_SCENE = 9,
        NEXT_STAGE_SCENE = 10,
        RANKINGS_SCENE = 11,
        OPTIONS_SCENE = 12,
        VERSUS_INTRO = 13,
        CHARACTER_SELECT_SCENE = 20,
        MAIN_MENU_SCENE = 25,
        REPLAYS_SCENE = 26,
        NETWORK_SCENE = 100
    };

    enum BattleMode {
        VS_PLAYER = 0x1,
        ARCADE = 0x10,
        PLAYER_VS_CPU = 0x11,
        CPU_VS_CPU = 0x12,
        UNKNOWN = 0x30,
        UNKNOWN2 = 0x100,
        UNKNOWN3 = 0x200,
        PRACTICE_MODE = 0x1010
    };

    enum FunctionAddress {
        ADDR_UPDATE_BATTLESCENE_CALL = 0x4235D1,
        ADDR_UPDATEGAME_CALL = 0x4337AB,
        ADDR_DRAW_BATTLESCENE_CALL = 0x4235D7,

                /* Draw Function Calls */
        ADDR_DRAW_CHARACTERS_CALL = 0x42388D,
        ADDR_DRAW_CHARACTERSHADOWS_CALL = 0x41B47C,
        ADDR_DRAW_EFFECTS1_CALL = 0x423892,
        ADDR_DRAW_EFFECTS2_CALL = 0x423897,
        ADDR_DRAW_HUDTEXT_CALL = 0x42389C,
        ADDR_DRAW_BATTLEBACKGROUND_CALL = 0x4238C0,

        ADDR_DRAW_BATTLEBHUD_CALL = 0x4238A6, //Crashes if NOPed
        ADDR_DRAW_RESOURCESHUD_CALL = 0x42485B,
        ADDR_DRAW_CHARACTERRESOURCESTEXT_CALL = 0x4249F7,
        ADDR_DRAW_CHARACTERRESOURCESTEXT1_CALL = 0x424A60,
        ADDR_DRAW_CHARACTERRESOURCES_CALL = 0x424ABC, //Call to DrawTexture()
        ADDR_DRAW_CHARACTERRESOURCES1_CALL = 0x4249CD, //Call to DrawTexture()
        ADDR_DRAW_CHARACTERRESOURCES2_CALL = 0x424B9D, //Call to DrawTexture()

                /* Draw Functions */
        ADDR_DRAW_TEXTURE = 0x415580,
        ADDR_DRAW_CHARACTERRESOURCESTEXT = 0x41DBF0,
        ADDR_DRAW_CHARACTERS = 0x46E2E0,
        ADDR_DRAW_CHARACTERSHADOWS = 0x41A390, //Function is not specific to shadows
        ADDR_DRAW_EFFECTS1 = 0x4540C0,
        ADDR_DRAW_EFFECTS2 = 0x458E80,
        ADDR_DRAW_HUDTEXT = 0x476C70,
        ADDR_DRAW_RESOURCESHUD = 0x424DF0,
        ADDR_DRAW_BATTLEBHUD = 0x424100,
        ADDR_DRAW_BATTLEBACKGROUND = 0x4B9540,

        /* Menu Calls */
        ADDR_INIT_TRAININGMENU_CALL = 0x47817A
    };

    enum Address {
        ADDR_CHARACTER_1 = 0x555130,
        ADDR_CHARACTER_2 = 0x555C2C,
        ADDR_CHARACTER_3 = 0x556728,
        ADDR_CHARACTER_4 = 0x557224,
        //0xDC gap between these two
        ADDR_COMBO_INFO = 0x557DFC,

        ADDR_CAMERA_POS_COMPUTE = 0x44ba40,
        ADDR_CAMERA_ZOOM_COMPUTE = 0x44bcb0,

        ADDR_WORLD_TIMER = 0x55D1D4,
        ADDR_PAUSE_FLAG = 0x55d203,

        ADDR_ROUND_TIMER = 0x562A3C,
        ADDR_REAL_TIMER = 0x562A40,
        //0x562A58
        //0x562A4C
        //0x562A6F
        ADDR_BATTLEMODE = 0x562A74,

        ADDR_NEWSCENEFLAG = 0x55DEC3,
        ADDR_CAMERA_X = 0x55DEC4,
        ADDR_CAMERA_Y = 0x55DEC8,
        ADDR_CAMERA_Z = 0x55DECC,

        ADDR_CAMERA_NEXT_X = 0x555124,
        ADDR_CAMERA_NEXT_Y = 0x555128,
        ADDR_CAMERA_DIFF_X = 0x5585E8,
        ADDR_CAMERA_DIFF_Y = 0x5585EC,
        ADDR_CAMERA_DIFF_Z = 0x5585F0,
        ADDR_COUNTERHIT_MODE = 0x77C210, //0 to 4

        ADDR_SELECTED_STAGE = 0x74FD98,
        ADDR_PREVIOUS_SELECTED_STAGE = 0x76E988,

        ADDR_HUD_NOT_DISPLAYED = 0x5545f1,

        ADDR_TIMER_DISPLAY_REVERSEBEAT_C1 = 0x55531C,
        ADDR_TIMER_DISPLAY_REVERSEBEAT_C2 = 0x555E18, //0xAFC difference
        ADDR_TIMER_DISPLAY_COUNTERHIT_C1 = 0x557FBC,
        ADDR_TIMER_DISPLAY_COUNTERHIT_C2 = 0x5581C8,
        ADDR_CAMERA_FOLLOW_MODE = 0x559546, //255 = normal, 0/1 = no care for sprize size, 2 = no care for characters

        ADDR_MENU = 0x74D7FC,
        ADDR_CAMERA_SCALE_Y = 0x77C06C,
        ADDR_CAMERA_SCALE_Z = 0x77C094,

        ADDR_CAMERA_SCALE_X = 0x77C158,
        ADDR_D3DX9_DEVICE = 0x76e7d4


        //MENU
        // 0x74d7fc + 10] + 0] + 0] = pTrainingMenu
        // 0x76E6D4 + 10] + 0] + 0] = pMainMenu
        // 0x76E98C + 10] + 0] + 0] = OptionsMenu
    };
}

#endif //MELTYLIB_ADDRESS_H
