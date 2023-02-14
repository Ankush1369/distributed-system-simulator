#include <map>
#include <iostream>
using namespace std;

extern int x;

int add(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a + b;
}

int mult(int a, int b){
    return a*b;
}

int readData(int id, map<int, int> variable){
    return id + 1;
}
void doubleThis(){
    x = 2 * x;
}