#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define lli long long int
#define RAL(i, n) for (int i=0; i<n; i++)

lli I[2][2];
lli T[2][2];

void mul(lli A[2][2], lli B[2][2])
{
    lli res[2][2];
    RAL(i, 2) RAL(j, 2) res[i][j]=0;
    RAL(i, 2)
    {
        RAL(j, 2)
        {
            RAL(k, 2)
            {
                lli x=(A[i][k]*B[k][j])%mod;
                res[i][j]=(res[i][j]+x)%mod;        
            }
        }          
    }
    
    RAL(i, 2) RAL(j, 2) A[i][j]=res[i][j];
}

void power(lli T[][2], long n)
{
    I[0][0]=I[1][1]=1;
    I[1][0]=I[0][1]=0;
    while(n>=1)
    {
        if (n%2)
        {
            n--;
            mul(I, T);
        }
        else
        {
            n/=2;
            mul(T, T);
        }
    }
    RAL(i, 2) RAL(j, 2) T[i][j]=I[i][j];
}
lli getfib(int n,int a, int b)
{
    lli res;
    T[0][0]=0;
    T[1][0]=T[0][1]=T[1][1]=1;
    power(T, n-1);
    res=(a*T[0][1]+b*T[1][1])%mod;
    return res;
}

int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int a, b, n;
        cin>>a>>b>>n;
        if(n<2)
        {
            int res;
            res=n==1? b:a;
            cout<<res<<endl;
            continue;
        }
        else
        {
            cout<<getfib(n, a, b)<<endl;           
        }
        
    }
    return 0;
}
