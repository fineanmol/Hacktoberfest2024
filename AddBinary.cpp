#include<bits/stdc++.h>
using namespace std;

int reverse(int a)
{
    int ans=0;
    while(a>0)
    {
        int ld=a%10;
        ans=ans*10+ld;
    }
}

int dd(int a,int b)
{
    int c=0;
    int ans=0;
    while(a>0 && b>0)
    {
        if(a%2==0 && b%2==0)
        {
            ans=ans*10 + c;
            c=0;
        }else if((a%2==0 && b%2==1) || (a%2==1 && b%2==0))
        {
            if (c==0)
            {
                ans=ans*10+1;
                c=0;
            }
            else
            {
                ans=ans*10+0;
                c=1;
            }
            
        }
        else
        {
            if(c==0)
            {
                ans=ans*10+0;
                c=1;
            }
            else
            {
                ans=ans*10+1;
                c=1;
            }
            a/=10;
            b/=10;
        }
        while(a>0)
        {
            if (c==1){
                if(a%2==1){
                    ans=ans*10+0;
                    c=0;
                }else
                {
                    ans=ans*10+1;
                    c=0;
                }
            }
            else{
                ans=ans*10+(a%2);
                a/=10;
            }
        }
        while(b>0)
        {
            if (c==1){
                if(b%2==1){
                    ans=ans*10+0;
                    c=0;
                }else
                {
                    ans=ans*10+1;
                    c=0;
                }
            }
            else{
                ans=ans*10+(b%2);
                b/=10;
            }
        }
        if(c==1)
        ans = ans*10 +1;
        ans= reverse(ans);
    return ans;
    }

int32_t main()
{
    int a,b;
    cin>>a>>b;
    cout<<dd(a,b)<<endl;        

    return 0;
}