#include <iostream>
#include "simulatorAPI.hpp"
#include <math.h>
using namespace std;

// void simulatorProgram(Simulator userSimulator){
//     int N = 10;
//     userSimulator.Initialize(N);
    
//     userSimulator.stageStart();
//     for(int i=0; i<N; i++){
//         int* pi = new int;
//         *pi = i;
//         userSimulator.writeData(i, "value", pi);
//     }
//     userSimulator.stageComplete();

//     for(int i=0; i<=log2(N); i++){
//         int step = 1 << i;
//         userSimulator.stageStart(); 
//         for(int j=step; j<N; j++){
//             userSimulator.readData(j, j-step, "value");
//         }
//         userSimulator.stageComplete();

//         userSimulator.stageStart();
//         for(int j=step; j<N; j++){
//             int readValue = * (int *) userSimulator.getStoredValue(j);
//             int* computedValue = new int;
//             *computedValue = readValue + * (int *) userSimulator.getLocalValue(j, "value");
//             userSimulator.writeData(j, "value", computedValue);

//         }
//         userSimulator.stageComplete();

//     }


//     userSimulator.stageStart();
//     for(int i=0; i<N; i++){
//         int localValue = * (int *) userSimulator.getLocalValue(i, "value");
//         printf("%d ", localValue);
//     }
//     userSimulator.stageComplete();

// }

/*
    userSimulator.execute(func(data));
    userSimulator.read(func(id), "value");
    userSimulator.write("data", );

    ptr = new UserObject();
    us.init(N, void *ptr)  - num of processor, 
    us.prepareData();

    us.read(function1(id))
    us.execute(function2(id / Processor)) // on all processors
    us.write(function3(id/ Processor)) // on all processors


    user defined its own object structure..
    us.read(func(id) -> );
    user will write 3 functions -- read(int id, void *ptr), execute(), write()[]
*/

void execute(map<string, void*>& localData, void* varRef){
    int currentBit = * (int *) localData["bit"];
    if(currentBit == 0){
        *((int *)varRef) = 0;
    }
}

void localExecute(map<string, void*>& localData){
    int currentBit = * (int *) localData["bit"];
    * (int *) localData["bit"] = 1 - currentBit;
}


void simulatorProgram(Simulator us){
    int N = 10;
    us.initialize(N);
    int arr[N];
    for(int i=0; i<N; i++){
        arr[i] = 1;
        us.initializeData("bits", (arr+i), i);
    }

    
    int* result = new int;
    *result = 1;
    
    us.initializeData("result", result);

    us.readData("bits", "bit", identity);
    us.execute(localExecute);
    us.writeData("result", execute, zero);
    cout << (*result) << '\n';
}


