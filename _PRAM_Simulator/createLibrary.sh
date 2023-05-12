#!/bin/bash
g++-12 -fPIC -c simulatorAPI.cpp userProgram.cpp 
g++-12 -fPIC -o libsim.so simulatorAPI.o userProgram.o -shared 