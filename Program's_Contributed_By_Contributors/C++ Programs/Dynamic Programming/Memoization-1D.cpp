// C++ program to find the Nth term
// of Fibonacci series
#include <bits/stdc++.h>
using namespace std;
 
// Fibonacci Series using Recursion
int fib(int n)
{
 
    // Base case
    if (n <= 1)
        return n;
 
    // recursive calls
    return fib(n - 1) + fib(n - 2);
}
 
// Driver Code
int main()
{
    int n = 6;
    printf("%d", fib(n));
    return 0;
}
