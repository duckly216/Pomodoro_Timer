//
// Created by jorge on 10/20/2025.
//

#include<iostream>
#include "Timer.h"
using namespace std;

int main() {
    cout << "Welcome to Pomodoro Timer" << endl;
    Timer the_timer;
    the_timer.set_all(0,5);
    Timer break_timer;
    break_timer.set_all(0,8);

    bool on_break = false;
    int loops = 2;
    char input;

    for (int i = 1; i <= loops * 2; i++) {
        cout<<"This is where "<< (on_break ? "break": "work") <<" time happens "<<endl;
        Timer& focus = on_break ? break_timer : the_timer;
        focus.startTimer();
        while (true){
            // cout << "Timer started for " << 0 << ":" << 05 <<endl;


            auto [curr_min, curr_sec] = focus.get_current_time();
            cout << curr_min << ":" << (curr_sec < 10 ? "0" : "") << curr_sec << endl;

            if(curr_min == 0 && curr_sec == 0) {
                cout << "Timer Finished" << endl;
                break;
            }
            this_thread::sleep_for(milliseconds(900));
        }
        on_break = !on_break;
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