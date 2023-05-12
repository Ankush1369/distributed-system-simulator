#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

int main(int argc, char* argv[]){
    ifstream input(argv[1]);
    int n, m;
    input >> n >> m;
    vector<vector<int> > neighbours(n);
    for(int i=0; i<m; i++){
        int u, v;
        input >> u >> v;
        neighbours[u].push_back(v);
        neighbours[v].push_back(u);
    }

    vector<int> distance(n, 100000);
    vector<int> visited(n, false);
    distance[0] = 0;
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(auto i: neighbours[x]){
            if(!visited[i]){
                distance[i] = distance[x] + 1;
                q.push(i);
                visited[i] = true;
            }
        }
    }

    for(int i=0; i<n; i++){
        printf("Distance to Node %d is %d\n", i, distance[i]);
    }
}