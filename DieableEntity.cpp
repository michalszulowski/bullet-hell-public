#include "DieableEntity.h"

DieableEntity::DieableEntity(double radius, double maxHp) : GameEntity{radius} {
    this->maxHP = maxHp;
    currentHP = maxHp;
}

void DieableEntity::receiveShot(double power, long atTime) {
    currentHP -= power;
}

double DieableEntity::getLifeFactor() {
    return ((double) currentHP) / ((double) maxHP);
}
