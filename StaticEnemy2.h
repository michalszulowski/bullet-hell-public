#ifndef PROJ_2_BULLET_HELL_STATICENEMY2_H
#define PROJ_2_BULLET_HELL_STATICENEMY2_H

#include "Enemy.h"

class StaticEnemy2 : public Enemy {
private:
    sptr<Displayable> image;
    sptr<Displayable> shotSprite;

public:
    StaticEnemy2(Coord startingPosition, sptr<Displayable> image, sptr<Displayable> shotSprite);
    void move(long inTime);
    SDL_Surface* getImage(long time);
};



#endif //PROJ_2_BULLET_HELL_STATICENEMY2_H
