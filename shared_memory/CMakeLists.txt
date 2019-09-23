cmake_minimum_required(VERSION 3.6)

project (shared_memory)

add_executable(shmclient shmclient_main.c)
add_executable(shmserver shmserver_main.c)
