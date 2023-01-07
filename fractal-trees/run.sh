#!/usr/bin/env bash
NAME=sfml

g++ -Wall -O3 $NAME.cpp -o $NAME -lsfml-graphics -lsfml-window -lsfml-system && ./$NAME
