#include<iostream>
using namespace std;
int findhcf(int num1,int num2)
{
    if(num1==0)
    return num1;

    if(num2==0)
    return num2;

    if(num1==num2)
    return num1;
    if(num1>num2)
    {
        return findhcf(num1-num2,num2);
    }
    if(num2>num1)
    {
        return findhcf(num1,num2-num1);
    }
}

int main()
{
    int num1,num2;
    cout<<"enter 2 nos.";
    cin>>num1>>num2;
    int ans = findhcf(num1,num2);
    cout<<ans;
}