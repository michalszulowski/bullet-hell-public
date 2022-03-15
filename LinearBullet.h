#ifndef PROJ_2_BULLET_HELL_LINEARBULLET_H
#define PROJ_2_BULLET_HELL_LINEARBULLET_H

#include "Bullet.h"

class LinearBullet : public Bullet {
public:
    LinearBullet(double angle, Coord startingPoint, sptr<Displayable> image);

protected:
    double patternFunction(double distance);
};


#endif //PROJ_2_BULLET_HELL_LINEARBULLET_H
