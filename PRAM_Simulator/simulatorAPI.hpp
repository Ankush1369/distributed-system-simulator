#include <map>
#include <iostream>
#include <vector>
#include <queue>
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
        void readData(string variableName, string storeName, int (*getIndex)(int) = identity);
        void writeData(string variableName, void (*compute)(map<string, int>&, int&), int (*getIndex)(int));
        void execute(void (*executeSomething)(map<string, int>&)); //local computation

        
};

void simulatorProgram(Simulator);
