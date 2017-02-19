#!/bin/bash

# Takes in a string that represents the program as input
make
./main <<< $1 > test.asm
nasm -felf64 test.asm
gcc test.o -o test
gdb test
