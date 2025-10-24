//
// Created by jorge on 10/20/2025.
//

#include <iostream>
#include "Timer.h"


// Type determines whether it adds to work or break
void Timer::add_5_minutes(int type) {
    switch (type) {
        case WORK:
            work_timer += 5;
            break;
        case BREAK:
            break_timer += 5;
            break;
        default: ;
    }
}
void Timer::startTimer()
{
    int type = WORK; // initially will always be work
    // timer will alternate between work and break times (cycles) number of times
    for (int i = 0; i < cycles; i++) {
        toggle_timer(type);
        type = BREAK; // timer type switches to break
        toggle_timer(type);
    }
}

void Timer::toggle_timer(int type) {
    const int target_time = (type == BREAK) ? break_timer : work_timer;
    string type_debug = (type == BREAK) ? "Break" : "Work";
    current_timer = chrono::steady_clock::now() + chrono::minutes(target_time);
    while (chrono::steady_clock::now() < current_timer) {
        cout << type_debug <<" Time left: "
         << chrono::duration_cast<chrono::minutes>(current_timer - chrono::steady_clock::now()).count()
         << " m | "
         << chrono::duration_cast<chrono::seconds>(current_timer - chrono::steady_clock::now()).count()%60
         << " s\n";
        this_thread::sleep_for(chrono::seconds(1));
    }
}
