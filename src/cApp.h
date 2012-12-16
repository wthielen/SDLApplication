#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL/SDL.h>

#include "cActivity.h"
#include "cEntity.h"

class cApp : public cActivity {
    private:
        cEntity     e1;
        cEntity     e2;

    public:
        cApp();

        bool init();
        void loop();
        void render();
        void cleanup();
};

#endif
