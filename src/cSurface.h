#ifndef _CSURFACE_H_
#define _CSURFACE_H_

#include <SDL/SDL.h>

class cSurface {
    public:
        cSurface();

        static SDL_Surface *load(const char *file);
        static bool draw(SDL_Surface *dest, SDL_Surface *src, int x, int y);
};

#endif
