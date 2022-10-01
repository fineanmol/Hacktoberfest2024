/*****from dust i have come, dust i will be*****/

#include<bits/stdc++.h>

typedef long long int ll;

#define pp pair<ll,ll>
#define dbg printf("in\n");
#define NL printf("\n");

#define inf 1000000000000

using namespace std;

bool prime[3001];

void sieve()
{
    memset(prime,1,sizeof(prime));

    prime[0]=prime[1]=0;
    for(int i=4;i<=3001;i+=2)
        prime[i]=0;

    for(int i=3;i<=3001;i+=2)
    {
        if(prime[i])
        {
            for(int j=i*2;j<=3001;j+=i)
            {
                prime[j]=0;
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);

    ll i,j,k;
    ll n;

    sieve();
    cin>>n;

    ll count=0,sum;
    for(i=1;i<=n;i++)
    {
        sum=0;
        for(j=1;j<=i;j++)
        {
            if(prime[j] && i%j==0)
                sum++;

            if(sum>2)
                break;
        }

        if(sum==2)
            count++;
    }

    cout<<count;

    return 0;
}