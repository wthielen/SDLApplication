#ifndef _CENTITY_H_
#define _CENTITY_H_

#include <vector>

#include "cAnimation.h"
#include "cSurface.h"

class cEntity {
    public:
        static std::vector<cEntity *> collection;

    protected:
        cAnimation      animControl;
        SDL_Surface     *sfEntity;

    public:
        float x, y;
        int w, h;
        
        int animState;

    public:
        cEntity();
        virtual ~cEntity();

        virtual bool load(const char *file, int w, int h, int frames);
        virtual void loop();
        virtual void render(SDL_Surface *display);
        virtual void cleanup();
};

#endif
