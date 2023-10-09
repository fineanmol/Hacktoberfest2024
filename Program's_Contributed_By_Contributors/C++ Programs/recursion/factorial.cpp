// factorial using tail recursion
#include<iostream>
using namespace std;

int tail(int n, int result = 1)
{
    if (n == 0 || n == 1)
        return result;
    else
        return tail(n - 1, n * result);
}
int non_tail(int n)
{
    int sum;
    if (n == 0 || n==1)
        return n;
        else{
            
            return non_tail(n-1)+non_tail(n-2);
            }
   
}

int main()
{
   cout<< "Tail "<<tail(5);
   cout<< "Non tail "<<non_tail(5);
}
