#include <map>
#include <iostream>
#include <math.h>
#include <assert.h>
#include "simulatorAPI.hpp"
using namespace std;

Task::Task(int pid, string variableName, void* value){
    this->pid = pid;
    this->variableName = variableName;
    this->value = value;
}

void Processor::setId(int id){
    this->id = id;
}


Memory Processor::getData(string variableName)
{
    return this->localData[variableName];
}

void Processor::writeData(string variableName, void* variableValue)
{
    if(this->localData.find(variableName) == this->localData.end()){
        this->localData[variableName] = new Memory(variableValue);
    }
}


Simulator::Simulator()
{
    this->N = 4;
    this->Processors.resize(this->N);
    this->initialized = false;
}

void Simulator::Initialize(int numberOfProcessors){
    this->N = numberOfProcessors;
    this->Processors.resize(numberOfProcessors);
    this->initialized = false;
    for(int i=0; i<numberOfProcessors; i++){
        this->Processors[i].setId(i);
    }
}

void* Simulator::readData(int pid, string variableName){
    return this->Processors[pid].getData(variableName).ptr;
}

void Simulator::writeData(int pid, string variableName, void* dataValue){
    Task newTask(pid, variableName, dataValue);
    this->taskQueue.push(newTask);
}

// Processor pid computes this value and stores in a variable
void compute(int pid, void* computedValue){

}

void Simulator::stageComplete(){
    
}






