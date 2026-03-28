#ifndef __NAMES__
#define __NAMES__

#include "tonc.h"
#include "sceneElement.hpp"
#include "tp_font_widths.hpp"

class NameElement : public SceneElement {
    private:
        const char* name;
        u8 total_width;
        u8 yLevel;

    public:
        NameElement(u16 start, u16 duration, u8 y, const char* print_name);

        ~NameElement();

        void activate();

        void update() override;

};

#endif