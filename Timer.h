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

    static void reset(); // Reset timer.
    static int start(); // Start timer.
    static int stop(); // Stop timer.
    static time_t result(); // Return elapsed time [ms].
};



#endif //TIMER_H
