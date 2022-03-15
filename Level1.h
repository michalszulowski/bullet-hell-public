#ifndef PROJ_2_BULLET_HELL_LEVEL1_H
#define PROJ_2_BULLET_HELL_LEVEL1_H

#include "GameLevel.h"

class Level1 : public GameLevel {

public:
    Level1(sptr<Displayable> background, sptr<BmpResourceManager> resourceManager,
            sptr<ImageRenderer> imageRenderer);
protected:
    void initEnemy();
};


#endif //PROJ_2_BULLET_HELL_LEVEL1_H
