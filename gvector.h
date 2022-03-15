#ifndef PROJ_1_SHIPS_GVECTOR_H
#define PROJ_1_SHIPS_GVECTOR_H
#include "direction.h"
#include "PlayerState.h"
#include <math.h>

struct GVector {
    double x, y;

    GVector(double x, double y) : x{x}, y{y} {};

    ~GVector() {}

    GVector opposite() {
        return GVector(-x, -y);
    }

    GVector multipliedBy(double scalar) {
        return GVector(scalar * x, scalar * y);
    }

    GVector& operator=(const GVector& other) {
        x = other.x;
        y = other.y;
        return *this;
    }

    bool isZero() {
        const double MARGIN = 0.00001;
        double xAbs = abs(x);
        double yAbs = abs(y);
        return (xAbs < MARGIN) && (yAbs < MARGIN);
    }

    static GVector vectorOf(Direction direction);
    static GVector movementVectorOf(PlayerState direction);
    static GVector getZeroVector();
};
#endif //PROJ_1_SHIPS_GVECTOR_H