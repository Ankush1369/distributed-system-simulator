#include <iostream>
#include "helper.hpp"
using namespace std;

int x = 10;

int main(){
    int a = 10;
    int b = 20;
    int c = 40;
    cout << calci(a, b, c) << '\n';
    doubleThis();
    doubleThis();
    doubleThis();
    cout << "Now x is " << x << '\n';
    return 0;
}