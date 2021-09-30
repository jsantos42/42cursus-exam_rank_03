#!/usr/bin/env bash

TEST_FILE="file1"

rm diff*

gcc -Wall -Werror -Wextra -g -fsanitize=address srcs/*.c -o mine
./mine $TEST_FILE > diff_mine
echo $?
./solution $TEST_FILE > diff_solution
echo $?
diff diff_mine diff_solution
