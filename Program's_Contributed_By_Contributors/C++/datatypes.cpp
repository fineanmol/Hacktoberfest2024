#include <iostream>
using namespace std;

int main()
{

    cout << "----- Data Types -----" << endl;

    int a; //declaration
    cout << "Size of a (integer)" << sizeof(a) << endl;

    float b; //declaration
    cout << "Size of b (float)" << sizeof(b) << endl;

    char c; //declaration
    cout << "Size of c (character)" << sizeof(c) << endl;

    bool d; //declaration
    cout << "Size of d (boolean)" << sizeof(d) << endl;

    cout << "\n";

    cout << "----- Type Modifiers -----" << endl;

    short int e;
    long int f;
    cout << "Size of e (short integer)" << sizeof(e) << endl;
    cout << "Size of f (long integer)" << sizeof(f) << endl;

    return 0;
}