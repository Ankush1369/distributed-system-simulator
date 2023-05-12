#include <iostream>
#include "simulatorAPI.hpp"
#include <math.h>
using namespace std;

/* Program 1 Starts (AND of n bits in parallel)*/

// pair<bool, int> compute(int id, map<string, int>& localData){
//     if(!localData["num"]){
//         return {true, 0};
//     }else{
//         return {false, 0};
//     }
// }

// void printResult(int id, map<string, int>& localData){
//     if(id == 0){
//         printf("%d\n", localData["result"]);
//     }
// }


// void simulatorProgram(Simulator us){
//     srand(time(0));
//     int N = 10;

//     int arr[N];
//     for(int i=0; i<N; i++){
//         arr[i] = 1;
//     }
//     us.initialize(N);
//     us.initializeData("arr", arr, N);

//     us.initializeData("result", 1);

//     us.readData("arr", "num", identity);
//     us.writeData("result", compute);
    
//     us.readData("result", "result");
//     us.execute(printResult);
// }
/* Program 1 Ends*/


/* Program 2 Starts (Right shifting an array)*/

pair<bool, int> getNum(int id, map<string, int>& localData){
    return {true, localData["num"]};
}

void printValues(int id, map<string, int>& localData){
    printf("Data at index %d is %d\n", id, localData["num"]);
}

void simulatorProgram(Simulator us){
    srand(time(0));
    int N = 10;
    int arr[N];
    for(int i=0; i<N; i++){
        arr[i] = rand()%100;
        printf("%d ", arr[i]);
    }
    printf("\n");
    us.initialize(N);
    us.initializeData("arr", arr, N);
    us.readData("arr", "num", identity);

    auto nextPos = [N](int id) {return (id+1)%N;};
    us.writeData("arr", getNum, nextPos);
    us.readData("arr", "num", identity);
    us.execute(printValues);
}

/* Program 2 Ends*/


/*Program 3 Starts*/

// void simulatorProgram(Simulator us){
//     srand(time(0));
//     int N = 10;
//     int arr[N];
//     for(int i=0; i<N; i++){
//         arr[i] = rand()%10;
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
//     us.initialize(N);
//     us.initializeData("arr", arr, N);

//     for(int i=0; i<=log2(N); i++){
//         int step = 1 << i;
//         auto prevPos = [step](int id) {return id - step;};
//         us.readData("arr", "prevNum", prevPos);
//         us.readData("arr", "currNum", identity);

//         auto compute = [step](int id, map<string, int>&localData) -> pair<bool, int> {
//             if(id<step){
//                 return make_pair(false, 0);
//             }else{
//                 return make_pair(true, localData["prevNum"] + localData["currNum"]);
//             }
//         };
//         us.writeData("arr", compute, identity);
//     }
//     us.readData("arr", "num", identity);
//     auto printValues = [](int id, map<string, int>& localData) {printf("Data at index %d is %d\n", id, localData["num"]);};
//     us.execute(printValues);
// }

/*Program 3 Ends*/