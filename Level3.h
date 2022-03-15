#ifndef PROJ_2_BULLET_HELL_LEVEL3_H
#define PROJ_2_BULLET_HELL_LEVEL3_H

#include "GameLevel.h"

class Level3 : public GameLevel {

public:
    Level3(sptr<Displayable> background, sptr<BmpResourceManager> resourceManager,
           sptr<ImageRenderer> imageRenderer);
protected:
    void initEnemy();
};


#endif //PROJ_2_BULLET_HELL_LEVEL3_H
