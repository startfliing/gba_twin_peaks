#ifndef __FADE_ACTION__
#define __FADE_ACTION__

#include "sceneAction.hpp"

enum class FadeMode { IN, OUT, FROM_BLACK, TO_BLACK};

class FadeAction : public SceneAction {
    private:
        u16 top_layer;
        u16 bot_layer;
        FadeMode mode;

    public:
        FadeAction(u16 duration, u16 start, u16 top, u16 bot, FadeMode fade_mode)
            : SceneAction(duration, start), top_layer(top), bot_layer(bot), mode(fade_mode) {}

        void activate() override {
            u16 bld_mode = 0;
            u16 bld_top = 0;
            u16 bld_bot = 0;
            u16 bld_y = 0;
            switch(mode){
                case FadeMode::IN:
                    bld_mode = 1;
                    bld_top = 0;
                    bld_bot = 16;
                    break;
                case FadeMode::OUT:
                    bld_mode = 1;
                    bld_top = 16;
                    bld_bot = 0;
                    break;
                case FadeMode::FROM_BLACK:
                    bld_mode = 3;
                    bld_y = 16;
                    break;
                case FadeMode::TO_BLACK:
                    bld_mode = 3;
                    bld_y = 16;
                    break;
                default:
                    break;
            }
            REG_BLDCNT = BLD_BUILD(top_layer, bot_layer, bld_mode);
            REG_BLDALPHA = BLDA_BUILD(bld_top, bld_bot);
            REG_BLDY = BLDY_BUILD(bld_y);
        }

        void update() override {
            SceneAction::update();
            u8 update_rate = duration/16;
            u8 ev = remaining_frames/update_rate;

            switch(mode){
                case FadeMode::IN:
                    REG_BLDALPHA = BLDA_BUILD(16-ev,ev);
                    break;
                case FadeMode::OUT:
                    REG_BLDALPHA = BLDA_BUILD(ev, 16-ev);
                    break;
                case FadeMode::FROM_BLACK:
                    REG_BLDY = BLDY_BUILD(ev);
                    REG_BLDALPHA = BLDA_BUILD(16-ev, 0);
                    break;
                case FadeMode::TO_BLACK:
                    REG_BLDALPHA = BLDA_BUILD(ev, 16-ev);
                    REG_BLDY = 16-ev;
                    break;
                default:
                    break;
            }

        }
};

#endif