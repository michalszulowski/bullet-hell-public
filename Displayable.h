#ifndef PROJ_2_BULLET_HELL_DISPLAYABLE_H
#define PROJ_2_BULLET_HELL_DISPLAYABLE_H

#include "sdlinclude.h"

class Displayable {
public:
    virtual SDL_Surface* getImage(long time) = 0;
};

#endif //PROJ_2_BULLET_HELL_DISPLAYABLE_H
