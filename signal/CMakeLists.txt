cmake_minimum_required(VERSION 3.6)

project (signal)

add_executable(signal signal_main.c)
add_executable(sigaction sigaction_main.c)