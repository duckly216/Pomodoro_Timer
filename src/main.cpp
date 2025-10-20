//
// Created by jorge on 10/20/2025.
//
#include "Timer.h"
#include<iostream>

using namespace std;

int main() {
    Timer timer;
    timer.startTimer(0);

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