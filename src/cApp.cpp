#include "cApp.h"
#include "cSurface.h"

#include <iostream>

#define WEBCAM_WIDTH 640
#define WEBCAM_HEIGHT 480

cApp::cApp() {
    width = WEBCAM_WIDTH;
    height = WEBCAM_HEIGHT;
}

bool cApp::init() {
    if (!cActivity::init()) return false;

    Uint32 rmask, gmask, bmask, amask;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    rmask = 0xff000000;
    gmask = 0x00ff0000;
    bmask = 0x0000ff00;
    amask = 0x000000ff;
#else
    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = 0xff000000;
#endif

	sfFrame = SDL_CreateRGBSurface(0, width, height, 32, rmask, gmask, bmask, amask);
    if (sfFrame == NULL) return false;

    w = webcam_open("/dev/video0");
    webcam_resize(w, WEBCAM_WIDTH, WEBCAM_HEIGHT);
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

	updateFrame();

    SDL_Surface *surface = SDL_GetWindowSurface(window);
    SDL_Renderer *renderer = SDL_CreateSoftwareRenderer(surface);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, sfFrame);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    SDL_UpdateWindowSurface(window);
}

void cApp::cleanup() {
    webcam_stream(w, false);
    webcam_close(w);

    if (frame.start != NULL) free(frame.start);

	SDL_FreeSurface(sfFrame);

    cActivity::cleanup();
}

void cApp::updateFrame() {
    Uint8 r, g, b;
    Uint32 *p;
    size_t pixels = frame.length / 3;

    for(size_t i = 0; i < pixels; i++) {
        r = (Uint8)frame.start[i * 3];
        g = (Uint8)frame.start[i * 3 + 1];
        b = (Uint8)frame.start[i * 3 + 2];

        p = (Uint32*)sfFrame->pixels + i;
        *p = SDL_MapRGB(sfFrame->format, r, g, b);
    }
}

void cApp::onResize(int w, int h) {
    width = w;
    height = h;
}

int main(int argc, char *argv[]) {
    cApp theApp;

    return theApp.execute();
}
