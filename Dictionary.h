#ifndef PROJ_1_SHIPS_DICTIONARY_H
#define PROJ_1_SHIPS_DICTIONARY_H

#include "UnorderedList.h"
#include "Pair.h"
#include "sptr.h"
#include "exceptions.h"

//Inefficient, simple dictionary implementation
template<class K, class V>
class Dictionary {
protected:
    sptr<UnorderedList<Pair<K,V>>> pairs;
public:
    Dictionary() {
        pairs = sptr<UnorderedList<Pair<K,V>>>(new UnorderedList<Pair<K,V>>());
    }

    ~Dictionary() {}

    void put(K key, V value) {
        pairs->append(Pair<K,V>(key, value));
    }

    V get(K key) {
        for (int i = 0; i < pairs->getSize(); i++) {
            Pair<K, V> pair = pairs->get(i);
            if (equals(pair.key, key)) {
                return pair.value;
            }
        }
        throw NoSuchElementException();
    }

    V remove(K key) {
        for (int i = 0; i < pairs->getSize(); i++) {
            Pair<K, V> pair = pairs->get(i);
            if (equals(pair.key, key)) {
                pairs->remove(i);
                return pair.value;
            }
        }
        throw NoSuchElementException();
    }

    bool isFree(K key) {
        try {
            get(key);
        } catch (const NoSuchElementException&) {
            return true;
        }
        return false;
    }

    sptr<UnorderedList<Pair<K,V>>> getPairList() {
        return pairs;
    }

protected:
    virtual bool equals(K key1, K key2) {
        return key1 == key2;
    }
};

#endif //PROJ_1_SHIPS_DICTIONARY_H