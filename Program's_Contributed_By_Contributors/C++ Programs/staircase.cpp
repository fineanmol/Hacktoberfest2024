// Stair Case Problem
// A person can climb 1 stair or 2 stair at a time. find the number of ways to climb n stairs.

#include<iostream>
using namespace std;
int stairCase(int n)
{
    int* output=new int[n+1];
    output[0]=1;
    output[1]=1;
    output[2]=2;
    for(int i=3;i<=n;i++){
        output[i]=output[i-1]+output[i-3]+output[i-2];
    }
    return output[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<stairCase(n)<<endl;
    return 0;
}
