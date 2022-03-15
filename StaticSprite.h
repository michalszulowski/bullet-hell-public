#ifndef PROJ_2_BULLET_HELL_STATICSPRITE_H
#define PROJ_2_BULLET_HELL_STATICSPRITE_H

#include "Displayable.h"

class StaticSprite : public Displayable {
private:
    SDL_Surface* image;

public:
    StaticSprite(SDL_Surface* image);
    SDL_Surface* getImage(long time);
};


#endif //PROJ_2_BULLET_HELL_STATICSPRITE_H
