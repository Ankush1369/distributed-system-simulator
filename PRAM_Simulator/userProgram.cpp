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
        int* pi = new int;
        *pi = i;
        userSimulator.writeData(i, "value", pi);
    }
    userSimulator.stageComplete();

    for(int i=0; i<=log2(N); i++){
        int step = 1 << i;
        userSimulator.stageStart(); 
        for(int j=step; j<N; j++){
            userSimulator.readData(j, j-step, "value");
        }
        userSimulator.stageComplete();

        userSimulator.stageStart();
        for(int j=step; j<N; j++){
            int readValue = * (int *) userSimulator.getStoredValue(j);
            int* computedValue = new int;
            *computedValue = readValue + * (int *) userSimulator.getLocalValue(j, "value");
            userSimulator.writeData(j, "value", computedValue);

        }
        userSimulator.stageComplete();

    }


    userSimulator.stageStart();
    for(int i=0; i<N; i++){
        int localValue = * (int *) userSimulator.getLocalValue(i, "value");
        printf("%d ", localValue);
    }
    userSimulator.stageComplete();

}


