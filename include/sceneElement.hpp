// sceneelement.hpp
#ifndef __SCENE_ELEMENT__
#define __SCENE_ELEMENT__

#include "tonc.h"

#include "sceneAction.hpp"
#include "linked_list.hpp"


class SceneElement {
    protected:
        u16 start_frame;
        u16 duration;
        u16 remaining_frames;
        LinkedList<SceneAction*> actions;


    public:
        SceneElement(u16 start, u16 dur) 
            : start_frame(start), duration(dur), remaining_frames(dur)  {}

        virtual ~SceneElement() {}

        bool firstFrame(u16 frame_count){
            return frame_count == start_frame;
        }

        void addAction(SceneAction* sa){
            actions.push_back(sa);
        };


        // Check if this element should be active at current frame
        bool isActive(u16 frame_count) const {
            return frame_count >= start_frame && remaining_frames > 0;
        }

        // Check if element has finished
        bool isFinished() const {
            return remaining_frames == 0;
        }

        virtual void activate(){

        };

        // Called each frame while active
        virtual void update(){
            u16 frame_count = duration - remaining_frames;
            for(int i = 0; i < actions.size(); i++){
                SceneAction* action = actions.at(i);
            
                if(action->isFirstFrame(frame_count)) {
                    action->activate();
                }

                if(action->isActive(frame_count)){
                    action->update();
                }
            
                if(action->isFinished()) {
                    delete action;
                    actions.remove(i);
                    i--;
                }
            }

            remaining_frames--;
        };

        u16 getRemainingFrames(){
            return remaining_frames;
        }

};

#endif