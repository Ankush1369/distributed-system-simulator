#include <map>
#include <iostream>
#include <vector>
#include <queue>
#include <util.h>
#include <functional>
using namespace std;

// enum TaskType { READ , WRITE , IDLE , COMPUTE};
enum STATE { START = 0, READ = 1, EXECUTE = 2, WRITE = 3};

int zero(int);
int identity(int);

class Processor {
    private:
        map<string, int> localData;
        int id;
    public:
        void storeData(string variableName, int value);
        map<string, int>& getLocalDataReference();
};


class Simulator {
    private:
        int N;
        vector<Processor> Processors;
        map<string, map<int, int> > sharedMemory;
        STATE currentState;
    public:
        void initialize(int numberOfProcessors);
        void initializeData(string variableName, int* data, int length = 0);
        void initializeArray(string variableName, int lenght, int defaultValue = 0);
        void initializeData(string variableName, int data);
        void readData(string variableName, string storeName, function<int(int)> getIndex = zero);
        void writeData(string variableName, function<pair<bool, int>(int, map<string, int>&)> compute, function<int(int)> getIndex = zero);
        void execute(function<void(int, map<string, int>&)> executeSomething); //local computation

        
};

void simulatorProgram(Simulator);
