#include<bits/stdc++.h>
using namespace std;

int kthprime(int k)
{
    int primes[100000]={0};
    for (int i=2; i*i<=100000; i++)
    {
        if (!primes[i])
        {
            for(int j=i*i; j<=100000; j+=i)
            {
                primes[j]=1;
            }
        }
    }
    int count=0;
    for(int i=2; i<=100000; i++)
    {
        if (!primes[i])
        {
            count++;
            if(count==k)
            {
                k=i;
                break;
            }
        }
    }
    return k;
}

int main()
{
    int k;
    cin>>k;
    cout<<kthprime(k);
    return 0;
}