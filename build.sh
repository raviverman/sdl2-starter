#!/usr/bin/env zsh

CC=gcc
SDL2_PATH=/opt/homebrew/Cellar/sdl2/2.30.2

$CC *.c -I$SDL2_PATH/include -L$SDL2_PATH/lib -o main -lSDL2
