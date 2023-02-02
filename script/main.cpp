#include <iostream>
#include <omp.h>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <fstream>

using namespace std;


class System{
    public:
        System(){

        }
    private:

};

vector<System> NODES;
vector<vector<int> > FROM_EDGES;
vector<vector<int> > TO_EDGES;
int N;

void getData(){
    
}

void transfer(int from, int to){

}

void compute(){

}

void clockCycleEnd(){

}

void Initialize(string inputFile){
    ifstream inputGraph( (string) inputFile);
    inputGraph >> N;
    assert(N > 1);
    
    FROM_EDGES.resize(N+1);
    TO_EDGES.resize(N+1);
    NODES.resize(N+1);

    int edgeCount;
    inputGraph >> edgeCount;

    while(edgeCount--){
        int fromNode, toNode;
        inputGraph >> fromNode >> toNode;
        
        assert(fromNode < N+1);
        assert(fromNode > 0);

        assert(toNode < N+1);
        assert(toNode > 0);
    }
}




int main(int argc, char* argv[]){
    assert(argc == 2);
    
}