#include <map>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <util.h>
#include <functional>
using namespace std;

class Student 
{
    public:
        string name;
        int rollNum;

        Student(string name, int roll){
            this->name = name;
            this->rollNum = roll;
        }
};

int main(){
    Student A("Ankushejdhhjdchuhcufhcufhfuhvfvhfvhfuhdjjhjfifjijifjijijijijijijijvu", 7);
    Student B("Manik", 5);
    cout << sizeof(A) << " " << sizeof(B) << '\n';
}