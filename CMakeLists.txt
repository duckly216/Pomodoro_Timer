cmake_minimum_required(VERSION 3.30)
project(Pomodoro_Timer)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(Pomodoro_Timer
    src/pomodoro.cpp
    src/timer.cpp
    src/timer.h)
