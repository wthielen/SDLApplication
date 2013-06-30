#include "cApp.h"
#include "cSurface.h"

#include <iostream>

#define DISPLAY_WIDTH 640
#define DISPLAY_HEIGHT 480

cApp::cApp() {
    width = DISPLAY_WIDTH;
    height = DISPLAY_HEIGHT;
}

bool cApp::init() {
    if (!cActivity::init()) return false;

    w = webcam_open("/dev/video0");
    webcam_resize(w, DISPLAY_WIDTH, DISPLAY_HEIGHT);
    webcam_stream(w, true);

    frame.start = NULL;
    frame.length = 0;

    return true;
}

void cApp::loop() {
    webcam_grab(w, &frame);
}

void cApp::render() {
    cActivity::render();

    Uint8 r, g, b;
    Uint32 *p;
    size_t pixels = frame.length / 3;

    for(size_t i = 0; i < pixels; i++) {
        r = (Uint8)frame.start[i * 3];
        g = (Uint8)frame.start[i * 3 + 1];
        b = (Uint8)frame.start[i * 3 + 2];

        p = (Uint32*)display->pixels + i;
        *p = SDL_MapRGB(display->format, r, g, b);
    }

    SDL_Flip(display);
}

void cApp::cleanup() {
    webcam_stream(w, false);
    webcam_close(w);

    if (frame.start != NULL) free(frame.start);

    cActivity::cleanup();
}

int main(int argc, char *argv[]) {
    cApp theApp;

    return theApp.execute();
}
