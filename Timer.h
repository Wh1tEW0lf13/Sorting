//
// Created by Wh1tEW0lf13 on 28.03.2025.
//

#ifndef TIMER_H
#define TIMER_H
#include <ctime>
#include <thread>


class Timer {
public:
    Timer(); // Initialize and prepare to start.

    void reset(); // Reset timer.
    int start(); // Start timer.
    int stop(); // Stop timer.
    int result(); // Return elapsed time [ms].
};



#endif //TIMER_H
