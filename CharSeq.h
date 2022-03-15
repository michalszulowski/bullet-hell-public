#ifndef PROJ_1_SHIPS_CHARSEQ_H
#define PROJ_1_SHIPS_CHARSEQ_H

#include <string.h>
#include "ArrayList.h"
#include "sptr.h"

//simple class substituting string
class CharSeq : public ArrayList<char> {
public:
    CharSeq() {};
    CharSeq(int size) : ArrayList<char>{size} {};
    CharSeq(const char* from);
    CharSeq(ArrayList<char>* from);
    CharSeq(ArrayList<char>* from, bool deleteFrom);
    bool equals(CharSeq* other);
    bool equals(const char* other);
    char charAt(int index);
    char set(int index, char newElement);
    //returns dynamically allocated array;
    char* asArray();
};
#endif //PROJ_1_SHIPS_CHARSEQ_H