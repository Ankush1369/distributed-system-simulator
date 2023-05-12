#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int main(int argc, char* argv[]){
    ofstream outFile(argv[1]);
    srand(time(0));
    int n = 20 + rand()%10;
    outFile << n << '\n';
    int m = 0;
    for(int i=0; i<n-1; i++){
        int outgoing = rand() % (n-i-1);
        set<int> outgoingNodes;

        while(outgoing--){
            int newOutgoing = 1 + i + rand() % (n-i-1);
            outgoingNodes.insert(newOutgoing);
        }

        for(auto node: outgoingNodes){
            outFile << i << " " << node << '\n';
        }
        // cout << "---------------------------------";
        m += (int)outgoingNodes.size();
    }
    cout << "Size is: " << m << '\n';

}