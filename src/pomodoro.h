//
// Created by jorge on 10/25/2025.
//

#ifndef POMODORO_H
#define POMODORO_H

#include "Timer.h"
class Pomodoro {
    // Default time values are: 5 minutes for work, 2 minutes for break
    // Default Cycles (times it goes through the work/break cycle)
    Timer work_timer;
    Timer break_timer;
    int cycles;

public:
    enum timer_type {
        WORK,
        BREAK
    };
    Pomodoro() {
      // Default -> work: 25 minutes, 0 seconds | break : 5 minutes, 0 seconds
      // 3 cycles
        this->work_timer.set_all(25,0);
        this->break_timer.set_all(5,0);
        this->cycles = 3;
    }
    // pair<minutes,seconds>
    Pomodoro(pair<int,int> work_time, pair<int,int> break_time, int num_cycles) {
        this->work_timer.set_all(work_time.first, work_time.second);
        this->break_timer.set_all(break_time.first, break_time.second);
        this->cycles = num_cycles;
    }
    void set_all(pair<int,int> work_time, pair<int,int> break_time, int num_cycles) {
        this->work_timer.set_all(work_time.first, work_time.second);
        this->break_timer.set_all(break_time.first, break_time.second);
        this->cycles = num_cycles;
    }

    void set_work_time(pair<int,int> new_time) {
        this->work_timer.set_all(new_time.first, new_time.second);
    }
    void set_break_time(pair<int,int> new_time) {
        this->break_timer.set_all(new_time.first, new_time.second);
    }
    void set_cycles(int new_time) {
        this->cycles = new_time;
    }
    // Before Start Settings
    void add_5_minutes(int type);
    void run_timer(Timer& focus_timer);
    // While Timer Running Controls
    void add_5_minutes_curr();
    void toggle_timer(int type);
    void toggle_break_timer();

};



#endif //TIMER_H

#endif //POMODORO_H
