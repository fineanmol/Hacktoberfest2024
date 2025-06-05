#include <iostream>
using namespace std;
int fib(int n, int result = 1)
{
    if (n == 0 || n == 1)
        return result;
    else
        return fib(n - 1, n * result);
}

int main()
{
    cout << "Factorial is: " << fib(7);
}
