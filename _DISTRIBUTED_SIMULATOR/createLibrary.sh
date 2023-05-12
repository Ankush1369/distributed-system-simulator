#!/bin/bash
g++-12 -fPIC -c API.cpp _userProgram.cpp
g++-12 -fPIC -o libsim.so API.o _userProgram.o -shared