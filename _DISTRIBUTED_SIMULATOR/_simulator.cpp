#include <iostream>
#include "API.hpp"
#include <assert.h>
using namespace std;


int main(int argc, char* argv[]){
    assert(argc > 1);
    string inputGraph = argv[1];
    Simulator userSimulator(inputGraph);
    userProgram(userSimulator);
}