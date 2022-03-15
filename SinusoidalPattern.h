#ifndef PROJ_2_BULLET_HELL_SINUSOIDALPATTERN_H
#define PROJ_2_BULLET_HELL_SINUSOIDALPATTERN_H

#include "ShootingPattern.h"
#include "SinusoidalBullet.h"

class SinusoidalPattern : public ShootingPattern {
public:
    SinusoidalPattern(sptr<Displayable> bulletSprite, GameEntity* bulletSource) : ShootingPattern{bulletSprite, bulletSource} {
        numberOfBullets = 20;
    }

    sptr<Bullet> createBullet(int index) {
        sptr<Bullet> bullet = new SinusoidalBullet(getAngleOfBullet(index), bulletSource->getCentre(), bulletSprite);
        return bullet;
    }
};


#endif //PROJ_2_BULLET_HELL_SINUSOIDALPATTERN_H
