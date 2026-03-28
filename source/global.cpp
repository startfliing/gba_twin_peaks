#include "global.hpp"

bool isBG0 = true;

u16 BG0_config = BG_BUILD(0,12,2,0,1,0,1);
u16 BG1_config = BG_BUILD(2,28,2,0,2,0,1);


void initializeGlobal(){
    isBG0 = true;
    BG0_config = BG_BUILD(0,12,2,0,1,0,1);
    BG1_config = BG_BUILD(2,28,2,0,2,0,1);
}