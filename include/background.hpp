#ifndef __BACKGROUND__
#define __BACKGROUND__

#include "tonc.h"
#include "sceneElement.hpp"

class BackgroundElement : public SceneElement {
    private:
        u16 bgImportInd;

        bool is_bg0;

    public:
        BackgroundElement(u16 start, u16 duration, u16 bgImportInd);

        ~BackgroundElement();

        void activate();

        void update() override;

};


#endif