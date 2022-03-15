#ifndef PROJ_2_BULLET_HELL_EMPTYLIST_H
#define PROJ_2_BULLET_HELL_EMPTYLIST_H

#include "List.h"
#include "exceptions.h"

template<class E>
class EmptyList : public List<E>{
public:
    EmptyList() {};
    ~EmptyList() {};

    bool contains(E element) {
        return false;
    }

    bool containsAny(sptr<List<E>> from) {
        return false;
    }

    bool append(E element) {
        throw IllegalOperationException();
    }

    E set(int index, E newElement) {
        throw IllegalOperationException();
    }

    E get(int index) {
        throw IllegalOperationException();
    }

    E getFirst() {
        throw IllegalOperationException();
    }

    E getLast() {
        throw IllegalOperationException();
    }

    int getSize() {
        return 0;
    }

    virtual sptr<List<E>> subList(int start, int end) {
        return new EmptyList<E>();
    }

    void addAll(sptr<List<E>> list) {
        throw IllegalOperationException();
    }

    bool isEmpty() {
        return true;
    }
};

#endif //PROJ_2_BULLET_HELL_EMPTYLIST_H
