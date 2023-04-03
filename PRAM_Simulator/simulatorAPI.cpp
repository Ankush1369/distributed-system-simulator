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

map<string, void*>& Processor::getLocalDataReference(){
    return this->localData;
}

void Simulator::initialize(int numberOfProcessors){
    this->N = numberOfProcessors;
    this->Processors.resize(numberOfProcessors);
}

void Simulator::initializeData(string variableName, void* dataPointer, int index /* = 0 */){
    assert(index >=0);
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

void Simulator::writeData(string variableName, void (*compute)(map<string, void*>&, void*), int (*getIndex)(int)){
    for(int i=0; i<this->N; i++){
        int dataIndex = getIndex(i);
        if(dataIndex >=0){
            compute(this->Processors[i].getLocalDataReference(), this->sharedMemory[variableName][dataIndex]);
        }
    }
}

void Simulator::execute(void (*executeSomething)(map<string, void*>&)){
    for(int i=0; i<this->N; i++){
        executeSomething(this->Processors[i].getLocalDataReference());
    }
}

