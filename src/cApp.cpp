#include "cApp.h"
#include "cSurface.h"

#include <iostream>

#define DISPLAY_WIDTH 600
#define DISPLAY_HEIGHT 600

cApp::cApp() {
    sfYoshi = NULL;

    width = DISPLAY_WIDTH;
    height = DISPLAY_HEIGHT;
}

bool cApp::init() {
    if (!cActivity::init()) return false;

    if ((sfYoshi = cSurface::load("./gfx/yoshi.bmp")) == NULL) {
        return false;
    }

    cSurface::transparent(sfYoshi, 255, 0, 255);

    animYoshi.maxFrames = 8;

    return true;
}

void cApp::loop() {
    animYoshi.animate();
}

void cApp::render() {
    SDL_Rect bg;
    bg.x = 0;
    bg.y = 0;
    bg.w = width;
    bg.h = width;
    
    SDL_FillRect(display, &bg, SDL_MapRGB(display->format, 0, 0, 0));
    cSurface::draw(display, sfYoshi, 290, 220, 0, animYoshi.getCurrentFrame() * 64, 64, 64);

    SDL_Flip(display);
}

void cApp::cleanup() {
    SDL_FreeSurface(sfYoshi);

    cActivity::cleanup();
}

int main(int argc, char *argv[]) {
    cApp theApp;

    return theApp.execute();
}
