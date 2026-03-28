#include "tonc.h"

//code
#include "scene.hpp"
#include "names.hpp"
#include "fade.hpp"
#include "background.hpp"
#include "bringToFront.hpp"
#include "translate.hpp"
#include "shake.hpp"

//audio
#include "maxmod.h"
#include "soundbank.h"
#include "soundbank_bin.h"

#include "tp_font.h"



enum BG_IMPORT_IND{BIRD, MILL_EXT, MILL1, MILL2, TP, WATERFALL, RIVER, CREATED};

u16 secToFrames(double seconds){
    u16 frames = (u16)(seconds * 64);
    return frames;
}

void addNameFade(SceneElement* elem){
    elem->addAction(new FadeAction(32, 0, BLD_OBJ, BLD_BG0 | BLD_BG1, FadeMode::IN));
    elem->addAction(new FadeAction(32, 128, BLD_OBJ, BLD_BG0 | BLD_BG1, FadeMode::OUT));
}

double nameDuration = 2.5;

void buildScene(Scene* scene){
    //bg0
    SceneElement* bird = new BackgroundElement(0, secToFrames(6), BG_IMPORT_IND::BIRD);
    bird->addAction(new FadeAction(secToFrames(1), secToFrames(0.5), BLD_BG0, BLD_BG1, FadeMode::FROM_BLACK));
    bird->addAction(new FadeAction(secToFrames(3), secToFrames(3), BLD_BG0, BLD_BG1, FadeMode::OUT));
    bird->addAction(new ShakeAction(secToFrames(6),0,0,0,30,ShakeMode::BG0));
    scene->addElement(bird);

    //bg1
    SceneElement* millExt = new BackgroundElement(0, secToFrames(13), BG_IMPORT_IND::MILL_EXT);
    //millExt->addAction(new BTFAction(secToFrames(5), false));
    millExt->addAction(new FadeAction(secToFrames(3), secToFrames(10), BLD_BG0, BLD_BG1, FadeMode::IN));
    millExt->addAction(new ShakeAction(secToFrames(13),0,0,0,30,ShakeMode::BG1));
    scene->addElement(millExt);

    //bg0
    SceneElement* mill1 = new BackgroundElement(secToFrames(9), secToFrames(8), BG_IMPORT_IND::MILL1);
    mill1->addAction(new FadeAction(secToFrames(3), secToFrames(5), BLD_BG0, BLD_BG1, FadeMode::OUT));
    mill1->addAction(new ShakeAction(secToFrames(8),0,0,0,60,ShakeMode::BG0));
    scene->addElement(mill1);

    //bg1
    SceneElement* mill2 = new BackgroundElement(secToFrames(14), secToFrames(10), BG_IMPORT_IND::MILL2);
    mill2->addAction(new FadeAction(secToFrames(3), secToFrames(7), BLD_BG0, BLD_BG1, FadeMode::IN));
    mill2->addAction(new ShakeAction(secToFrames(10),0,0,0,30,ShakeMode::BG1));
    scene->addElement(mill2);

    //bg0
    SceneElement* twinpeaks = new BackgroundElement(secToFrames(18), secToFrames(24), BG_IMPORT_IND::TP);
    twinpeaks->addAction(new FadeAction(secToFrames(2.5), secToFrames(21.5), BLD_BG0, BLD_BG1, FadeMode::OUT));
    twinpeaks->addAction(new ShakeAction(secToFrames(25),0,0,0,60,ShakeMode::BG0));
    scene->addElement(twinpeaks);

    SceneElement* title = new NameElement(secToFrames(25), secToFrames(5.5), 72, "TWIN PEAKS");
    title->addAction(new FadeAction(secToFrames(1), 0, BLD_OBJ, BLD_BG0 | BLD_BG1, FadeMode::IN));
    title->addAction(new FadeAction(secToFrames(1), secToFrames(4.5), BLD_OBJ, BLD_BG0 | BLD_BG1, FadeMode::OUT));
    scene->addElement(title);
    
    SceneElement* kyle = new NameElement(secToFrames(31.5), secToFrames(4), 72, "KYLE MQXLACHLAN");
    kyle->addAction(new FadeAction(secToFrames(1), 0, BLD_OBJ, BLD_BG0 | BLD_BG1, FadeMode::IN));
    kyle->addAction(new FadeAction(secToFrames(1), secToFrames(3), BLD_OBJ, BLD_BG0 | BLD_BG1, FadeMode::OUT));
    scene->addElement(kyle);

    SceneElement* michael = new NameElement(secToFrames(35.5), secToFrames(4), 72, "MICHAEL ONTKEAN");
    michael->addAction(new FadeAction(secToFrames(1), 0, BLD_OBJ, BLD_BG0 | BLD_BG1, FadeMode::IN));
    michael->addAction(new FadeAction(secToFrames(1), secToFrames(3), BLD_OBJ, BLD_BG0 | BLD_BG1, FadeMode::OUT));
    scene->addElement(michael);

    //bg1
    SceneElement* waterfall = new BackgroundElement(secToFrames(39.5), secToFrames(20.5), BG_IMPORT_IND::WATERFALL);
    waterfall->addAction(new TranslateAction(secToFrames(7), secToFrames(0),16,96,TranslateMode::BG1));
    waterfall->addAction(new BTFAction(secToFrames(2.5), true));
    waterfall->addAction(new FadeAction(secToFrames(2), secToFrames(18.5), BLD_BG1, BLD_BG0, FadeMode::OUT));
    waterfall->addAction(new ShakeAction(secToFrames(13.5),secToFrames(7),15,95,30,ShakeMode::BG1));
    scene->addElement(waterfall);

    //waterfall is only being shown because of blending

    SceneElement* madchen = new NameElement(secToFrames(42), secToFrames(nameDuration), 72, "MADCHEN AMICK");
    addNameFade(madchen);
    scene->addElement(madchen);

    SceneElement* dana = new NameElement(secToFrames(45), secToFrames(nameDuration), 72, "DANA ASHBROOK");
    addNameFade(dana);
    scene->addElement(dana);

    SceneElement* richard = new NameElement(secToFrames(47.5), secToFrames(nameDuration), 72, "RICHARD BEYMER");
    addNameFade(richard);
    scene->addElement(richard);

    SceneElement* lara = new NameElement(secToFrames(50), secToFrames(nameDuration), 72, "LARA FLYNN BOYLE");
    addNameFade(lara);
    scene->addElement(lara);

    SceneElement* sherilyn = new NameElement(secToFrames(53), secToFrames(nameDuration), 72, "SHERILYN FENN");
    addNameFade(sherilyn);
    scene->addElement(sherilyn);

    SceneElement* warren = new NameElement(secToFrames(55.5), secToFrames(nameDuration), 72, "WARREN FROST");
    addNameFade(warren);
    scene->addElement(warren);

    //bg0
    SceneElement* river = new BackgroundElement(secToFrames(57), secToFrames(36), BG_IMPORT_IND::RIVER);
    river->addAction(new TranslateAction(secToFrames(25), secToFrames(0),256,0,TranslateMode::BG0));
    river->addAction(new FadeAction(secToFrames(1), secToFrames(23), BLD_BG0, BLD_BG1, FadeMode::OUT));
    river->addAction(new BTFAction(secToFrames(4), false));
    scene->addElement(river);

    SceneElement* peggy = new NameElement(secToFrames(61), secToFrames(nameDuration), 72, "PEGGY LIPTON");
    addNameFade(peggy);
    scene->addElement(peggy);

    SceneElement* james = new NameElement(secToFrames(63.5), secToFrames(nameDuration), 72, "JAMES MARSHALL");
    addNameFade(james);
    scene->addElement(james);

    SceneElement* everett = new NameElement(secToFrames(66), secToFrames(nameDuration), 72, "EVERETT MXGILL");
    addNameFade(everett);
    scene->addElement(everett);

    SceneElement* jack = new NameElement(secToFrames(68.5), secToFrames(nameDuration), 72, "JACK NANCE");
    addNameFade(jack);
    scene->addElement(jack);

    SceneElement* ray = new NameElement(secToFrames(71), secToFrames(nameDuration), 72, "RAY WISE");
    addNameFade(ray);
    scene->addElement(ray);

    SceneElement* joan = new NameElement(secToFrames(73.5), secToFrames(nameDuration), 72, "JOAN CHEN");
    addNameFade(joan);
    scene->addElement(joan);

    SceneElement* piper = new NameElement(secToFrames(76), secToFrames(nameDuration), 72, "PIPER LAURIE");
    addNameFade(piper);
    scene->addElement(piper);


    SceneElement* created = new BackgroundElement(secToFrames(79), secToFrames(11), BG_IMPORT_IND::CREATED);
    created->addAction(new FadeAction(secToFrames(3), secToFrames(8), BLD_BG0 | BLD_BG1, BLD_BACKDROP, FadeMode::TO_BLACK));
    created->addAction(new BTFAction(secToFrames(4), true));
    scene->addElement(created);

}

