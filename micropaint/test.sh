#!/usr/bin/env bash

TEST_FILE="operation_file"

rm diff*

gcc -Wall -Werror -Wextra -g -fsanitize=address srcs/*.c -o mine
./mine $TEST_FILE > diff_mine
echo $?
./solution $TEST_FILE > diff_solution
echo $?
diff diff_mine diff_solution
