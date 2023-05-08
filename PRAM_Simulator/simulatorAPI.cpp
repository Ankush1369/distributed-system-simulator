#include <map>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <functional>
#include "simulatorAPI.hpp"
using namespace std;

int zero(int a){
    return 0;
}

int identity(int x){
    return x;
}

void Processor::storeData(string variableName, int value){
    this->localData[variableName] = value;
}

map<string, int>& Processor::getLocalDataReference(){
    return this->localData;
}

void Simulator::initialize(int numberOfProcessors){
    this->N = numberOfProcessors;
    this->Processors.resize(numberOfProcessors);
    this->currentState = START;
}

void Simulator::initializeArray(string variableName, int length, int defaultValue){
    for(int i=0; i<length; i++){
        this->sharedMemory[variableName][i] = defaultValue;
    }
}

void Simulator::initializeData(string variableName, int data){
    this->sharedMemory[variableName][0] = data;
}

void Simulator::initializeData(string variableName, int* data, int length /* = 0 */){
    assert(length >=0);
    for(int i=0; i<length; i++){
        this->sharedMemory[variableName][i] = data[i];
    }
}

void Simulator::readData(string variableName, string storeName, function<int(int)> getIndex){
    this->currentState = READ;
    printf("READ STEP:\n");
    for(int i=0; i<this->N; i++){
        int dataIndex = getIndex(i);
        if(dataIndex >= 0){
            this->Processors[i].storeData(storeName, this->sharedMemory[variableName][dataIndex]);
            // printf("Processor %d reading %s[%d]\n", i, variableName.c_str(), dataIndex);
        }
    }
}

void Simulator::writeData(string variableName, function<pair<bool, int>(int, map<string, int>&)> compute, function<int(int)> getIndex){
    this->currentState = WRITE;
    printf("WRITE STEP:\n");
    for(int i=0; i<this->N; i++){
        int dataIndex = getIndex(i);
        if(dataIndex >=0){
            pair<bool, int> resultComputed = compute(i, this->Processors[i].getLocalDataReference());
            if(resultComputed.first){
                this->sharedMemory[variableName][dataIndex] = resultComputed.second;
                // printf("Processor %d updated %s[%d] with %d\n", i, variableName.c_str(), dataIndex, resultComputed.second);
            }
        }
    }
}

void Simulator::execute(function<void(int, map<string, int>&)> executeSomething){
    this->currentState = EXECUTE;
    printf("LOCAL EXECUTE STATE\n");
    for(int i=0; i<this->N; i++){
        executeSomething(i, this->Processors[i].getLocalDataReference());
    }
}

