#ifndef __SCENE__
#define __SCENE__

#include "linked_list.hpp"
#include "sceneElement.hpp"

class Scene {
    private:
        LinkedList<SceneElement*> elements; // adjust max size as needed
        u16 frame_counter;

    public:
        Scene() : frame_counter(0) {}

        ~Scene() {
            clear();
        }

        // Add an element to the scene
        bool addElement(SceneElement* element) {
            return elements.push_back(element);
        }

        // Update all active elements and remove finished ones
        void update() {
            for (int i = 0; i < elements.size(); i++) {
                SceneElement* elem = elements.at(i);
                if(elem->firstFrame(frame_counter)){
                    elem->activate();
                }

                if (elem->isActive(frame_counter)) {
                    // Update active elements
                    elem->update();
                } else if (elem->isFinished()) {
                    // Remove finished elements
                    delete elem;
                    elements.remove(i);
                    i--; // adjust index after removal
                }
            }
            frame_counter++;
        }

        // Get current frame
        u16 getCurrentFrame() const {
            return frame_counter;
        }

        // Reset scene
        void clear() {
            for (int i = 0; i < elements.size(); i++) {
                delete elements.at(i);
            }
            elements.clear();
            frame_counter = 0;
        }

        // Advance to a specific frame
        void setFrame(u16 frame) {
            frame_counter = frame;
        }

        bool isFinished(){
            return elements.empty();
        }
};

#endif