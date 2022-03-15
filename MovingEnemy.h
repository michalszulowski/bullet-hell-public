#ifndef PROJ_2_BULLET_HELL_MOVINGENEMY_H
#define PROJ_2_BULLET_HELL_MOVINGENEMY_H

#include "Enemy.h"
#include "EnemyState.h"

class MovingEnemy : public Enemy {
private:
    sptr<Displayable> image;
    sptr<Displayable> shotSprite;
    EnemyState state;
    int movingAreaWidth;
    int movingAreaHeight;
    double distance;
    double movingSpeed;
    Coord startingPosition;

public:
    MovingEnemy(Coord startingPosition, sptr<Displayable> image, sptr<Displayable> shotSprite,
                int movingAreaWidth, int movingAreaHeight);
    void move(long inTime);
    SDL_Surface* getImage(long time);
};

#endif //PROJ_2_BULLET_HELL_MOVINGENEMY_H
