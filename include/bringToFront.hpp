#ifndef __BRING_TO_FRONT_ACTION__
#define __BRING_TO_FRONT_ACTION__

#include "sceneAction.hpp"

#include "global.hpp"

//bring to Front
class BTFAction : public SceneAction {
    private:
        bool BG0toFront;

    public:
        BTFAction(u16 start, bool bringBG0)
            : SceneAction(1, start), BG0toFront(bringBG0){}

        void activate() override {
            u16 bg0_prio = BG0toFront ? 2 : 1;
            u16 bg1_prio = BG0toFront ? 1 : 2;

            BG0_config = BG_BUILD(0,12,2,0,bg0_prio,0,1);
            BG1_config = BG_BUILD(2,28,2,0,bg1_prio,0,1);

            REG_BG0CNT = BG0_config;
            REG_BG1CNT = BG1_config;
        }

        void update() override {
            SceneAction::update();
        }
};

#endif