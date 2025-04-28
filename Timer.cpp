//
// Created by Wh1tEW0lf13 on 28.03.2025.
//

#include "Timer.h"
#include <chrono>
std::chrono::milliseconds startTime, stopTime, timeResult;
void Timer::reset() {
    startTime = stopTime = timeResult = std::chrono::milliseconds(0);
}
Timer::Timer() {
    reset();
}

int Timer::start() {
    startTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    return 1;
}
int Timer::stop() {
    stopTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    timeResult = stopTime-startTime;
    return 1;
}
int Timer::result() {
    return static_cast<int>(timeResult.count());
}