int main(){
    //enable Border BG

    memcpy16(&tile_mem[4], tp_fontTiles, tp_fontTilesLen/2);
    memcpy16(pal_obj_mem, tp_fontPal, tp_fontPalLen/2);

    irq_init(nullptr);
	irq_set( II_VBLANK, mmVBlank, 0);
	irq_enable(II_VBLANK);
    mmInitDefault( (mm_addr)soundbank_bin, 16 );

    

    while(1){
        initializeGlobal();

        REG_BG0CNT = BG0_config;
        REG_BG1CNT = BG1_config;

        REG_DISPCNT = DCNT_BG0 | DCNT_BG1 | DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D;

        REG_BLDCNT = BLD_BUILD(BLD_BG0, BLD_BG1, 1);
        REG_BLDALPHA = BLDA_BUILD(0,0);
        
        Scene scene;
        
        buildScene(&scene);

        mmStart( MOD_TWINPEAKSCUSTOM, MM_PLAY_ONCE );

        while(!scene.isFinished()){

            scene.update();

            //update random nunmber
            qran();

            //poll what keys are down
            key_poll();

            //update music
            mmFrame();

            //helps with visual tearing
            VBlankIntrWait();
        }

        //press any button to replay
        SceneElement* press = new NameElement(0, 0, 72, "PRESS ANY BUTTON");
        press->activate();

        while(!key_hit(KEY_ANY)){
            key_poll();
            VBlankIntrWait();
        }

        delete press;
    }
}