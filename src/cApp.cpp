#include "cApp.h"
#include "cSurface.h"

#include <iostream>

#define DISPLAY_WIDTH 600
#define DISPLAY_HEIGHT 600

cApp::cApp() {
    sfGrid = NULL;
    sfX = NULL;
    sfO = NULL;

    width = DISPLAY_WIDTH;
    height = DISPLAY_HEIGHT;

    currentPlayer = 0;
}

bool cApp::init() {
    if (!cActivity::init()) return false;

    if ((sfGrid = cSurface::load("./gfx/grid.bmp")) == NULL) {
        return false;
    }

    if ((sfX = cSurface::load("./gfx/x.bmp")) == NULL) {
        return false;
    }

    if ((sfO = cSurface::load("./gfx/o.bmp")) == NULL) {
        return false;
    }

    cSurface::transparent(sfX, 255, 0, 255);
    cSurface::transparent(sfO, 255, 0, 255);

    reset();

    return true;
}

void cApp::render() {
    cSurface::draw(display, sfGrid, 0, 0);

    for (int i = 0; i < 9; i++) {
        int x = (i % 3) * 200;
        int y = (i / 3) * 200;

        if (grid[i] == GRID_TYPE_X) {
            cSurface::draw(display, sfX, x, y);
        } else if (grid[i] == GRID_TYPE_O) {
            cSurface::draw(display, sfO, x, y);
        }
    }

    SDL_Flip(display);
}

void cApp::cleanup() {
    SDL_FreeSurface(sfGrid);
    SDL_FreeSurface(sfO);
    SDL_FreeSurface(sfX);

    cActivity::cleanup();
}

void cApp::reset() {
    for (int i = 0; i < 9; i++) {
        grid[i] = GRID_TYPE_NONE;
    }
}

void cApp::setCell(int id, int type) {
    if (id < 0 || id >= 9) return;
    if (type < 0 || type > GRID_TYPE_O) return;

    grid[id] = type;
}

void cApp::onLButtonDown(int mx, int my) {
    int id = mx / 200 + 3 * (my / 200);

    if (grid[id] != GRID_TYPE_NONE) return;

    if (currentPlayer == 0) {
        setCell(id, GRID_TYPE_X);
        currentPlayer = 1;
    } else {
        setCell(id, GRID_TYPE_O);
        currentPlayer = 0;
    }
}

int main(int argc, char *argv[]) {
    cApp theApp;

    return theApp.execute();
}
