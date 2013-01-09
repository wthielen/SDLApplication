#ifndef _CANIMATION_H_
#define _CANIMATION_H_

#include <SDL/SDL.h>

class cAnimation {
    private:
        int     currentFrame;
        int     frameInc;
        int     frameRate;
        long    oldTime;

    public:
        int     maxFrames;
        bool    oscillate;

        cAnimation();
        
        void animate();

        void setFrameRate(int rate);
        void setCurrentFrame(int frame);
        int getCurrentFrame();
};

#endif
