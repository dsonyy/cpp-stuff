#!/usr/bin/env bash
# gcc -std=gnu17 -E -o build/preprocessor.c *.c
gcc -std=gnu17 -Wall -o build/build.out *.c -lm && ./build/build.out < in