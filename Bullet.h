#ifndef PROJ_2_BULLET_HELL_BULLET_H
#define PROJ_2_BULLET_HELL_BULLET_H

#include "GameEntity.h"

class Bullet : public GameEntity {
    double angle; //in radians
    double totalDistance = 0;
    Coord startingPoint;
    sptr<Displayable> image;
    float power = 20;

public:
    Bullet(double angle, Coord startingPoint, sptr<Displayable> image);
    void move(long inTime);
    SDL_Surface* getImage(long time);
    virtual float getPower();
    void deactivate();

protected:
    virtual double patternFunction(double distance) = 0;
};


#endif //PROJ_2_BULLET_HELL_BULLET_H
