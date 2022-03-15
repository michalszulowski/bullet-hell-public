#ifndef PROJ_1_SHIPS_INTCOORD_H
#define PROJ_1_SHIPS_INTCOORD_H


struct IntCoord {
    int x;
    int y;

    IntCoord() : x{0}, y{0} {}
    IntCoord(int x, int y) : x{x}, y{y} {}
    IntCoord(const IntCoord &from) : x{from.x}, y{from.y} {}

    bool equals(IntCoord other) const {
        return this->x == other.x && this->y == other.y;
    }

    IntCoord& operator = (IntCoord const &obj) {
        this->x = obj.x;
        this->y = obj.y;
        return *this;
    }

    friend bool operator== (const IntCoord& c1, const IntCoord& c2) {
        return c1.x == c2.x && c1.y == c2.y;
    }
};

#endif //PROJ_1_SHIPS_INTCOORD_H