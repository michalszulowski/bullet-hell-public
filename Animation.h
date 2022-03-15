#ifndef PROJ_2_BULLET_HELL_ANIMATION_H
#define PROJ_2_BULLET_HELL_ANIMATION_H

#include "ArrayList.h"
#include "sdlinclude.h"
#include "Displayable.h"

class Animation : public Displayable {
private:
    sptr<ArrayList<SDL_Surface*>> sprites;
    long changeSpriteFor;
    int numberOfSprites;

public:
    Animation(sptr<ArrayList<SDL_Surface*>> sprites, long changeSpriteFor);
    SDL_Surface* getImage(long time);
};


#endif //PROJ_2_BULLET_HELL_ANIMATION_H
