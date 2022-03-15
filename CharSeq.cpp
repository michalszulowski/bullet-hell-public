#include "CharSeq.h"
#include "MathAndCalc.h"
#include <stdio.h>

CharSeq::CharSeq(const char *from) : ArrayList<char>(0) {
    int size = strlen(from);
    copyContentToNewArray(size);
    for (int i = 0; i < size; ++i) {
        this->append(from[i]);
    }
}

CharSeq::CharSeq(ArrayList<char> *from) : CharSeq{from, true} {}

CharSeq::CharSeq(ArrayList<char> *from, bool deleteFrom) : ArrayList<char>(0) {
    copyContentToNewArray(from->getSize());
    for (int i = 0; i < from->getSize(); ++i) {
        this->append(from->get(i));
    }
    if (deleteFrom) {
        delete from;
    }
}

bool CharSeq::equals(CharSeq *other) {
    if (this->getSize() != other->getSize())
        return false;
    for (int i = 0; i < this->getSize(); ++i) {
        if (this->charAt(i) != other->charAt(i))
            return false;
    }
    return true;
}


bool CharSeq::equals(const char *other) {
    CharSeq* otherSeq = new CharSeq(other);
    bool result = equals(otherSeq);
    delete otherSeq;
    return result;
}

char CharSeq::charAt(int index) {
    return get(index);
}

char CharSeq::set(int index, char newElement) {
    char oldElement = ArrayList::set(index, newElement);
    return oldElement;
}

char* CharSeq::asArray() {
    int charCount = getSize();
    char* arr = new char[charCount + 1];
    for (int i = 0; i < charCount; ++i) {
        arr[i] = charAt(i);
    }
    arr[charCount] = '\0';
    return arr;
}

sptr<CharSeq> CharSeq::getSptr(const char *of) {
    sptr<CharSeq> ptr = sptr<CharSeq>(new CharSeq(of));
    return ptr;
}

