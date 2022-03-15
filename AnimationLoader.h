#ifndef PROJ_2_BULLET_HELL_ANIMATIONLOADER_H
#define PROJ_2_BULLET_HELL_ANIMATIONLOADER_H

#include "Animation.h"
#include "BmpResourceManager.h"

class AnimationLoader {
private:
    sptr<BmpResourceManager> resourceManager;

public:
    AnimationLoader(sptr<BmpResourceManager> resourceManager);
    sptr<Displayable> loadOf(sptr<CharSeq> path1, sptr<CharSeq> path2, int changeFor);
};


#endif //PROJ_2_BULLET_HELL_ANIMATIONLOADER_H
