#ifndef PROJ_2_BULLET_HELL_EXPONENTIALBULLET_H
#define PROJ_2_BULLET_HELL_EXPONENTIALBULLET_H

#include "Bullet.h"

class ExponentialBullet : public Bullet {
public:
    ExponentialBullet(double angle, Coord startingPoint, sptr<Displayable> image);

protected:
    double patternFunction(double distance);
};


#endif //PROJ_2_BULLET_HELL_EXPONENTIALBULLET_H
