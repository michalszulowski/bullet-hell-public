#ifndef PROJ_1_SHIPS_COORD_H
#define PROJ_1_SHIPS_COORD_H
#include "direction.h"
#include "gvector.h"
#include <math.h>

struct Coord {
    double x;
    double y;

    Coord() : x{0}, y{0} {}
    Coord(double x, double y) : x{x}, y{y} {}
    Coord(const Coord &from) : x{from.x}, y{from.y} {}

    Coord movedBy(GVector v) const {
        return Coord(x + v.x, y + v.y);
    }

    bool equals(Coord other) const {
        return this->x == other.x && this->y == other.y;
    }

    Coord& operator = (Coord const &obj) {
        this->x = obj.x;
        this->y = obj.y;
        return *this;
    }

    friend bool operator== (const Coord& c1, const Coord& c2) {
        return c1.x == c2.x && c1.y == c2.y;
    }

    Coord rotated(double by, Coord around) {
        double rX = (x - around.x) * cos(by) - (y - around.y) * sin(by);
        double rY = (x - around.x) * sin(by) + (y - around.y) * cos(by);
        return Coord(rX + around.x, rY + around.y);
    }
};

#endif //PROJ_1_SHIPS_COORD_H