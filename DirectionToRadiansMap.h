#ifndef PROJ_2_BULLET_HELL_DIRECTIONTORADIANSMAP_H
#define PROJ_2_BULLET_HELL_DIRECTIONTORADIANSMAP_H

#include "PlayerState.h"
#include <math.h>
#include "exceptions.h"

class DirectionToRadiansMap {
public:
    static double directionOf(PlayerState state);
};


#endif //PROJ_2_BULLET_HELL_DIRECTIONTORADIANSMAP_H
