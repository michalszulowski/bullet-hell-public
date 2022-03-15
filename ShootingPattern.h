#ifndef PROJ_2_BULLET_HELL_SHOOTINGPATTERN_H
#define PROJ_2_BULLET_HELL_SHOOTINGPATTERN_H

#include "Bullet.h"
#include "ArrayList.h"
#include "Enemy.h"

class ShootingPattern {
protected:
    sptr<Displayable> bulletSprite;
    GameEntity* bulletSource;
    int numberOfBullets;

public:
    ShootingPattern(sptr<Displayable> bulletSprite, GameEntity* bulletSource);
    sptr<List<sptr<Bullet>>> generateBullets();

protected:
    virtual sptr<Bullet> createBullet(int index) = 0;
    double getAngleOfBullet(int ith);
};


#endif //PROJ_2_BULLET_HELL_SHOOTINGPATTERN_H
