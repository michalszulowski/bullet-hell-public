#ifndef PROJ_2_BULLET_HELL_GAMEPERFORMANCEMEASURER_H
#define PROJ_2_BULLET_HELL_GAMEPERFORMANCEMEASURER_H

#include "Timer.h"
#include "sptr.h"

class GamePerformanceMeasurer {
private:
    int frames = 0;
    int fpsTimer = 0;
    double fps = 0;
    sptr<Timer> timer;

public:
    GamePerformanceMeasurer(sptr<Timer> timer);
    void updateAfterLoop();
    double getFps();

};

#endif //PROJ_2_BULLET_HELL_GAMEPERFORMANCEMEASURER_H
