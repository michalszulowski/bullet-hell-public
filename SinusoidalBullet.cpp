#include "SinusoidalBullet.h"
#include <math.h>

SinusoidalBullet::SinusoidalBullet(double angle, Coord startingPoint, sptr<Displayable> image)
        : Bullet{angle, startingPoint, image} {
}

double SinusoidalBullet::patternFunction(double distance) {
    return 10 * sin(distance/15);
}