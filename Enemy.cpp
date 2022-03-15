#include "Enemy.h"

Enemy::Enemy(Coord startingPosition) : DieableEntity{0, 100} {
    this->setPosition(startingPosition);
}

sptr<List<sptr<Bullet>>> Enemy::shoot(long atTime) {
    long timeFromLastShot = atTime - lastTimeShot;
    if (timeFromLastShot >= shotFor) {
        changeShootingPatternIfTimeTo(atTime);
        lastTimeShot = atTime;
        return currentPattern->generateBullets();
    }
    return new EmptyList<sptr<Bullet>>;
}

void Enemy::changeShootingPatternIfTimeTo(long time) {
    long timeElapsed = time - lastTimePatternChanged;
    if (timeElapsed >= changePatternFor) {
        currentPattern = getNextPattern();
    }
}

sptr<ShootingPattern> Enemy::getNextPattern() {
    currentPatternIndex = (++currentPatternIndex) % shootingPatterns->getSize();
    return shootingPatterns->get(currentPatternIndex);
}
