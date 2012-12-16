#include "cEntity.h"

std::vector<cEntity *> cEntity::collection;

cEntity::cEntity() {
    sfEntity = NULL;

    x = y = 0.0f;
    w = h = 0;

    animState = 0;
}

cEntity::~cEntity() {
}

bool cEntity::load(const char *file, int w, int h, int frames) {
    if ((sfEntity = cSurface::load(file)) == NULL) {
        return false;
    }

    cSurface::transparent(sfEntity, 255, 0, 255);

    this->w = w;
    this->h = h;

    animControl.maxFrames = frames;

    return true;
}

void cEntity::loop() {
    animControl.animate();
}

void cEntity::render(SDL_Surface *display) {
    if (sfEntity == NULL || display == NULL) return;

    cSurface::draw(display, sfEntity, x, y, animState * w, animControl.getCurrentFrame() * h, w, h);
}

void cEntity::cleanup() {
    if (sfEntity) SDL_FreeSurface(sfEntity);

    sfEntity = NULL;
}
