// C++ program for Fibonacci Series 
// using Dynamic Programming
#include<bits/stdc++.h>
using namespace std;
 
class Solve{
     
public:
int fibonacci(int n)
{
    // 1 extra to handle
    // case, n = 0
    int f[n + 2];
    int i;
 
    // 0th and 1st number of the
    // series are 0 and 1
    f[0] = 0;
    f[1] = 1;
 
    for(i = 2; i <= n; i++)
    {
         
       //Add the previous 2 numbers in the series and store it
       f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
    }
};
int main ()
{
    solve s;
    int n = 9;
     
    cout << s.fibonacci(n);
    return 0;
}
