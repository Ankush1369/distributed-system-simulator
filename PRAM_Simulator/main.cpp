#include <iostream>
#include "helper.hpp"
using namespace std;

int x = 10;

int main(){
    Complex z1(12, 5);
    Complex z2(9,-2);
    Complex z3 = calci(1, z1, z2);
    Complex z4 = calci(2, z1, z2);

    cout << z1.getModulus() << '\n';
    cout << z3.a << " " << z3.b << '\n';
    cout << z4.a << " " << z4.b << '\n';
}