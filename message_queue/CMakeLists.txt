cmake_minimum_required(VERSION 3.6)

project (message_queue)

add_executable(msqsnd msqsnd_main.c)
add_executable(msqrcv msqrcv_main.c)
