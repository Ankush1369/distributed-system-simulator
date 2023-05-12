#!/bin/bash
./createLibrary.sh
g++-12 _simulator.cpp -o mainBuild -lsim -I . -L .