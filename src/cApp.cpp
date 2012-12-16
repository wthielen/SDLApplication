#include "cApp.h"
#include "cSurface.h"

#include <iostream>

#define DISPLAY_WIDTH 600
#define DISPLAY_HEIGHT 600

cApp::cApp() {
    width = DISPLAY_WIDTH;
    height = DISPLAY_HEIGHT;
}

bool cApp::init() {
    if (!cActivity::init()) return false;

    if (e1.load("./gfx/yoshi.bmp", 64, 64, 8) == false) {
        return false;
    }

    if (e2.load("./gfx/yoshi.bmp", 64, 64, 8) == false) {
        return false;
    }

    e2.x = 100;

    cEntity::collection.push_back(&e1);
    cEntity::collection.push_back(&e2);

    return true;
}

void cApp::loop() {
    for (int i = 0; i < cEntity::collection.size(); i++) {
        if (!cEntity::collection[i]) continue;

        cEntity::collection[i]->loop();
    }
}

void cApp::render() {
    SDL_Rect bg;
    bg.x = 0;
    bg.y = 0;
    bg.w = width;
    bg.h = height;

    SDL_FillRect(display, &bg, SDL_MapRGB(display->format, 0, 0, 0));

    for (int i = 0; i < cEntity::collection.size(); i++) {
        if (!cEntity::collection[i]) continue;

        cEntity::collection[i]->render(display);
    }

    SDL_Flip(display);
}

void cApp::cleanup() {
    for (int i = 0; i < cEntity::collection.size(); i++) {
        if (!cEntity::collection[i]) continue;

        cEntity::collection[i]->cleanup();
    }

    cEntity::collection.clear();

    cActivity::cleanup();
}

int main(int argc, char *argv[]) {
    cApp theApp;

    return theApp.execute();
}
