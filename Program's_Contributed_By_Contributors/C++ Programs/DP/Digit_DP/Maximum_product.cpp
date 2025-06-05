#include <bits/stdc++.h>
using namespace std;
 

 // int overflow

string a,b;long long n;
pair<long long,string> dp[20][2][2][2];


pair<long long,string> ans(long long pos ,long long t1,long long t2,long long st){
    if(pos==n){
        return {1,""};
    }
    if(dp[pos][t1][t2][st].first!=-1){
        return dp[pos][t1][t2][st];
    }
    long long mi = t1?(a[pos]-'0'):0;
    long long ma = t2?(b[pos]-'0'):9;
    long long flag =INT_MIN;
    string str="";
    for(long long i=mi;i<=ma;i++){
        long long val;
        if(st ==0 and i==0){
          val =1;
        }else{
          val =i;
        }
        pair<long long,string> dpans = ans(pos+1,t1&(i==mi),t2&(i==ma),st|(i>0));
        long long re = val*dpans.first;

        if(re>=flag){
            str = dpans.second;
            if(st ==0 and i==0){
               str.push_back('0');
            }else{
               str.push_back('0'+i);
            }
            flag = re;
        }
    }

    dp[pos][t1][t2][st].second=str;
    dp[pos][t1][t2][st].first=flag;

    return dp[pos][t1][t2][st];

}
void solve(){
    cin>>a>>b;n=b.size(); 
    reverse(a.begin(),a.end());
    while(a.size()<n){
        a.push_back('0');
    }
    reverse(a.begin(),a.end());
    
    for(long long i=0;i<20;i++){
        for(long long j=0;j<2;j++){
            for(long long k=0;k<2;k++){
                for(long long l=0;l<2;l++){
                    dp[i][j][k][l].first=-1;
                }
            }
        }
    }

    pair<long long,string> re = ans(0,1,1,0);
    string res = re.second;
    reverse(res.begin(),res.end());
    bool flag =false;
    for(auto i: res){
       if(i!='0'){
        flag =true;
       }
       if(flag){
        cout<<i<<"";
       }
    }

    cout<<"\n";
   

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    long long t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
    
}
