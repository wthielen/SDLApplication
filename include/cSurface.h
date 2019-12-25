#ifndef _CSURFACE_H_
#define _CSURFACE_H_

#include <SDL2/SDL.h>

class cSurface {
    public:
        cSurface();

        static SDL_Surface *load(const char *file);
        static bool draw(SDL_Surface *dest, SDL_Surface *src, int x, int y);
        static bool draw(SDL_Surface *dest, SDL_Surface *src, int x1, int y1, int x2, int y2, int w, int h);
        static bool transparent(SDL_Surface *dest, int r, int g, int b);
};

#endif
