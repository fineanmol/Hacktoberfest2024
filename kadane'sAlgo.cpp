#include<iostream>
using namespace std;

int main()
{
    int a[5];
    int cumSum[5]={0};
    int curSum=0, maxSum=0;

    cin>>a[0];
    cumSum[0]=a[0];

    for(int i=1; i<5; i++)
    {
        cin>>a[i];
        cumSum[i] = cumSum[i-1] + a[i];
    }