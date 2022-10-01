#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define fo1(x, y) for (ll x = 0; x < y; x++)
#define fo2(x, y) for (ll x = 1; x <= y; x++)
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)

ll mod = 1000000007;
void doit()
{
    int  n;
    cin>>n;
    int mn=1e9+1,mnAt=0;
    int mx=-1,mxAt=0;
    map<pair<int,int>,int>mp;
    for(int i=0;i<n;i++){

        int l,r,x;
        cin>>l>>r>>x;
        if(mp.find(make_pair(l,r))==mp.end())
            mp[make_pair(l,r)]=x;
        mp[make_pair(l,r)]=min(mp[make_pair(l,r)],x);
        if(mn>l||(mn==l && mnAt>x)){
            mn=l;
            mnAt=x;
        }
        if(mx<r|| (mx==r && mxAt>x)){
            mx=r;
            mxAt=x;
        }
        int res=mnAt+mxAt;
        if(mp.find(make_pair(mn,mx))!=mp.end())
            res=min(res,mp[make_pair(mn,mx)]);
        cout<<res<<endl;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    w(t)
    {
        doit();
    }
}



// void it()
// {
//     int n;
//     cin>>n;
//     vector<ll>a[n];
//     int mi=INT_MAX;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<3;j++)
//         {   
//             int x;
//             cin>>x;
//             if(j==0)
//             {
//                 mi=min(x,mi);
//             }
//             a[i].push_back(x);
//         }
//     }

//     ll sum=a[0][2];
//     cout<<sum<<endl;
//     for(int i=1;i<n;i++){
//         if(a[i][1]>a[i-1][1])
//         {   int j=i;
//             while(a[j][0]<a[j-1][0]){
//                 sum-=a[j-1][2];
//                 j--;
//                 if(j==0)
//                     break;
//             }
//             sum+=a[i][2];
//         }
//         else if(a[i][1]==a[i-1][1]){
//             int j=i;
//             while(a[j][0]>a[j-1][0] ){
//                 if(mi<a[j-1][0])
//                     break;
//                 sum-=a[j-1][2];
//                 j--;
//                 if(j==0)
//                     break;
//             }
//         }
        
//         cout<<sum<<endl;
//     }
    


// }