//
// Created by jorge on 10/20/2025.
//

#ifndef TIMER_H
#define TIMER_H

#include<chrono>
#include<thread>
using namespace std::chrono;
using namespace std;



class Timer {
    // Minutes and seconds stored for pomodoro purposes
    // Total duration is used for actual timer countdown (in seconds)
    minutes i_minutes{};
    seconds i_seconds{};

    seconds total_duration{};
    seconds paused_duration{};

    bool is_paused;

    steady_clock::time_point start_time;
    steady_clock::time_point pause_time;

public:

    Timer() {
        i_minutes = minutes(5);
        i_seconds = seconds(0);
        is_paused = false;
        total_duration = i_minutes + i_seconds;
    }
    Timer(int m, int s);
    // Setters //
    // Sets minutes and seconds
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
    void pause();
    void resume();

    std::pair<int,int> get_current_time();
    bool is_finished();
    // Debug

    bool subtract_minutes(int min);
    bool subtract_seconds(int sec);
};



#endif //TIMER_H
