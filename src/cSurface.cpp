#include "cSurface.h"

cSurface::cSurface() {
}

SDL_Surface *cSurface::load(const char *file) {
    SDL_Surface *temp = NULL;
    SDL_Surface *ret = NULL;

    if ((temp = SDL_LoadBMP(file)) == NULL) {
        return NULL;
    }

    ret = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);

    return ret;
}

bool cSurface::draw(SDL_Surface *dest, SDL_Surface *src, int x, int y) {
    if (dest == NULL || src == NULL) {
        return false;
    }

    SDL_Rect r;
    r.x = x;
    r.y = y;

    SDL_BlitSurface(src, NULL, dest, &r);

    return true;
}
