#include <map>
#include <iostream>
#include <vector>
using namespace std;

// class Processor {
//     private:
//         //assuming localData initially is just of form int and unordered(without indexing)
//         map<string, int> localData;
//     public:
//         Processor();
//         int readData(string variableName);
//         void writeData(string variableName, int variableValue);
//         // void update(string variableName, int variableValue);
        
// };

// class Task{

// };

// class Simulator {
//     private:
//         int N;
//         vector<Processor> Processors;
//         map<string, int> globalData;
    
//     public:
//         Simulator(int N);
//         int readData(int pid, string variableName);


// };

// void Stage();
// void PRAM_Simulator();


class Complex {
    public:
        int a, b;
        Complex(int a, int b);
        double getModulus();
};


Complex add(Complex z1, Complex z2);
Complex sub(Complex z1, Complex z2);

Complex calci(int operation, Complex z1, Complex z2);
