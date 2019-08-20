cmake_minimum_required(VERSION 3.6)

project (helloworld)

set(TARGET_NAME helloworld)

add_executable(${TARGET_NAME}
				helloworld_main.c
)