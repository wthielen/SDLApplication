#ifndef _CACTIVITY_H_
#define _CACTIVITY_H_

#include <SDL/SDL.h>

#include "cEvent.h"

#define CA_DEFAULT_WIDTH 640
#define CA_DEFAULT_HEIGHT 480

class cActivity : public cEvent{
    protected:
        bool        running;
        SDL_Surface *display;
    
        Uint16      width;
        Uint16      height;

    public:
        cActivity();

        int execute();

        virtual bool init();
        virtual void loop();
        virtual void render();
        virtual void cleanup();

        // From cEvent
        virtual void onExit();
};

#endif
