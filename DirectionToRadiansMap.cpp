#include "DirectionToRadiansMap.h"

double DirectionToRadiansMap::directionOf(PlayerState state) {
    switch (state) {
        case MOVING_RIGHT:
            return 0;
        case MOVING_DOWN:
            return (1.0/2.0) * M_PI;
        case MOVING_LEFT:
            return M_PI;
        case MOVING_UP:
            return (3.0/2.0) * M_PI;
        default:
            throw IllegalArgumentException();
    }
}