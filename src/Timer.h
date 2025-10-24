//
// Created by jorge on 10/20/2025.
//

#ifndef TIMER_H
#define TIMER_H

#include<chrono>
#include<thread>
using namespace std;



class Timer {
    // Default time values are: 5 minutes for work, 2 minutes for break
    // Default Cycles (times it goes through the work/break cycle)
    int work_timer;
    int break_timer;
    int cycles;
    chrono::steady_clock::time_point current_timer = chrono::steady_clock::now();

public:
    enum timer_type {
        WORK,
        BREAK
    };
    Timer() {
        this->work_timer = 5;
        this->break_timer = 2;
        this->cycles = 4;
    }
    Timer(int work_time, int break_time, int num_cycles) {
        this->work_timer = work_time;
        this->break_timer = break_time;
        this->cycles = num_cycles;
    }
    void set_cycles(int num_cycles) {
        this->cycles = num_cycles;
    }
    void set_work_time(int new_time) {
        this->work_timer = new_time;
    }
    void set_break_time(int new_time) {
        this->break_timer = new_time;
    }
    // Before Start Settings
    void add_5_minutes(int type);
    void startTimer();
    // While Timer Running Controls
    void add_5_minutes_curr();
    void toggle_timer(int type);
    void toggle_break_timer();

};



#endif //TIMER_H
