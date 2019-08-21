cmake_minimum_required(VERSION 3.6)

project (fifo)

add_executable(fifoserver fifoserver_main.c)
add_executable(fifoclient fifoclient_main.c)