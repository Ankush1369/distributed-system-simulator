#include <map>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <functional>
#include "API.hpp"
#include <fstream>
using namespace std;

Node::Node(int id, set<int> neighbours){
    this->id = id;
    this->neighbours = neighbours;
}

// void Node::setId(int id){
//     this->id = id;
// }

// void Node::addNeighbour(int pid){
//     this->neighbours.insert(pid);
// }

// void Node::removeNeighbour(int pid){
//     this->neighbours.erase(pid);
// }

int Node::getId(){
    return this->id;
}

bool Node::checkNeighbour(int pid){
    return (this->neighbours.find(pid) != this->neighbours.end());
}

void Node::writeData(string variableName, int value){
    this->data[variableName] = value;
}

int Node::getData(string variableName){
    return this->data[variableName];
}

set<int> Node::getNeighbours(){
    return this->neighbours;
}

void Node::receiveData(Transmission message){
    if(this->checkNeighbour(message.from) && message.to == this->id) {
        this->receivedMessages.push(message);
    };
}

Transmission Node::getLatestMessage(){
    Transmission latest = this->receivedMessages.front();
    this->receivedMessages.pop();
    return latest;
}

bool Node::checkBufferIsEmpty(){
    return this->receivedMessages.empty();
}

void Node::cleanBuffer(){
    while(!this->receivedMessages.empty()) this->receivedMessages.pop();
}

Transmission Node::sendData(int to, int value, string storeName){
    if(this->checkNeighbour(to)){
        return Transmission(this->id, to, storeName, value);
    }else{
        return Transmission();
    }
}


Simulator::Simulator(string inputFile){
    ifstream input(inputFile);
    input >> this->N;
    vector<set<int> > neighbours(N);

    int numberOfEdges;
    input >> numberOfEdges;

    for(int i=0; i<numberOfEdges; i++){
        int u, v;
        input >> u >> v;
        neighbours[u].insert(v);
        neighbours[v].insert(u);
    }

    for(int i=0; i<this->N; i++){
        this->Nodes.push_back(Node(i, neighbours[i]));
    }
}

int Simulator::getSize(){
    return this->N;
}


void Simulator::sendToNeighbours(function<int(Node&)> nodeValue, string storeName, function<bool(Node&)> check){
    for(int i=0; i<this->N; i++){
        if(check(this->Nodes[i])){
            int data = nodeValue(this->Nodes[i]);
            for(auto neighbour: this->Nodes[i].getNeighbours()){
                this->addTransmission(Transmission(i, neighbour, storeName, data));
            }
        }
    }
    this->executeTransmissions();
}



void Simulator::addTransmission(Transmission T){
    if(T.from < 0 || T.to < 0) return;
    this->messages.push(T);
}


void Simulator::executeTransmissions(){
    while(!this->messages.empty()){
        Transmission latest = messages.front();
        this->Nodes[latest.to].receiveData(latest);
        messages.pop();
    }
}

void Simulator::execute(function<void(Node&)> nodeFunction){
    for(int i=0; i<this->N; i++){
        nodeFunction(this->Nodes[i]);
    }
    this->executeTransmissions();
}
void Simulator::execute(function<void(Node&,Simulator&)> nodeFunction){
    for(int i=0; i<this->N; i++){
        nodeFunction(this->Nodes[i], *this);
    }
    this->executeTransmissions();
}