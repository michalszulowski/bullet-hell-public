#ifndef PROJ_1_SHIPS_MATHANDCALC_H
#define PROJ_1_SHIPS_MATHANDCALC_H
#include <string.h>
#include "CharSeq.h"
#include "Coord.h"

class CharSeq;

class MathAndCalc {
public:
    static int numberOfDigits(int n);
    static CharSeq* numberAsCharSeq(int number, int numberOfChars);
    static CharSeq* numberAsCharSeq(int number);
    static int valueOf(char c);
    static int valueOf(CharSeq* seq);
    static double distance(Coord c1, Coord c2);
};

#endif //PROJ_1_SHIPS_MATHANDCALC_H