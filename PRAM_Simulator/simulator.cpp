#include <iostream>
#include "simulatorAPI.hpp"
using namespace std;

int x = 10;


int main(){
    Simulator mySimulator(4);
    simulatorProgram(mySimulator);
    return 0;
}

