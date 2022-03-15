#ifndef PROJ_2_BULLET_HELL_GAME_H
#define PROJ_2_BULLET_HELL_GAME_H

#include "ImageRenderer.h"
#include "sptr.h"

class Game {
private:
    sptr<ImageRenderer> imageRenderer;

public:
    void start();

private:
    void playLevel(int index);
};


#endif //PROJ_2_BULLET_HELL_GAME_H
