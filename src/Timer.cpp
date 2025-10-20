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
void Timer::startTimer(int type)
{
    const int target_time = (type == BREAK) ? break_timer : work_timer;
    current_timer = chrono::steady_clock::now() + chrono::minutes(target_time);
    while (chrono::steady_clock::now() < current_timer) {
        cout << "Time left: "
         << chrono::duration_cast<chrono::minutes>(current_timer - chrono::steady_clock::now()).count()
         << " m | "
         << chrono::duration_cast<chrono::seconds>(current_timer - chrono::steady_clock::now()).count()%60
         << " s\n";
        this_thread::sleep_for(chrono::seconds(1));
    }
}