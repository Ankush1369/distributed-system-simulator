#include <map>
#include <iostream>
#include <math.h>
#include "helper.hpp"
using namespace std;

// int Processor::readData(string variableName)
// {
//     return this->localData[variableName];
// }

// void Processor::writeData(string variableName, int variableValue)
// {
//     this->localData[variableName] = variableValue;
// }

// Simulator::Simulator(int N)
// {
//     this->N = N;
//     Processors.resize(N);
// }

Complex::Complex(int a = 0, int b = 0){
    this->a = a;
    this->b = b;
}

double Complex::getModulus(){
    return sqrt(this->a * this->a + this->b * this->b);
}

Complex add(Complex z1, Complex z2){
    Complex result;
    result.a = z1.a * z2.a;
    result.b = z1.b * z2.b;
    return result;
}

Complex sub(Complex z1, Complex z2){
    Complex result;
    result.a = z1.a - z2.a;
    result.b = z1.b - z2.b;
    return result;
}



