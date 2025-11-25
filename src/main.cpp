//
// Created by jorge on 10/20/2025.
//

#include<iostream>
#include "Timer.h"
using namespace std;
void run_timer(Timer& focus) {
    focus.startTimer();
    auto [initial_min, initial_sec] = focus.get_current_time();
    cout << initial_min << ":" << (initial_sec < 10 ? "0" : "") << initial_sec << endl;

    while (true){
        this_thread::sleep_for(milliseconds(1000));
        auto [curr_min, curr_sec] = focus.get_current_time();
        cout << curr_min << ":" << (curr_sec < 10 ? "0" : "") << curr_sec << endl;
        if(curr_min == 0 && curr_sec == 0) {
            cout << "Timer Finished" << endl;
            break;
        }

    }
}
int main() {
    cout << "Welcome to Pomodoro Timer" << endl;
    Timer the_timer;
    the_timer.set_all(0,6);
    Timer break_timer;
    break_timer.set_all(0,8);

    bool on_break = false;
    int loops = 2;
    char input;

    for (int i = 1; i <= loops; i++) {
        cout<< "Loop: " << i << endl;
        cout << "Work Timer" << endl;
        run_timer(the_timer);
        if (i != loops) {
            cout << "Break Timer" << endl;
            run_timer(break_timer);
        }

    }
}