#ifndef PROJ_2_BULLET_HELL_BOARDENTITY_H
#define PROJ_2_BULLET_HELL_BOARDENTITY_H

#include "Coord.h"
#include "Displayable.h"
#include "sptr.h"

//Represents circular game objects
class GameEntity : public Displayable {
private:
    Coord centre;
    double radius;
protected:
    double movementSpeedPerSecond;

public:
    GameEntity(double radius);
    virtual void move(long inTime) = 0;
    bool doesTouch(sptr<GameEntity> other);
    Coord getCentre();
    void setPosition(Coord at);
    double getMovementSpeedPerSecond();
    double getDistanceToMove(long inTime);

protected:
    void moveBy(GVector vector);
};

#endif //PROJ_2_BULLET_HELL_BOARDENTITY_H
