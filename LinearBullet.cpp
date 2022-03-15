#include "LinearBullet.h"
#include <math.h>

LinearBullet::LinearBullet(double angle, Coord startingPoint, sptr<Displayable> image)
    : Bullet{angle, startingPoint, image} {
}

double LinearBullet::patternFunction(double distance) {
    return 0;
}