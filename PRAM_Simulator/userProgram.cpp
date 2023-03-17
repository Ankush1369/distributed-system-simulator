#include <iostream>
#include "simulatorAPI.hpp"
#include <math.h>
using namespace std;

// void PRAM_Simulator()
// {   
//     int N = 20;
//     Simulator[2*N];
//     int stages = ceil((float)log2(2*N));
//     for(int i = 0; i<stages; i++){
//         Simulator.r
//     }
// }

void simulatorProgram(Simulator userSimulator){
    int N = 10;
    // userSimulator.Initialize(N);
    // userSimulator.stageStart();
    // for(int i=0; i<N; i++){
    //     userSimulator.writeData<string>(i, "name", "ankush");
    // }
    // userSimulator.stageComplete();
    
    // userSimulator.stageStart();
    // for(int i=0; i<N; i++){
    //     userSimulator.readData(i, i, "name");
    // }
    // userSimulator.stageComplete();

    userSimulator.Initialize(N);
    userSimulator.stageStart();
    for(int i=0; i<N; i++){
        userSimulator.writeData<int>(i, "value", i);
    }
    userSimulator.stageComplete();

    for(int i=0; i<=log2(N); i++){
        int step = 1 << i;
        userSimulator.stageStart(); 
        for(int j=step; j<N; j++){
            userSimulator.readData(j-step, j, "value");
        }
        userSimulator.stageComplete();

        userSimulator.stageStart();
        for(int j=step; j<N; j++){
            int readValue = * (int *) userSimulator.getStoredValue(j-step);
        }
    }


}


