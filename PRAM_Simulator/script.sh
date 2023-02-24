#!/bin/bash
g++-12 -fPIC -c pramhelper.cpp simulator.cpp 
g++-12 -fPIC -o libsim.so pramhelper.o simulator.o -shared 