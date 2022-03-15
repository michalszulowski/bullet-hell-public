#include "gvector.h"
#include "exceptions.h"

GVector GVector::getZeroVector() {
    return GVector(0, 0);
}

GVector GVector::vectorOf(Direction direction) {
    switch (direction) {
    case NORTH:
        return GVector(0, -1);
    case EAST:
        return GVector(1, 0);
    case SOUTH:
        return GVector(0, 1);
    case WEST:
        return GVector(-1, 0);
    default:
        throw IllegalArgumentException();
    }
}

GVector GVector::movementVectorOf(PlayerState state) {
    switch (state) {
        case MOVING_UP:
            return GVector(0, -1);
        case MOVING_RIGHT:
            return GVector(1, 0);
        case MOVING_DOWN:
            return GVector(0, 1);
        case MOVING_LEFT:
            return GVector(-1, 0);
        default:
            return getZeroVector();
    }
}

