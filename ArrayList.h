#ifndef PROJ_1_SHIPS_ARRAYLIST_H
#define PROJ_1_SHIPS_ARRAYLIST_H

#include "List.h"
#include "exceptions.h"

template<class E>
class ArrayList : public List<E>{
protected:
    E* valArray;
    int arraySize;
    int size = 0;
    const int DEFAULT_INIT_ARRAY_SIZE = 10;

public:
    ArrayList(int initArraySize) {
        arraySize = initArraySize;
        init();
    }

    ArrayList() {
        arraySize = DEFAULT_INIT_ARRAY_SIZE;
        init();
    }
    
    ~ArrayList() {
        delete [] valArray;
    }
    
    bool contains(E element) {
        for (int i = 0; i < size; i++) {
            if (valArray[i] == element) {
                return true;
            }
        }
        return false;
    }

    bool containsAny(sptr<List<E>> from) {
        for (int i = 0; i < getSize(); ++i) {
            for (int j = 0; j < from->getSize(); ++j) {
                if (this->get(i) == from->get(j))
                    return true;
            }
        }
        return false;
    }

    //returns: element added
    bool append(E element) {
        if (size == arraySize) {
            copyContentToNewArray();
        }
        valArray[size] = element;
        size++;
        return true;
    }

    //returns: old element
    virtual E set(int index, E newElement) {
        E oldElement = get(index);
        valArray[index] = newElement;
        return oldElement;
    }

    E get(int index) {
        checkIfIsWithinBounds(index);
        return valArray[index];
    }
     
    E getFirst() {
        return get(0);
    }
    
    E getLast() {
        return get(getSize() - 1);
    }
    
    int getSize() {
        return size;
    }
    
    virtual sptr<List<E>> subList(int start, int end) {
        int newSize = end - start;
        sptr<List<E>> sub = sptr<List<E>>(new ArrayList<E>(newSize));
        for (int i = 0; i < newSize; ++i) {
            sub->append(this->get(start + i));
        }
        return sub;
    }
    
    void addAll(sptr<List<E>> list) {
        int newSize = this->size + list->getSize();
        if (newSize > arraySize) {
            copyContentToNewArray(newSize);
        }
        for (int i = 0; i < list->getSize(); ++i) {
            this->append(list->get(i));
        }
    }
    
    bool isEmpty() {
        return getSize() == 0;
    }

protected:
    
    void init() {
        valArray = new E[arraySize];
    }
    
    void copyContentToNewArray() {
        const int SIZE_MULTIPLIER = 2;
        int newArraySize = arraySize * SIZE_MULTIPLIER;
        copyContentToNewArray(newArraySize);
    }
    
    void copyContentToNewArray(int newArraySize) {
        E* newArray = new E[newArraySize];
        for (int i = 0; i < arraySize; i++) {
            newArray[i] = valArray[i];
        }
        delete [] valArray;
        valArray = newArray;
        arraySize = newArraySize;
    }
    
    void checkIfIsWithinBounds(int index) {
        if (index >= size || index < 0) {
            throw IncorrectIndexException();
        }
    }
};


#endif //PROJ_1_SHIPS_ARRAYLIST_H
