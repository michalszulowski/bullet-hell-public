#include "Bullet.h"

Bullet::Bullet(double angle, Coord startingPoint, sptr<Displayable> image) : GameEntity{16} {
    this->angle = angle;
    this->startingPoint = startingPoint;
    this->image = image;
    movementSpeedPerSecond = 70;
}

void Bullet::move(long inTime) {
    totalDistance += getDistanceToMove(inTime);
    double x = totalDistance;
    double y = patternFunction(x);
    Coord patternResult = Coord(x + startingPoint.x, y + startingPoint.y);
    Coord destination = patternResult.rotated(angle, startingPoint);
    setPosition(destination);
}

SDL_Surface *Bullet::getImage(long time) {
    return image->getImage(time);
}

float Bullet::getPower() {
    return power;
}

void Bullet::deactivate() {
    power = 0;
}

