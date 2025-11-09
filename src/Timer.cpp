//
// Created by jorge on 10/20/2025.
//

#include <iostream>
#include "Timer.h"


Timer::Timer(int m, int s) {
    this->i_minutes = minutes(m);
    this->i_seconds = seconds(s);
    is_paused = false;
    total_duration = i_minutes + i_seconds;
}

bool Timer::add_5_minutes() {
    // Timer will only be able to display 2 digits for minutes
    if (i_minutes >= minutes(95))
        return false;
    i_minutes += minutes(5);
    return true;
}

void Timer::startTimer()
{
    start_time = steady_clock::now();
}
void Timer::pause() {
    if (is_paused == true) return;
    pause_time = steady_clock::now();
    is_paused = true;
}
void Timer::resume() {
    if (is_paused == false) return;
    auto recent_pause = steady_clock::now() - pause_time;
    paused_duration += duration_cast<seconds>(recent_pause);
    is_paused = false;
}

// Returns time as a pair of (minutes, seconds)
std::pair<int,int> Timer :: get_current_time(){
    // raw times do not factor in the paused time
    auto raw_elapsed_time = steady_clock::now() - start_time;
    seconds effective_paused_duration = paused_duration;

    if (is_paused) {
        effective_paused_duration += duration_cast<seconds>(steady_clock::now() - pause_time);
    }
    auto effective_elapsed_time = raw_elapsed_time- effective_paused_duration;
    auto remaining_time = total_duration - effective_elapsed_time;

    if (remaining_time.count() <= 0) return {0,0};

    auto total_remaining_seconds = duration_cast<seconds>(remaining_time);
    int remaining_min = duration_cast<minutes>(total_remaining_seconds).count();
    int remaining_sec = (total_remaining_seconds % minutes(1)).count();

    return std::make_pair(remaining_min, remaining_sec);

}

bool Timer::subtract_minutes(int min) {
    if (i_minutes - minutes(min) < minutes(0)) return false;
    i_minutes -= minutes(min);
    return true;
}
bool Timer::subtract_seconds(int sec) {
    if (i_seconds - seconds(sec) < seconds(0)) return false;
    i_seconds -= seconds(sec);
    return true;
}

