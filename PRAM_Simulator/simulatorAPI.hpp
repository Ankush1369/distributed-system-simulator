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


class Memory {
    public:
        void* ptr;
        Memory(void* value){
            this->ptr = value;
        }

};

class Processor {
    private:
        map<string, Memory> localData;
        Memory lastComputedValue;
        int id;
    public:
        Memory lastReadValue;
        void setId(int id);
        Memory getData(string variableName);
        void writeData(string variableName, void* variableValue);

};


class Simulator {
    private:
        int N;
        vector<Processor> Processors;
        map<string, int> globalData;
        queue<Task> taskQueue;
        bool initialized;
    public:
        Simulator();
        void Initialize(int numberOfProcessors);
        void* readData(int pid, string variableName);
        void writeData(int, string variableName, void* dataValue);
        void* getStoredValue(int pid); //get last stored value by pid from its action
        void compute(int pid, void* computedValue = NULL); //stores computed value if any
        void stageComplete();
};

void simulatorProgram(Simulator);


