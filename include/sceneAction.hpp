#ifndef __SCENE_ACTION__
#define __SCENE_ACTION__

#include "tonc.h"

class SceneAction {
    protected:
        u16 duration;
        u16 remaining_frames;
        //relative to its associated scene
        u16 start_frame;

    public:
        SceneAction(u16 dur, u16 start) 
            : duration(dur), remaining_frames(dur), start_frame(start) {}

        virtual ~SceneAction() {}

        bool isFirstFrame(u16 scene_frame){
            return scene_frame == start_frame;
        }

        // Check if this element should be active at current frame
        bool isActive(u16 frame_count) const {
            return frame_count >= start_frame && remaining_frames > 0;
        }

        // Called once when action starts
        virtual void activate() {}

        // Called each frame
        virtual void update() {
            remaining_frames--;
        }

        bool isFinished() const {
            return remaining_frames == 0;
        }

};

#endif