#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cout<<"enter first integer : ";
    cin>>a;
    cout<<"enter second integer : ";
    cin>>b;
    //the idea is to use the bitwise XOR operator.
    a = a^b;
    b = b^a;
    a = a^b;

    cout<<"After swapping : a = "<<a<<" b = "<<b<<endl;

}