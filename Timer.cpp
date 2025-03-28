//
// Created by Wh1tEW0lf13 on 28.03.2025.
//

#include "Timer.h"

#include <iostream>
#include <ostream>
#include <thread>
time_t t = 0;
std::thread counter;
bool isStopped = false;
void Timer::reset() {
    t = 0;
}
Timer::Timer() {
    reset();
}

void Timer::TimerCounter() {
    while (!isStopped) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        t++;
    }
}

int Timer::start() {
    std::thread counter(TimerCounter);
    counter.detach();
    return 0;
}
int Timer::stop() {
    isStopped = true;
    return 0;
}
int Timer::result() {
    return t;
}

