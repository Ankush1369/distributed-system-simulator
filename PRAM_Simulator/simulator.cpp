#include <iostream>
#include "helper.hpp"
#include <math.h>
using namespace std;

// void PRAM_Simulator()
// {   
//     int N = 20;
//     Simulator[2*N];
//     int stages = ceil((float)log2(2*N));
//     for(int i = 0; i<stages; i++){
//         Simulator.r
//     }
// }

Complex calci(int operation, Complex z1, Complex z2){
    cout << "This is similutor\n";
    cout << "Testing\n";
    if(operation == 2){
        return add(z1, z2);
    }else{
        return sub(z1, z2);
    }
}