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
    public:
        void* storedValue;
        void setId(int id);
        void* getData(string variableName);
        void writeData(string variableName, void* variableValue);

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
        template<class T> void writeData(int, string variableName, T dataValue);
        // template<class T> void updateData(int, string variableName, T (*updateValue)(T));
        void* getStoredValue(int pid); //get last stored value by pid from its action
        // void compute(int pid, void* computedValue = NULL); //stores computed value if any
        void* getLocalValue(int pid, string variableName);
        void stageStart();
        void stageComplete();
};

void simulatorProgram(Simulator);

template<class T> void Simulator::writeData(int pid, string variableName, T dataValue){
    if(this->isStaged){
        T* dataPointer= new T;
        *dataPointer = dataValue;
        Task newTask(pid, variableName, (void *)dataPointer);
        this->taskQueue.push(newTask);
    }else{
        cout << "Simulator is not staged to start any processing...\n";
    }
}
