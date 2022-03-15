#ifndef PROJ_2_BULLET_HELL_UNORDEREDLIST_H
#define PROJ_2_BULLET_HELL_UNORDEREDLIST_H

#include "ArrayList.h"

//allows removing elements
template<class E>
class UnorderedList : public ArrayList<E> {

public:
    UnorderedList() : ArrayList<E>{} {};
    UnorderedList(int size) : ArrayList<E>{size} {};
    ~UnorderedList() {};

    //moves last element into place of removed one
    E remove(int index) {
        this->checkIfIsWithinBounds(index);
        if (this->getSize() == 1) {
            E result = this->set(0, {});
            this->size--;
            return result;
        }
        E last = this->getLast();
        this->set(this->getSize() - 1, {});
        this->size--;
        return this->set(index, last);
    }
};

#endif //PROJ_2_BULLET_HELL_UNORDEREDLIST_H
