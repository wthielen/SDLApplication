#include "cActivity.h"

cActivity::cActivity() {
    display = NULL;
    width = 0;
    height = 0;

    running = true;
}

int cActivity::execute() {
    if (init() == false) {
        return -1;
    }

    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            onEvent(&event);
        }

        loop();
        render();
    }

    cleanup();

    return 0;
}

bool cActivity::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    width = width == 0 ? CA_DEFAULT_WIDTH : width;
    height = height == 0 ? CA_DEFAULT_HEIGHT : height;

    if ((display = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    return true;
}

void cActivity::loop() {
}

void cActivity::render() {
    SDL_Rect background;
    background.x = 0;
    background.y = 0;
    background.w = width;
    background.h = height;

    SDL_FillRect(display, &background, SDL_MapRGB(display->format, 0, 0, 0));
}

void cActivity::cleanup() {
    SDL_FreeSurface(display);

    SDL_Quit();
}

void cActivity::onExit() {
    running = false;
}
