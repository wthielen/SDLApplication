#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL/SDL.h>

#include "cActivity.h"
#include "cAnimation.h"

class cApp : public cActivity {
    private:
        SDL_Surface     *sfYoshi;

        cAnimation      animYoshi;

    public:
        cApp();

        bool init();
        void loop();
        void render();
        void cleanup();
};

#endif
