#include "Timer.h"

void Timer::updateTime(long timeRec) {
    this->prevTime = this->time;
    this->time = timeRec;
}

void Timer::startCounting(long timeRec) {
    this->start = timeRec;
    this->prevTime = timeRec;
    this->time = timeRec;
}

long Timer::getTime() {
    return time;
}

long Timer::getDelta() {
    return time - prevTime;
}

long Timer::getFromStart() {
    return time - start;
}
