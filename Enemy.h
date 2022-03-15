#ifndef PROJ_2_BULLET_HELL_ENEMY_H
#define PROJ_2_BULLET_HELL_ENEMY_H

#include "DieableEntity.h"
#include "EmptyList.h"
#include "Bullet.h"
#include "ShootingPattern.h"

class ShootingPattern;

class Enemy : public DieableEntity {
private:
    long lastTimeShot = 0;

protected:
    sptr<ArrayList<sptr<ShootingPattern>>> shootingPatterns;
    sptr<ShootingPattern> currentPattern;
    int currentPatternIndex = 0;
    long changePatternFor;
    long lastTimePatternChanged = 0;
    long shotFor;

public:
    Enemy(Coord startingPosition);
    sptr<List<sptr<Bullet>>> shoot(long atTime);

private:
    void changeShootingPatternIfTimeTo(long time);
    sptr<ShootingPattern> getNextPattern();
};


#endif //PROJ_2_BULLET_HELL_ENEMY_H
