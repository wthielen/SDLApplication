#include "cAnimation.h"

cAnimation::cAnimation() {
    currentFrame = 0;
    maxFrames = 0;
    frameInc = 1;

    frameRate = 100;
    oldTime = 0;

    oscillate = false;
}

void cAnimation::animate() {
    if (oldTime + frameRate > SDL_GetTicks()) {
        return;
    }

    oldTime = SDL_GetTicks();

    currentFrame += frameInc;

    if (oscillate) {
        if (frameInc > 0) {
            if (currentFrame >= maxFrames - 1) {
                frameInc *= -1;
            }
        } else {
            if (currentFrame <= 0) {
                frameInc *= -1;
            }
        }
    } else {
        if (currentFrame >= maxFrames) {
            currentFrame = 0;
        }
    }
}

void cAnimation::setFrameRate(int rate) {
    frameRate = rate;
}

void cAnimation::setCurrentFrame(int frame) {
    if (frame < 0 || frame >= maxFrames) return;

    currentFrame = frame;
}

int cAnimation::getCurrentFrame() {
    return currentFrame;
}
