//
// Created by PC_volt on 13/05/2022.
//
#include "Address.h"
#include "TextureManager.h"

namespace MeltyLib
{
    IDirect3DDevice9 *(&pd3dDev) = *reinterpret_cast<IDirect3DDevice9 **>(ADDR_D3D9_DEVICE);
}