#ifndef PROJ_2_BULLET_HELL_LINEARPATTERN_H
#define PROJ_2_BULLET_HELL_LINEARPATTERN_H

#include "ShootingPattern.h"
#include "LinearBullet.h"

class LinearPattern : public ShootingPattern {
public:
    LinearPattern(sptr<Displayable> bulletSprite, GameEntity* bulletSource) : ShootingPattern{bulletSprite, bulletSource} {
        numberOfBullets = 20;
    }

    sptr<Bullet> createBullet(int index) {
        sptr<Bullet> bullet = new LinearBullet(getAngleOfBullet(index), bulletSource->getCentre(), bulletSprite);
        return bullet;
    }
};

#endif //PROJ_2_BULLET_HELL_LINEARPATTERN_H
