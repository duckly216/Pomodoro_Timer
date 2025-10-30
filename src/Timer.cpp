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

// Type determines whether it adds to work or break
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
    paused_duration = paused_duration + (recent_pause);
    is_paused = false;
}

std::pair<int,int> Timer :: get_current_time(){
    auto elapsed_time = steady_clock::now() - start_time;
    auto remaining_time = total_duration - elapsed_time;
    if (remaining_time.count() <= 0) return {0,0};
}
// void Timer::toggle_timer(int type) {
//     const int target_time = (type == BREAK) ? break_timer : work_timer;
//     string type_debug = (type == BREAK) ? "Break" : "Work";
//     current_timer = chrono::steady_clock::now() + chrono::minutes(target_time);
//     while (chrono::steady_clock::now() < current_timer) {
//         cout << type_debug <<" Time left: "
//          << chrono::duration_cast<chrono::minutes>(current_timer - chrono::steady_clock::now()).count()
//          << " m | "
//          << chrono::duration_cast<chrono::seconds>(current_timer - chrono::steady_clock::now()).count()
//          << " s\n";
//         this_thread::sleep_for(chrono::seconds(1));
//     }
// }
