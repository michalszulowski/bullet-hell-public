#ifndef PROJ_1_SHIPS_PAIR_H
#define PROJ_1_SHIPS_PAIR_H

template<class K, class V>
struct Pair {
    K key;
    V value;

    Pair(K key, V value) : key{key}, value{value} {}
    Pair() {};
    ~Pair() {};

    friend bool operator== (const Pair<K, V>& p1, const Pair<K, V>& p2) {
        return p1.key == p2.key && p2.value == p2.value;
    }
};
#endif //PROJ_1_SHIPS_PAIR_H