#ifndef _CEVENT_H_
#define _CEVENT_H_

#include <SDL/SDL.h>

class cEvent {
    public:
        cEvent();
        virtual ~cEvent();

        void onEvent(SDL_Event *ev);
        virtual void onInputFocus();
        virtual void onInputBlur();
        virtual void onKeyDown(SDLKey key, SDLMod mod, Uint16 unicode);
        virtual void onKeyUp(SDLKey key, SDLMod mod, Uint16 unicode);
        virtual void onMouseFocus();
        virtual void onMouseBlur();
        virtual void onMouseMove(int mx, int my, int dx, int dy, bool left, bool right, bool middle);
        virtual void onMouseWheel(bool up, bool down);
        virtual void onLButtonDown(int mx, int my);
        virtual void onLButtonUp(int mx, int my);
        virtual void onRButtonDown(int mx, int my);
        virtual void onRButtonUp(int mx, int my);
        virtual void onMButtonDown(int mx, int my);
        virtual void onMButtonUp(int mx, int my);
        virtual void onJoyAxis(Uint8 which, Uint8 axis, Sint16 value);
        virtual void onJoyButtonDown(Uint8 which, Uint8 button);
        virtual void onJoyButtonUp(Uint8 which, Uint8 button);
        virtual void onJoyHat(Uint8 which, Uint8 hat, Uint8 value);
        virtual void onJoyBall(Uint8 which, Uint8 ball, Sint16 dx, Sint16 dy);
        virtual void onMinimize();
        virtual void onRestore();
        virtual void onResize(int w, int h);
        virtual void onExpose();
        virtual void onExit();
        virtual void onUser(Uint8 type, int code, void *data1, void *data2);
};

#endif
