cmake_minimum_required(VERSION 3.9)
project(bowling)

set(CMAKE_CXX_STANDARD 11)

add_executable(bowling main.cpp Game.cpp Game.h Scorer.cpp Scorer.h)