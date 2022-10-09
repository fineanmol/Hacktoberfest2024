#include <bits/stdc++.h>
using namespace std;
const int N=1e+5;
int dp[N];
static int c=0;
unsigned long long int fib( unsigned long long int  n)
{
    if(n==1)
    return 0;
     if(n==2)
         return 1;
    if(dp[n]!=-1){
        c++;
    return dp[n];
    }

    else
    return  dp[n]= fib(n-1)+fib(n-2);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    fib(20);
cout<<"NUmber of overlapping subproblems "<<c;
    // const int n=70;
    // cout<<"Fibonacci series upto 70 terms"<<endl;
    // for(int i=1;i<=70;i++)
    // cout<<fib(i)<<" ";
    
    
    return 0;
    
}
