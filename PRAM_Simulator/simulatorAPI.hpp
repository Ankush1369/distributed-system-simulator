#include <map>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

enum TaskType { READ , WRITE , IDLE , COMPUTE};

class Task{
    public:
        TaskType type;
        int pid;
        string variableName;
        void* value;

        Task(int pid, string variableName, void* value);
};



class Processor {
    private:
        map<string, void*> localData;
        int id;
        void* storedValue;
    public:
        void setId(int id);
        int getID();
        void* getData(string variableName);
        void writeData(string variableName, void* variableValue);
        void setStoredValue(void *);
        void* getStoredValue();

};


class Simulator {
    private:
        int N;
        vector<Processor> Processors;
        map<string, int> globalData;
        queue<Task> taskQueue;
        bool initialized;
        bool isStaged;
    public:
        Simulator();
        void Initialize(int numberOfProcessors);
        void readData(int pid, int fromPid, string variableName);
        void writeData(int, string variableName, void* dataValue);
        void* getStoredValue(int pid); //get last stored value by pid from its action
        void compute(int pid, void* = NULL); //stores computed value if any
        void* getLocalValue(int pid, string variableName);
        void stageStart();
        void stageComplete();
};

void simulatorProgram(Simulator);
