#include <map>
#include <iostream>
#include <math.h>
#include <assert.h>
#include "simulatorAPI.hpp"
using namespace std;

int zero(int a){
    return 0;
}

int identity(int x){
    return x;
}

void Processor::storeData(string variableName, void* dataPointer){
    this->localData[variableName] = dataPointer;
}

void Processor::localCompute(void (*compute)(map<string, void*>, void*), void* varRef){
    compute(this->localData, varRef);
}

void Simulator::initialize(int numberOfProcessors){
    this->N = numberOfProcessors;
    this->Processors.resize(numberOfProcessors);
}

void Processor::execute(void (*executeSomething)(map<string, void*>)){
    executeSomething(this->localData);
}

// void Simulator::initializeData(string variableName,void* arr,int arrLength){
//     for(int i=0; i<arrLength; i++){
//         this->sharedMemory[variableName][i] = (arr+i);
//     }
// }

void Simulator::initializeData(string variableName, void* dataPointer, int index /* = 0 */){
    this->sharedMemory[variableName][index] = dataPointer;
}

void Simulator::readData(string variableName, string storeName, int (*getIndex)(int)){
    for(int i=0; i<this->N; i++){
        int dataIndex = getIndex(i);
        //check Valid Index 
        if(dataIndex >= 0){
            this->Processors[i].storeData(storeName, this->sharedMemory[variableName][dataIndex]);
        }
    }
}

void Simulator::writeData(string variableName, void (*compute)(map<string, void*>, void*), int (*getIndex)(int)){
    for(int i=0; i<this->N; i++){
        int dataIndex = getIndex(i);
        if(dataIndex >=0){
            this->Processors[i].localCompute(compute, this->sharedMemory[variableName][dataIndex]);
        }
    }
}

