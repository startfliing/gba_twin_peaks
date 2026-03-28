#ifndef __TRANSLATE_ACTION__
#define __TRANSLATE_ACTION__

#include "sceneAction.hpp"

enum class TranslateMode { BG0, BG1, BG2, BG3, SPRITE };

class TranslateAction : public SceneAction {
    private:
        s16 dx, dy;
        TranslateMode mode;

    public:
        TranslateAction(u16 duration, u16 start, s16 x, s16 y, TranslateMode Translate_mode)
            : SceneAction(duration, start), dx(x), dy(y), mode(Translate_mode) {}

        void activate() override {
            
        }

        void update() override {
            SceneAction::update();
            s16 update_rate_x = (dx<<8)/duration;
            s16 update_rate_y = (dy<<8)/duration;
            s16 ex = (duration - remaining_frames) * update_rate_x;
            s16 ey = (duration - remaining_frames) * update_rate_y;

            switch(mode){
                case TranslateMode::BG0:
                    REG_BG0HOFS = ex>>8;
                    REG_BG0VOFS = ey>>8;
                    break;
                case TranslateMode::BG1:
                    REG_BG1HOFS = ex>>8;
                    REG_BG1VOFS = ey>>8;
                    break;
                case TranslateMode::BG2:

                    break;
                case TranslateMode::BG3:

                    break;
                default:
                    break;
            }

        }
};

#endif