#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL/SDL.h>

#include "cActivity.h"

extern "C" {
#include "webcam.h"
};

class cApp : public cActivity {
    private:
        webcam_t *w;
        buffer_t frame;
        SDL_Surface *sfFrame;

    public:
        cApp();

        bool init();
        void loop();
        void render();
        void cleanup();
};

#endif
