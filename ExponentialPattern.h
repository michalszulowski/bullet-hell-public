#ifndef PROJ_2_BULLET_HELL_EXPONENTIALPATTERN_H
#define PROJ_2_BULLET_HELL_EXPONENTIALPATTERN_H

#include "ShootingPattern.h"
#include "ExponentialBullet.h"

class ExponentialPattern : public ShootingPattern {
public:
    ExponentialPattern(sptr<Displayable> bulletSprite, GameEntity* bulletSource) : ShootingPattern{bulletSprite, bulletSource} {
        numberOfBullets = 20;
    }

    sptr<Bullet> createBullet(int index) {
        sptr<Bullet> bullet = new ExponentialBullet(getAngleOfBullet(index), bulletSource->getCentre(), bulletSprite);
        return bullet;
    }
};

#endif //PROJ_2_BULLET_HELL_EXPONENTIALPATTERN_H
