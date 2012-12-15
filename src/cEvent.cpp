#include "cEvent.h"
 
cEvent::cEvent() {
}
 
cEvent::~cEvent() {
    //Do nothing
}
 
void cEvent::onEvent(SDL_Event* ev) {
    switch(ev->type) {
        case SDL_ACTIVEEVENT: {
            switch(ev->active.state) {
                case SDL_APPMOUSEFOCUS: {
                    if (ev->active.gain)
                        onMouseFocus();
                    else
                        onMouseBlur();
 
                    break;
                }
                case SDL_APPINPUTFOCUS: {
                    if (ev->active.gain)
                        onInputFocus();
                    else
                        onInputBlur();
 
                    break;
                }
                case SDL_APPACTIVE: {
                    if (ev->active.gain)
                        onRestore();
                    else
                        onMinimize();
 
                    break;
                }
            }
            break;
        }
 
        case SDL_KEYDOWN: {
            onKeyDown(
                    ev->key.keysym.sym, 
                    ev->key.keysym.mod, 
                    ev->key.keysym.unicode
                );
            break;
        }
 
        case SDL_KEYUP: {
            onKeyUp(
                    ev->key.keysym.sym, 
                    ev->key.keysym.mod, 
                    ev->key.keysym.unicode
                );
            break;
        }
 
        case SDL_MOUSEMOTION: {
            onMouseMove(
                    ev->motion.x, 
                    ev->motion.y, 
                    ev->motion.xrel, 
                    ev->motion.yrel,
                    (ev->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0,
                    (ev->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0,
                    (ev->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0
                );
            break;
        }
 
        case SDL_MOUSEBUTTONDOWN: {
            switch(ev->button.button) {
                case SDL_BUTTON_LEFT: {
                    onLButtonDown(ev->button.x, ev->button.y);
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    onRButtonDown(ev->button.x, ev->button.y);
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    onMButtonDown(ev->button.x, ev->button.y);
                    break;
                }
            }
            break;
        }
 
        case SDL_MOUSEBUTTONUP:    {
            switch(ev->button.button) {
                case SDL_BUTTON_LEFT: {
                    onLButtonUp(ev->button.x, ev->button.y);
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    onRButtonUp(ev->button.x, ev->button.y);
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    onMButtonUp(ev->button.x, ev->button.y);
                    break;
                }
            }
            break;
        }
 
        case SDL_JOYAXISMOTION: {
            onJoyAxis(
                    ev->jaxis.which, 
                    ev->jaxis.axis, 
                    ev->jaxis.value
                );
            break;
        }
 
        case SDL_JOYBALLMOTION: {
            onJoyBall(
                    ev->jball.which, 
                    ev->jball.ball, 
                    ev->jball.xrel, 
                    ev->jball.yrel
                );
            break;
        }
 
        case SDL_JOYHATMOTION: {
            onJoyHat(ev->jhat.which, ev->jhat.hat, ev->jhat.value);
            break;
        }
        case SDL_JOYBUTTONDOWN: {
            onJoyButtonDown(ev->jbutton.which, ev->jbutton.button);
            break;
        }
 
        case SDL_JOYBUTTONUP: {
            onJoyButtonUp(ev->jbutton.which, ev->jbutton.button);
            break;
        }
 
        case SDL_QUIT: {
            onExit();
            break;
        }
 
        case SDL_SYSWMEVENT: {
            //Ignore
            break;
        }
 
        case SDL_VIDEORESIZE: {
            onResize(ev->resize.w, ev->resize.h);
            break;
        }
 
        case SDL_VIDEOEXPOSE: {
            onExpose();
            break;
        }
 
        default: {
            onUser(
                    ev->user.type, 
                    ev->user.code, 
                    ev->user.data1, 
                    ev->user.data2
                );
            break;
        }
    }
}
 
void cEvent::onInputFocus() {
    //Pure virtual, do nothing
}
 
void cEvent::onInputBlur() {
    //Pure virtual, do nothing
}
 
void cEvent::onKeyDown(SDLKey key, SDLMod mod, Uint16 unicode) {
    //Pure virtual, do nothing
}
 
void cEvent::onKeyUp(SDLKey key, SDLMod mod, Uint16 unicode) {
    //Pure virtual, do nothing
}
 
void cEvent::onMouseFocus() {
    //Pure virtual, do nothing
}
 
void cEvent::onMouseBlur() {
    //Pure virtual, do nothing
}
 
void cEvent::onMouseMove(int mx, int my, int dx, int dy, bool left,bool right,bool middle) {
    //Pure virtual, do nothing
}
 
void cEvent::onMouseWheel(bool up, bool down) {
    //Pure virtual, do nothing
}
 
void cEvent::onLButtonDown(int mx, int my) {
    //Pure virtual, do nothing
}
 
void cEvent::onLButtonUp(int mx, int my) {
    //Pure virtual, do nothing
}
 
void cEvent::onRButtonDown(int mx, int my) {
    //Pure virtual, do nothing
}
 
void cEvent::onRButtonUp(int mx, int my) {
    //Pure virtual, do nothing
}
 
void cEvent::onMButtonDown(int mx, int my) {
    //Pure virtual, do nothing
}
 
void cEvent::onMButtonUp(int mx, int my) {
    //Pure virtual, do nothing
}
 
void cEvent::onJoyAxis(Uint8 which, Uint8 axis, Sint16 value) {
    //Pure virtual, do nothing
}
 
void cEvent::onJoyButtonDown(Uint8 which, Uint8 button) {
    //Pure virtual, do nothing
}
 
void cEvent::onJoyButtonUp(Uint8 which, Uint8 button) {
    //Pure virtual, do nothing
}
 
void cEvent::onJoyHat(Uint8 which, Uint8 hat, Uint8 value) {
    //Pure virtual, do nothing
}
 
void cEvent::onJoyBall(Uint8 which, Uint8 ball, Sint16 dx, Sint16 dy) {
    //Pure virtual, do nothing
}
 
void cEvent::onMinimize() {
    //Pure virtual, do nothing
}
 
void cEvent::onRestore() {
    //Pure virtual, do nothing
}
 
void cEvent::onResize(int w, int h) {
    //Pure virtual, do nothing
}
 
void cEvent::onExpose() {
    //Pure virtual, do nothing
}
 
void cEvent::onExit() {
    //Pure virtual, do nothing
}
 
void cEvent::onUser(Uint8 type, int code, void* data1, void* data2) {
    //Pure virtual, do nothing
}
