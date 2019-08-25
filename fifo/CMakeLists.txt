cmake_minimum_required(VERSION 3.6)

project (fifo)

add_executable(server fifoserver_main.c)
add_executable(client fifoclient_main.c)