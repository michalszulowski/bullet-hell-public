#include "ExponentialBullet.h"
#include <math.h>

ExponentialBullet::ExponentialBullet(double angle, Coord startingPoint, sptr<Displayable> image)
        : Bullet{angle, startingPoint, image} {
}

double ExponentialBullet::patternFunction(double distance) {
    return pow(2, distance/20) / 15;
    //return 1 / (distance + 0.001);
}