#include <map>
#include <iostream>
#include "helper.hpp"

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
    Processors.resize(N);
}

