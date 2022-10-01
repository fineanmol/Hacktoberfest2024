
#include<bits/stdc++.h>
using namespace std;

void primeSieve(int n)
{   // Algorith to find all the prime numbers till n😀
    int prime[100]={0};
    for (int i = 2; i <= n; i++)
    {
        if(prime[i]==0)
        {
            for (int j = i*i; j <= n; j+=i)
            {
                prime[j]=1;
            }
            
        }
    }
    for (int i = 2; i <= n ; i++)
    {
        if(prime[i]==0)
        {
            cout<<i<<" ";
        }
        
    }
    
    
}

void primeFct(int n)
{
    int spf[100]={0};
    for(int i=2;i<=n;i++)
    {
        spf[i]=i;
    }

    for (int i = 2; i <= n; i++)
    {
        if(spf[i]==i)
        {
            for (int j = i*i; j <= n; j+=i)
            {
                spf[j]=i;
            }
            
        }
    }

    while (n!=1)
    {
        cout<<spf[n]<<" ";
        n=n/spf[n];
    }
    
    
}

int main()
{
    int n; 
    cin>>n;
    primeSieve(n);
    cout<<"Prime Factor"<<endl;
    primeFct(n);
    return 0;
}