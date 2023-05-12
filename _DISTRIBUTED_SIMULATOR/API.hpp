#include <map>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <util.h>
#include <functional>
using namespace std;

class Transmission {
    private:
    public:
        int from;
        int to;
        string storeName;
        int value;
        
        Transmission(int from, int to, string storeName, int value){
            this->from = from;
            this->to = to;
            this->storeName = storeName;
            this->value = value;
        }

        //invalid Transmission
        Transmission(){
            this->from = -1;
            this->to = -1;
        }
};

class Node {
    private:
        map<string, int> data;
        set<int> neighbours;
        queue<Transmission> receivedMessages;
        int id;
    public:
        Node(int id, set<int> neighbours);
        int getId();
        set<int> getNeighbours();
        bool checkNeighbour(int pid);
        void writeData(string variableName, int value);
        int getData(string variableName);
        void receiveData(Transmission message);
        Transmission getLatestMessage();
        bool checkBufferIsEmpty();
        void cleanBuffer();
        Transmission sendData(int to, int value, string storeName);
};

class Simulator {
    private:
        int N;
        vector<Node> Nodes;
        queue<Transmission> messages;
        void executeTransmissions();
    public:
        Simulator(string inputFile);
        int getSize();
        // void sendToNeighbours(string variableName, string storeName);  
        void sendToNeighbours(function<int(Node&)>, string storeName, function<bool(Node&)> check = [](Node& a){return true;});
        void addTransmission(Transmission T);
        void execute(function<void(Node&)>);
        void execute(function<void(Node&,Simulator&)>);
        // void sendData(function<int(int)> to, string variableName);

};

void userProgram(Simulator us);