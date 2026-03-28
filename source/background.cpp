#include "tonc.h"
#include "background.hpp"

#include "bg_imports.hpp"

#include "global.hpp"

/* Backgrounds
    REG_BG0
    - cbb = 0
    - SBB = 12
    - pal = 0, use when loading map

    REG_BG1
    - cbb = 1
    - sbb = 28
    - pal 1

*/





BackgroundElement::BackgroundElement(u16 start, u16 duration, u16 bgInd)
    : SceneElement(start, duration), bgImportInd(bgInd){
        is_bg0 = isBG0;
        isBG0 = !isBG0;
    }

BackgroundElement::~BackgroundElement(){

}

void BackgroundElement::activate(){
    // set blend
    // load map
    // load tiles
    // load pal

    u16 sbb = 12;
    u16 cbb = 0;
    u16 palette = 0;
    u16 palbank = 0;
    vu16* cnt = &REG_BG0CNT;
    u16 config = BG0_config;
    if(!is_bg0){
        sbb = 28;
        cbb = 2;
        palette = 16;
        cnt = &REG_BG1CNT;
        config = BG1_config;
        palbank = 1;
        REG_BG1HOFS = 0;
        REG_BG1VOFS = 0;
    }else{
        REG_BG0HOFS = 0;
        REG_BG0VOFS = 0;
    }
    for(int i = 0; i < 1024; i++){
        memset16(&se_mem[sbb][i], ((u16*)(bgImports[bgImportInd].Map))[i] | SE_PALBANK(palbank), 1);
    }
    memcpy16(&tile_mem[cbb], bgImports[bgImportInd].Tiles, bgImports[bgImportInd].TilesLen/2);
    memcpy16(&pal_bg_mem[palette], bgImports[bgImportInd].Pal, bgImports[bgImportInd].PalLen/2);
    pal_bg_mem[palette] = RGB15(0,0,0);
    *cnt = config;
}

void BackgroundElement::update(){
    SceneElement::update();

}