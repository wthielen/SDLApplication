#include "cApp.h"
#include "cSurface.h"

#include <iostream>

#define DISPLAY_WIDTH 300
#define DISPLAY_HEIGHT 300

cApp::cApp() {
    sfTest = NULL;

    /*
    width = DISPLAY_WIDTH;
    height = DISPLAY_HEIGHT;
    */
}

bool cApp::init() {
    if (!cActivity::init()) return false;

    if ((sfTest = cSurface::load("./gfx/test.bmp")) == NULL) {
        return false;
    }

    return true;
}

void cApp::render() {
    cSurface::draw(display, sfTest, 100, 100);

    SDL_Flip(display);
}

void cApp::cleanup() {
    SDL_FreeSurface(sfTest);

    cActivity::cleanup();
}

int main(int argc, char *argv[]) {
    cApp theApp;

    return theApp.execute();
}
