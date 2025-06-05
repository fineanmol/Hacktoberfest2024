#include<iostream>
using namespace std;
 
int main()
{
    int fib1 = 0, fib2 = 1, fib3 = 1;
 
    cout << "The Fibonacci Series is follows : " << endl << fib1 << " " << fib2 << " ";
    while (fib1 + fib2 < 1000)
    {
        fib3 = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib3;
        cout << fib3 << " ";
    }
    cout << endl;
 
    return 0;
}
