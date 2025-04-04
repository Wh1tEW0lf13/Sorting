//
// Created by Wh1tEW0lf13 on 28.03.2025.
//

#include "Timer.h"

#include <iostream>
#include <ostream>
#include <thread>
time_t startTime, stopTime, timeResult;
void Timer::reset() {
    timeResult = 0.0;
}
Timer::Timer() {
    reset();
}

int Timer::start() {
    time (&startTime);
    return 1;
}
int Timer::stop() {
    time (&stopTime);
    timeResult = stopTime-startTime;
    return 0;
}
time_t Timer::result() {
    return timeResult;
}

