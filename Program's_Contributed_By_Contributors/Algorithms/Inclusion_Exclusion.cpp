// This principal is used when we have a question requiring number of ways to do a certain thing

#include<bits/stdc++.h>
using namespace std;

void divisible(int n , int a, int b)
{
    // Find out the numbers that are divisble by a and/or b , from 1 to n
    cout<<(n/a)+(n/b)-(n/(a*b))<<endl;
}

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    divisible(n,a,b);
    return 0;
}