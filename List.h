#ifndef PROJ_2_BULLET_HELL_LIST_H
#define PROJ_2_BULLET_HELL_LIST_H

#include "sptr.h"

//simple list interface
template<class E>
class List {
public:
    virtual bool contains(E element) = 0;
    virtual bool containsAny(sptr<List<E>> from) = 0;
    //returns: element added
    virtual bool append(E element) = 0;
    //returns: old element
    virtual E set(int index, E newElement) = 0;
    virtual E get(int index) = 0;
    virtual E getFirst() = 0;
    virtual E getLast() = 0;
    virtual int getSize() = 0;
    virtual sptr<List<E>> subList(int start, int end) = 0;
    virtual void addAll(sptr<List<E>> list) = 0;
    virtual bool isEmpty() = 0;
};

#endif //PROJ_2_BULLET_HELL_LIST_H
