#ifndef PROJ_2_BULLET_HELL_TIMER_H
#define PROJ_2_BULLET_HELL_TIMER_H

//Stores time values in milliseconds
class Timer {
private:
    long start;
    long time = 0;
    long prevTime = 0;

public:
    void startCounting(long timeRec);
    void updateTime(long timeRec);
    long getTime();
    long getDelta();
    long getFromStart();
};


#endif //PROJ_2_BULLET_HELL_TIMER_H
