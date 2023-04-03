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

int Processor::getID(){
    return this->id;
}


void* Processor::getData(string variableName)
{
    if(this->localData[variableName] != NULL){
        return this->localData[variableName];
    }else{
        cout << "Variable " << variableName << " doesn't exist on processor " << this->id << '\n';
        return (void *) NULL;
    }
}

void Processor::writeData(string variableName, void* variableValue)
{   
    this->localData[variableName] = variableValue;
}

void Processor::setStoredValue(void* dataPointer){
    this->storedValue = dataPointer;
}

void* Processor::getStoredValue(){
    return this->storedValue;
}


Simulator::Simulator()
{
    this->N = 4;
    this->Processors.resize(this->N);
    this->initialized = false;
    this->isStaged = false;
}

void Simulator::Initialize(int numberOfProcessors){
    this->N = numberOfProcessors;
    this->Processors.resize(numberOfProcessors);
    this->initialized = false;
    for(int i=0; i<numberOfProcessors; i++){
        this->Processors[i].setId(i);
    }
}

void Simulator::readData(int pid, int fromPid, string variableName){
    if(this->isStaged){
        void* dataRead = this->Processors[fromPid].getData(variableName);
        this->Processors[pid].setStoredValue(dataRead);
    }else{
        cout << "Simulator is not staged to start any processing...\n";
    }
}

void Simulator::writeData(int pid, string variableName, void* dataPointer){
    if(this->isStaged){
        Task newTask(pid, variableName, (void *)dataPointer);
        this->taskQueue.push(newTask);
    }else{
        cout << "Simulator is not staged to start any processing...\n";
    }
}

void* Simulator::getStoredValue(int pid){
    return this->Processors[pid].getStoredValue();
}

void* Simulator::getLocalValue(int pid, string variableName){
    return this->Processors[pid].getData(variableName);
}

void Simulator::compute(int pid, void* dataPointer){
    this->Processors[pid].setStoredValue(dataPointer);
}


void Simulator::stageStart(){
    this->isStaged = true;
    assert(this->taskQueue.empty());
}

void Simulator::stageComplete(){
    if(this->isStaged){
        while(!this->taskQueue.empty()){
            Task currentTask = this->taskQueue.front();
            taskQueue.pop();
            this->Processors[currentTask.pid].writeData(currentTask.variableName, currentTask.value);
        }
    }else{
        cout << "Please start your staging before completing...\n";
    }
    this->isStaged = false;
}


