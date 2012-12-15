#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL/SDL.h>

#include "cActivity.h"

class cApp : public cActivity {
    private:
        SDL_Surface     *sfGrid;
        SDL_Surface     *sfX;
        SDL_Surface     *sfO;

        int     currentPlayer;
        int     grid[9];
        enum {
            GRID_TYPE_NONE = 0,
            GRID_TYPE_X,
            GRID_TYPE_O
        };

    public:
        cApp();

        bool init();
        void render();
        void cleanup();

        void reset();
        void setCell(int id, int type);

        // Events
        void onLButtonDown(int mx, int my);
};

#endif
