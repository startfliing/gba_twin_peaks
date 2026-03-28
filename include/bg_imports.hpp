#ifndef __BG_IMPORTS__
#define __BG_IMPORTS__

#include "bird.h"
#include "millExterior.h"
#include "mill1.h"
#include "mill2.h"
#include "twinpeaks.h"
#include "waterfall.h"
#include "river.h"
#include "created.h"
#include "tp_font.h"

#include "tonc.h"

struct BG_IMPORT{
    const void* Pal;
    const u16 PalLen;
    const void* Tiles;
    const u16 TilesLen;
    const void* Map;
    const u16 MapLen;
};

BG_IMPORT bgImports[] = {
    {
        birdPal,
        birdPalLen,
        birdTiles,
        birdTilesLen,
        birdMap,
        birdMapLen,
    },
    {
        millExteriorPal,
        millExteriorPalLen,
        millExteriorTiles,
        millExteriorTilesLen,
        millExteriorMap,
        millExteriorMapLen,
    },
    {
        mill1Pal,
        mill1PalLen,
        mill1Tiles,
        mill1TilesLen,
        mill1Map,
        mill1MapLen,
    },
    {
        mill2Pal,
        mill2PalLen,
        mill2Tiles,
        mill2TilesLen,
        mill2Map,
        mill2MapLen,
    },
    {
        twinpeaksPal,
        twinpeaksPalLen,
        twinpeaksTiles,
        twinpeaksTilesLen,
        twinpeaksMap,
        twinpeaksMapLen,
    },
    {
        waterfallPal,
        waterfallPalLen,
        waterfallTiles,
        waterfallTilesLen,
        waterfallMap,
        waterfallMapLen,
    },
    {
        riverPal,
        riverPalLen,
        riverTiles,
        riverTilesLen,
        riverMap,
        riverMapLen,
    },
    {
        createdPal,
        createdPalLen,
        createdTiles,
        createdTilesLen,
        createdMap,
        createdMapLen,
    }
};




#endif