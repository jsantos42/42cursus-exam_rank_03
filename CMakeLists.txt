cmake_minimum_required(VERSION 3.17)
project(micropaint C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Werror -Wextra -g -fsanitize=address")
set(SRCS_DIR srcs)
include_directories(include
        ${SRCS})

file(GLOB SRCS ${SRCS_DIR}/*.c)
file(GLOB INCLUDES headers/*.h)

add_executable(micropaint ${SRCS} ${INCLUDES})
