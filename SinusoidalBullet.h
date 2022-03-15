#ifndef PROJ_2_BULLET_HELL_SINUSOIDALBULLET_H
#define PROJ_2_BULLET_HELL_SINUSOIDALBULLET_H

#include "Bullet.h"

class SinusoidalBullet : public Bullet {
public:
    SinusoidalBullet(double angle, Coord startingPoint, sptr<Displayable> image);

protected:
    double patternFunction(double distance);
};


#endif //PROJ_2_BULLET_HELL_SINUSOIDALBULLET_H
