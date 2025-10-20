//
// Created by jorge on 10/20/2025.
//

#ifndef TIMER_H
#define TIMER_H

#include<chrono>
#include<thread>
using namespace std;


class timer {
    // Default time values are: 5 minutes for work, 2 minutes for break
    // Default Cycles (times it goes through the work/break cycle)
    int work_timer = 5;
    int break_timer = 2;
    int cycles = 4;
    auto current_timer = chrono::minutes(0);

    timer(int work_time, int break_time, int num_cycles) {
        this->work_timer = work_time;
        this->break_timer = break_time;
        this->cycles = num_cycles;
    }
    // Before Start Settings
    void add_5_minutes();
    // While Timer Running Controls
    void add_5_minutes_curr();
    void toggle_work_timer();
    void toggle_break_timer();

};



#endif //TIMER_H
