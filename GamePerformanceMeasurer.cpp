#include "GamePerformanceMeasurer.h"
#include <stdio.h>

GamePerformanceMeasurer::GamePerformanceMeasurer(sptr<Timer> timer) {
    this->timer = timer;
}

void GamePerformanceMeasurer::updateAfterLoop() {
    fpsTimer += timer->getDelta();
    if(fpsTimer > 500) {
        fps = frames * 2;
        frames = 0;
        fpsTimer = 0;
    };
    frames++;
}

double GamePerformanceMeasurer::getFps() {
    return fps;
}
