#include<bits/stdc++.h>
using namespace std;

bool check(int a,int b,int c)
{
    int max;
    int y;
    int z;
    if(a>b && a>c)
    {
        max=a;
        y=b;
        z=c;
    }
    else if(b>a && b>c)

    {
        max=b;
        y=a;
        z=c;
    }
    else 
    {
        max=c;
        y=a;
        z=b;
    }

    if(max*max==y*y + z*z)
    {
        return true;
    }
    else{
        return false;
    }
}

int32_t main()
{
    int x,y,z;
    cin>>x>>y>>z;

    if(check(x,y,z))
    {
        cout<<"Pythagorean triplet. \n";
    }
    else
    {
        cout<<"Not a Pythagorean triplet. \n";
    }

    return 0;
}