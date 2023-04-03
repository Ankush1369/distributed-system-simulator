#include <map>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// enum TaskType { READ , WRITE , IDLE , COMPUTE};

int zero(int);
int identity(int);

// class Task{
//     public:
//         TaskType type;
//         int pid;
//         string variableName;
//         void* value;

//         Task(int pid, string variableName, void* value);
// };

class Processor {
    private:
        map<string, void*> localData;
        // int id;
        // void* storedValue;
    public:
        // void setId(int id);
        // int getID();
        // void* getData(string variableName);
        // void writeData(string variableName, void* variableValue);
        // void setStoredValue(void *);
        // void* getStoredValue();

        void storeData(string variableName, void* dataPointer);
        map<string, void*>& getLocalDataReference();
};


class Simulator {
    private:
        int N;
        vector<Processor> Processors;
        map<string, map<int, void*> > sharedMemory;
        // map<string, int> globalData;
        // queue<Task> taskQueue;
        // bool initialized;
        // bool isStaged;
    public:
        void initialize(int numberOfProcessors);
        // void readData(int pid, int fromPid, string variableName);
        // void writeData(int, string variableName, void* dataValue);
        // void* getStoredValue(int pid); 
        // void compute(int pid, void* = NULL); 
        // void* getLocalValue(int pid, string variableName);
        // void stageStart();
        // void stageComplete();

        void initializeData(string variableName, void* data, int index = 0);
        void readData(string variableName, string storeName, int (*getIndex)(int) = identity);
        void writeData(string variableName, void (*compute)(map<string, void*>&, void*), int (*getIndex)(int));
        void execute(void (*executeSomething)(map<string, void*>&));

        
};

void simulatorProgram(Simulator);
