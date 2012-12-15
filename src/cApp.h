#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL/SDL.h>

#include "cActivity.h"

class cApp : public cActivity {
    private:
        SDL_Surface     *sfTest;

    public:
        cApp();

        bool init();
        void render();
        void cleanup();
};

#endif
