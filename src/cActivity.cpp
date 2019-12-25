#include "cActivity.h"

cActivity::cActivity() {
    window = NULL;
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

    window = SDL_CreateWindow(
            "Webcam application",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            width,
            height,
            SDL_WINDOW_RESIZABLE);
        
    if (window == NULL) return false;

    return true;
}

void cActivity::loop() {
}

void cActivity::render() {
    /*
    SDL_Rect background;
    background.x = 0;
    background.y = 0;
    background.w = width;
    background.h = height;

    SDL_Surface *display = SDL_GetWindowSurface(window);
    SDL_FillRect(display, &background, SDL_MapRGB(display->format, 0, 0, 0));
    SDL_UpdateWindowSurface(window);
    */
}

void cActivity::cleanup() {
    SDL_DestroyWindow(window);

    SDL_Quit();
}

void cActivity::onExit() {
    running = false;
}
