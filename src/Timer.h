//
// Created by jorge on 10/20/2025.
//

#ifndef TIMER_H
#define TIMER_H

#include<chrono>
#include<thread>
using namespace std::chrono;



class Timer {
    // Minutes and seconds stored for pomodoro purposes
    // Total duration is used for actual timer countdown (in seconds)
    minutes i_minutes{};
    seconds i_seconds{};
    seconds total_duration{};
    steady_clock::time_point start_time;

public:

    Timer() {
        i_minutes = minutes(5);
        i_seconds = seconds(0);
        total_duration = i_minutes + i_seconds;
    }
    Timer(int m, int s);
    // Setters
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


    bool add_5_minutes();
    void startTimer();

    std::pair<int,int> get_current_time();
    bool is_finished();

};



#endif //TIMER_H
