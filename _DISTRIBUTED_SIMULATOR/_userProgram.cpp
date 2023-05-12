#include <iostream>
#include "API.hpp"
using namespace std;

void printDistance(Node& a){
    printf("Distance to Node %d is %d\n", a.getId(), a.getData("distance"));
}

void userProgram(Simulator us){
    us.execute([](Node& a){
        if(a.getId() == 0){
            a.writeData("distance", 0);
        }else{
            a.writeData("distance", 100000);
        }
    });

    int graphSize = us.getSize();
    while(graphSize--){
        us.sendToNeighbours([](Node& a){return a.getData("distance");}, "distance");
        us.execute([](Node& a){
            while(!a.checkBufferIsEmpty()){
                Transmission latest = a.getLatestMessage();
                int currentDistance = a.getData("distance");
                int newDistance = latest.value + 1;
                if(newDistance < currentDistance){
                    a.writeData("distance", newDistance);
                }
            }
        });
    }

    us.execute(printDistance);
}