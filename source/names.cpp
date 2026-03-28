#include "tonc.h"
#include "names.hpp"

#include "fade.hpp"

NameElement::NameElement(u16 start, u16 duration, u8 y, const char* print_name)
    : SceneElement(start, duration), name(print_name), total_width(0), yLevel(y) {
    const char* head = name;
    while(*head != '\0'){  
        int charInd = CAPITAL_TO_IND(*head);
        total_width += *head == ' ' ? 8 : tp_font_widths[charInd];
        head++;
    }
}

NameElement::~NameElement(){
    oam_init(oam_mem, 128);
}

void NameElement::activate(){

    // print text
    const char* head = name;
    u8 sprite_num = 0;
    u8 curr_width = (SCREEN_WIDTH - total_width) / 2; // apply centering
    while(*head != '\0'){
        //handle spaces
        if(*head == ' '){
            curr_width += 8;
            head++;
            continue;
        }

        int charInd = CAPITAL_TO_IND(*head);
        obj_set_attr(
            &oam_mem[sprite_num++], 
            ATTR0_SQUARE | ATTR0_BLEND | ATTR0_Y(yLevel),
            ATTR1_SIZE_16 | ATTR1_X(curr_width),
            (charInd*4) + 1
        );
        curr_width += tp_font_widths[charInd];
        head++;
    }
}

void NameElement::update(){
    SceneElement::update();
}