#include "GameEntity.h"
#include "MathAndCalc.h"
#include "MathConstants.h"

GameEntity::GameEntity(double radius) {
    this->radius = radius;
}

void GameEntity::moveBy(GVector vector) {
    centre = centre.movedBy(vector);
}

bool GameEntity::doesTouch(sptr<GameEntity> other) {
    double radiusSum = this->radius + other->radius;
    double distance = MathAndCalc::distance(this->centre, other->centre);
    return distance <= radiusSum;
}

Coord GameEntity::getCentre() {
    return centre;
}

void GameEntity::setPosition(Coord at) {
    centre = at;
}

double GameEntity::getMovementSpeedPerSecond() {
    return movementSpeedPerSecond;
}

double GameEntity::getDistanceToMove(long inTime) {
    return ((double) inTime / (double) MathConsts::SECOND) * movementSpeedPerSecond;
}
