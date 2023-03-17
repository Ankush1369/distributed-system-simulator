#!/bin/bash
./createLibrary.sh
g++-12 simulator.cpp -o mainBuild -lsim -I . -L .