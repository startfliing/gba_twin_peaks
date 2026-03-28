#ifndef __SHAKE_ACTION__
#define __SHAKE_ACTION__

#include "sceneAction.hpp"

enum class ShakeMode { BG0, BG1, BG2, BG3, SPRITE };

class ShakeAction : public SceneAction {
    private:
        u16 x,y;
        u16 shakeSpeed;
        u16 curr_frame;
        ShakeMode mode;

    public:
        ShakeAction(u16 duration, u16 start, u16 sx, u16 sy, u16 speed, ShakeMode Shake_mode)
            : SceneAction(duration, start), x(sx), y(sy), shakeSpeed(speed), curr_frame(0), mode(Shake_mode) {}

        void activate() override {
            
        }

        void update() override {
            SceneAction::update();

            
            curr_frame++;
            if(curr_frame == shakeSpeed){
                curr_frame = 0;

                s8 dx = qran() % 2;
                s8 dy = qran() % 2;

                u16 newx = x + dx;
                u16 newy = y + dy;

                switch(mode){
                    case ShakeMode::BG0:
                        REG_BG0HOFS = newx;
                        REG_BG0VOFS = newy;
                        break;
                    case ShakeMode::BG1:
                        REG_BG1HOFS = newx;
                        REG_BG1VOFS = newy;
                        break;
                    case ShakeMode::BG2:

                        break;
                    case ShakeMode::BG3:

                        break;
                    default:
                        break;
                }
            }

        }
};

#endif