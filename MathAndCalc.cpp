#include "MathAndCalc.h"
#include "exceptions.h"
#include <math.h>

int MathAndCalc::numberOfDigits(int n) {
    if (n == 0) {
        return 1;
    }
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

CharSeq* MathAndCalc::numberAsCharSeq(int number, int numberOfChars) {
    int numberOfDigits = MathAndCalc::numberOfDigits(number);
    if (numberOfDigits > numberOfChars)
        throw IllegalArgumentException();
    CharSeq* result = new CharSeq(numberOfChars);
    const char ZERO = '0';
    for (int i = 0; i < numberOfChars; ++i) {
        result->append(ZERO);
    }
    for (int i = 0; i < numberOfDigits; i++) {
        int digit = number % 10;
        number /= 10;
        char character = ZERO + digit;
        int index = numberOfChars - 1 - i;
        result->set(index, character);
    }
    return result;
}

CharSeq *MathAndCalc::numberAsCharSeq(int number) {
    return numberAsCharSeq(number, numberOfDigits(number));
}

int MathAndCalc::valueOf(char c) {
    int code = int(c);
    if (code > '9' || code < '0')
        throw CharNotADigitException();
    return code - '0';
}

int MathAndCalc::valueOf(CharSeq *seq) {
    if (seq->getSize() == 0)
        throw IllegalArgumentException();
    int val = 0;
    int multiplier = 1;
    for (int i = seq->getSize() - 1; i >= 0; --i) {
        int digit = valueOf(seq->get(i));
        int digitMeaning = digit * multiplier;
        val += digitMeaning;
        multiplier *= 10;
    }
    return val;
}

double MathAndCalc::distance(Coord c1, Coord c2) {
    double xDiff = c1.x - c2.x;
    double yDiff = c1.y - c2.y;
    double squareSum = xDiff * xDiff + yDiff * yDiff;
    return sqrt(squareSum);
}
