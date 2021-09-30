cmake_minimum_required(VERSION 3.17)
project(exam03 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Werror -Wextra -g -fsanitize=address")
set(SRCS_DIR_MINI minipaint/srcs)
set(SRCS_DIR_MICRO micropaint/srcs)
include_directories(include
        ${SRCS_DIR_MINI}
        ${SRCS_DIR_MICRO})

file(GLOB SRCS_MINI ${SRCS_DIR_MINI}/*.c)
file(GLOB SRCS_MICRO ${SRCS_DIR_MICRO}/*.c)
file(GLOB HEADERS_MINI minipaint/headers/*.h)
file(GLOB HEADERS_MICRO micropaint/headers/*.h)

add_executable(minipaint ${SRCS_MINI} ${HEADERS_MINI})
add_executable(micropaint ${SRCS_MICRO} ${HEADERS_MICRO})
