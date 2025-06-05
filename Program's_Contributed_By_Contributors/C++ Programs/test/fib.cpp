#include <iostream>
using namespace std;
int fib(int n)
{
    int sum;
    if (n == 0 || n==1)
        return n;
        else{
            
            return fib(n-1)+fib(n-2);
            }
   
}
int main()
{
    for (int i=0;i<5;i++)
    cout<< fib(i)<<"  ";
}
 