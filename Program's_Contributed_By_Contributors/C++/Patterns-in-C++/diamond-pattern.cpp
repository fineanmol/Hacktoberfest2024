//C++ program for printing Hollow diamond pattern
#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

int main()
{
    for(int i=-6;i<=6;i++)
    {
        for(int j=-6;j<=6;j++)
        {
            if((abs(i)+abs(j))>=6)
            {
                cout<<"*";
            }
            else
            cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
} 
