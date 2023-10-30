#include <bits/stdc++.h>
using namespace std;


// classy no is no with atmost 3 non zero integers
// dp[L-R]=dp[r]-dp[l-1];cummulative
// whereas max kind of functions are not 

long long x;
string s,l,r;


bool issubsequence(string& s1, string& s2)
{
    long long n = s1.length(), m = s2.length();
    long long i = 0, j = 0;
    while (i < n && j < m) {
        if (s1[i] == s2[j])
            i++;
        j++;
    }
    return i == n;
}


long long ans(long long sz,string &str){
    if(sz==x){
        return (issubsequence(str,s)?0:1);
    }

    
    long long ret =-1;
    long long st = (l[sz]-'0');
    long long en = (r[sz]-'0');
    for(long long i=st;i<=en;i++){
        string arb  = str;
        char ch  = '0';
        ch+=i;
        arb.push_back(ch);
        if(issubsequence(arb,s)){
            ret = max(ret,ans(sz+1,arb));
        }else{
            ret =1;
            break;
        }
        if(ret){
            break;
        }
    }

    return ret;
    
}

void solve(){
   cin>>s;
   cin>>x;
   cin>>l>>r;
   
   string str = "";
   cout<<(ans(0,str)==1?"YES":"NO")<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    long long  t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
    
}
