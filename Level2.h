#ifndef PROJ_2_BULLET_HELL_LEVEL2_H
#define PROJ_2_BULLET_HELL_LEVEL2_H


#include "GameLevel.h"

class Level2 : public GameLevel {

public:
    Level2(sptr<Displayable> background, sptr<BmpResourceManager> resourceManager,
           sptr<ImageRenderer> imageRenderer);
protected:
    void initEnemy();
};


#endif //PROJ_2_BULLET_HELL_LEVEL2_H
