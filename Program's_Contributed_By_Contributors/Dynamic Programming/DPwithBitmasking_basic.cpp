//add,remove,display the the number set bits
#include<bits/stdc++.h>
using namespace std;
void add(int& n,int x)
{
   n=(n^(1<<(x-1)));
}
void remove(int& n,int x)
{
    n=(n^(1<<(x-1)));
}
void display(int n)
{
    for(int i=0;i<=9;i++)
    {
        if(n & (1 << i))
        {
            cout<<i+1<<" ";
        }
    }
}
int main()
{
    int n;
    cin>>n;
    remove(n,2);
    display(n);
    remove(n,3);
    add(n,2);
    display(n);
    return 0;
}
