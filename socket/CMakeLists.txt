cmake_minimum_required(VERSION 3.6)

project (socket)

add_executable(socketserver socketserver_main.c)
add_executable(socketclient socketclient_main.c)
