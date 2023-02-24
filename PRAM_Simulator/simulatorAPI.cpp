#include <map>
#include <iostream>
#include <math.h>
#include <assert.h>
#include "simulatorAPI.hpp"
using namespace std;

Processor::Processor(int id){
    this->id = id;
}

int Processor::readData(string variableName)
{
    return this->localData[variableName];
}

void Processor::writeData(string variableName, int variableValue)
{
    this->localData[variableName] = variableValue;
}

Simulator::Simulator(int N)
{
    this->N = N;
    this->Processors.resize(N);
    for(int i=0; i<N; i++){
        this->Processors[i] = new Processor(i);
    }
}

int Simulator::readData(int id, string variableName){
    return this->Processors[id]->readData(variableName);
}

void Stage(){
    
}





