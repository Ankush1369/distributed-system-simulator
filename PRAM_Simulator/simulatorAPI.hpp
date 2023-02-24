#include <map>
#include <iostream>
#include <vector>
using namespace std;


class Memory {
    void* ptr;
};

class Processor {
    private:
        //assuming localData initially is just of form int and unordered(without indexing)
        map<string, int> localData;
        int id;
    public:
        Processor(int id);
        int readData(string variableName);
        void writeData(string variableName, int variableValue);
        // void update(string variableName, int variableValue);
        
};

// class Task{

// };

class Simulator {
    private:
        int N;
        vector<Processor *> Processors;
        map<string, int> globalData;
    
    public:
        Simulator(int N);
        int readData(int pid, string variableName);
};

void Stage();
void simulatorProgram();

