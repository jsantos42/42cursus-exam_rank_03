#!/usr/bin/env bash

TEST_FILE="file1"

rm diff*

gcc -Wall -Werror -Wextra -g -fsanitize=address srcs/*.c -o micropaint
./micropaint $TEST_FILE > diff_meu
echo $?
./deles $TEST_FILE > diff_deles
echo $?
diff diff_meu diff_deles
