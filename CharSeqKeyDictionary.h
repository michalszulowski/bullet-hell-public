#ifndef PROJ_1_SHIPS_CHARSEQKEYDICTIONARY_H
#define PROJ_1_SHIPS_CHARSEQKEYDICTIONARY_H

#include "Dictionary.h"
#include "CharSeq.h"

template<class V>
class CharSeqKeyDictionary : public Dictionary<sptr<CharSeq>, V> {

protected:
    virtual bool equals(CharSeq* key1, CharSeq* key2) {
        return key1->equals(key2);
    }

public:
    ~CharSeqKeyDictionary() {}
};

#endif //PROJ_1_SHIPS_CHARSEQKEYDICTIONARY_H