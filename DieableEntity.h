#ifndef PROJ_2_BULLET_HELL_DIEABLEENTITY_H
#define PROJ_2_BULLET_HELL_DIEABLEENTITY_H

#include "GameEntity.h"

class DieableEntity : public GameEntity {
    double maxHP;
    double currentHP;

public:
    DieableEntity(double radius, double maxHp);
    virtual void receiveShot(double power, long atTime);
    double getLifeFactor();

};


#endif //PROJ_2_BULLET_HELL_DIEABLEENTITY_H
