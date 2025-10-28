//
// Created by jorge on 10/20/2025.
//

#ifndef TIMER_H
#define TIMER_H

#include<chrono>
#include<thread>
using namespace std::chrono;



class Timer {
    // Default time values are: 5 minutes for work, 2 minutes for break
    // Default Cycles (times it goes through the work/break cycle)
    minutes i_minutes{};
    seconds i_seconds{};
    steady_clock::time_point current_time;

public:

    Timer() {
        i_minutes = minutes(5);
        i_seconds = seconds(0);
    }
    Timer(int m, int s);

    void set_all(int m, int s){
        this->i_minutes = minutes(m);
        this->i_seconds = seconds(s);

    }

    void set_minutes(int m) {
        this->i_minutes = minutes(m);
    }
    void set_seconds(int s) {
        this->i_seconds = seconds(s);
    }

    // Before Start Settings
    bool add_5_minutes();
    void startTimer();
    // While Timer Running Controls
    void add_5_minutes_curr();
    void toggle_timer(int type);
    void toggle_break_timer();

};



#endif //TIMER_H
