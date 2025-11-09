//
// Created by jorge on 10/20/2025.
//

#include<iostream>
#include "Timer.h"
using namespace std;

int main() {
    cout << "Welcome to Pomodoro Timer" << endl;
    Timer the_timer;
    the_timer.set_all(1,30);
    char input;

    the_timer.startTimer();
    cout << "Timer started for " << 1 << ":" << 30 <<endl;
    cout<<"This is where time happens "<<endl;
    while(true) {
        auto [curr_min, curr_sec] = the_timer.get_current_time();
        cout << curr_min << ":" << (curr_sec < 10 ? "0" : "") << curr_sec << endl;

        if(curr_min == 0 && curr_sec == 0) {
            cout << "Timer Finished" << endl;
            break;
        }
        this_thread::sleep_for(milliseconds(1000));
    }

    // cout << "begin\n";
    // int time_in_min = 3;
    // chrono::steady_clock::time_point tend = chrono::steady_clock::now()
    //                                             + chrono::minutes(time_in_min);
    // while (chrono::steady_clock::now() < tend) {
    //     cout << "Time left: "
    //      << chrono::duration_cast<chrono::minutes>(tend - chrono::steady_clock::now()).count()
    //      << " m | "
    //      << chrono::duration_cast<chrono::seconds>(tend - chrono::steady_clock::now()).count()%60
    //      << " s\n";
    //     this_thread::sleep_for(chrono::seconds(1));
    // }
}