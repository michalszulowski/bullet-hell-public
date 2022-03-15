#ifndef MY_LIB_SPTR_H
#define MY_LIB_SPTR_H

template<class T>
//simple implementation of smart pointer
class sptr {
private:
    T* content = nullptr;
    int* numberOfReferences = nullptr;
    bool allocated = false;

public:
    sptr(T* content) {
        allocateMemory(content);
    }

    sptr() {}

    ~sptr() {
        if (allocated) {
            removeReferenceAndFreeMemoryIfNeeded();
        }
    }

    void copyFrom(T* otherContent, int* otherRefCount) {
        if (allocated) {
            removeReferenceAndFreeMemoryIfNeeded();
        }
        this->content = otherContent;
        this->numberOfReferences = otherRefCount;
        (*numberOfReferences)++;
        allocated = true;
    }

    sptr(const sptr<T>& other) {
        if (other.allocated) {
            copy(other);
        }
    }

    sptr& operator= (const sptr<T>& other) {
        if (this == &other)
            return *this;
        if (allocated) {
            removeReferenceAndFreeMemoryIfNeeded();
        }
        if (other.allocated) {
            copy(other);
        }
        return *this;
    }

    T& operator* () {
        return *content;
    }

    T* operator-> () {
        return content;
    }

    friend bool operator== (const sptr<T>& c1, const sptr<T>& c2) {
        return c1.content == c2.content;
    }

    T* getContent() {
        return content;
    }

    int* getNumberOfReferences() {
        return numberOfReferences;
    }

private:
    void removeReferenceAndFreeMemoryIfNeeded() {
        (*numberOfReferences)--;
        if ((*numberOfReferences) == 0) {
            freeMemory();
        }
    }

    void allocateMemory(T* forObject) {
        content = forObject;
        numberOfReferences = new int(1);
        allocated = true;
    }

    void copy(const sptr& from) {
        content = from.content;
        numberOfReferences = from.numberOfReferences;
        (*numberOfReferences)++;
        allocated = true;
    }

    void freeMemory() {
        delete content;
        delete numberOfReferences;
    }
};


#endif //MY_LIB_SPTR_H
