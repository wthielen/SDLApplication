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

bool cSurface::draw(SDL_Surface *dest, SDL_Surface *src, int x1, int y1, int x2, int y2, int w, int h) {
    if (dest == NULL || src == NULL) return false;

    SDL_Rect destR;
    destR.x = x1;
    destR.y = y1;

    SDL_Rect srcR;
    srcR.x = x2;
    srcR.y = y2;
    srcR.w = w;
    srcR.h = h;

    SDL_BlitSurface(src, &srcR, dest, &destR);

    return true;
}

bool cSurface::transparent(SDL_Surface *dest, int r, int g, int b) {
    if (dest == NULL) return false;

    SDL_SetColorKey(dest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(dest->format, r, g, b));

    return true;
}
