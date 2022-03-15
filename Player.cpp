#include "Player.h"
#include "MathConstants.h"
#include "DirectionToRadiansMap.h"

Player::Player(sptr<Displayable> image, sptr<Displayable> bulletSprite) : DieableEntity{0, 100} {
    this->currentSprite = image;
    this->bulletSprite = bulletSprite;
    state = STANDING;
    direction = MOVING_RIGHT;
    lastTimeShot = MathConsts::VERY_LOW_NUMBER;
    movementSpeedPerSecond = 300;
    invincibilityTime = 1000;
    standingDisplayable = currentSprite;
    movingRightDisplayable = currentSprite;
    movingDownDisplayable = currentSprite;
    movingLeftDisplayable = currentSprite;
    movingUpDisplayable = currentSprite;
}

void Player::move(long inTime) {
    double distance = getDistanceToMove(inTime);
    GVector vector = GVector::movementVectorOf(state);
    if (!vector.isZero()) {
        vector = vector.multipliedBy(distance);
        moveBy(vector);
        direction = state;
    }
}

void Player::setState(PlayerState state) {
    this->state = state;
    currentSprite = getDisplayableOfState();
}

SDL_Surface *Player::getImage(long time) {
    return currentSprite->getImage(time);
}

sptr<Bullet> Player::shoot(long atTime) {
    double angle = DirectionToRadiansMap::directionOf(direction);
    return new LinearBullet(angle, getCentre(), bulletSprite);
}

void Player::setStandingDisplayable(sptr<Displayable> displayable) {
    standingDisplayable = displayable;
}

void Player::setMovingRightDisplayable(sptr<Displayable> displayable) {
    movingRightDisplayable = displayable;
}

void Player::setMovingDownDisplayable(sptr<Displayable> displayable) {
    movingDownDisplayable = displayable;
}

void Player::setMovingLeftDisplayable(sptr<Displayable> displayable) {
    movingLeftDisplayable = displayable;
}

void Player::setMovingUpDisplayable(sptr<Displayable> displayable) {
    movingUpDisplayable = displayable;
}

sptr<Displayable> Player::getDisplayableOfState() {
    switch (state) {
        case STANDING:
            return standingDisplayable;
        case MOVING_RIGHT:
            return movingRightDisplayable;
        case MOVING_DOWN:
            return movingDownDisplayable;
        case MOVING_LEFT:
            return movingLeftDisplayable;
        case MOVING_UP:
            return movingUpDisplayable;
        default:
            return currentSprite;
    }
}

void Player::receiveShot(double power, long atTime) {
    if (atTime - lastTimeShot > invincibilityTime) {
        DieableEntity::receiveShot(power, atTime);
        lastTimeShot = atTime;
    }
}

int Player::getPoints() {
    return points;
}

void Player::addPoints(double basicValue, long time) {
    points += basicValue;
}