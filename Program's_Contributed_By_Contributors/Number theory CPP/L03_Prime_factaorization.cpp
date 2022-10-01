#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;

    int count=0;
    for(int i=2; i*i<=n; i++)  
    {
        if (n%i==0)
        {
            int p;
            int pow=0;
            while(n%i==0 )
            {
                if(p!=i)
                {
                    count++;
                }
                pow++;
                n/=i;
            }
        }
    }
    if (n>1)
    {
        cout<<n<<"^"<<1<<endl;
    }
    return 0;
}

