//
// Created by PC_volt on 13/05/2022.
//

#ifndef MELTYLIB_TEXTUREMANAGER_H
#define MELTYLIB_TEXTUREMANAGER_H

#include <Windows.h>

struct IDirect3DDevice9;
struct IDirect3DTexture9;

namespace MeltyLib
{
    struct TextureManager {
        /*
        int *loadTexture(int *ret, LPCSTR path, void *width, void *height);
        int *createTextTexture(int *ret, LPCSTR str, struct SWRFont &font, int width, int height, int *realWidth, int *realHeight);
        void *remove(int id);
        void setTexture(int id, int stage);
        void getSize(int *w, int *h);
        IDirect3DTexture9 **toIDirect3DTexture9Array();
        IDirect3DTexture9 **allocate(int *handle);
        void deallocate(int handle);

        int *loadSound(int *ret, LPCSTR path);
        void playSound(int id);
         */
    };

    extern TextureManager &textureMgr;
    extern IDirect3DDevice9 *(&pd3dDev);
}

#endif //MELTYLIB_TEXTUREMANAGER_H
