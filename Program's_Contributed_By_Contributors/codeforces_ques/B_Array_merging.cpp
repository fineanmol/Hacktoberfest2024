B_Array_merging.cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout<<"YES"<<"\n"
#define no cout<<"NO"<<"\n"
#define line cout<<"\n"

#define fori(i,a,n) for(int i=a;i<n;i++)
#define ford(i,n,a) for(int i=n-1;i>=a;i--)
#define cap(s) std::transform(s.begin(), s.end(), s.begin(), std::ptr_fun<int, int>(std::toupper))
#define small(s) std::transform(s.begin(), s.end(), s.begin(), std::ptr_fun<int, int>(std::tolower))
const int mod = 1e9 + 7;
int mod_mul(int a, int b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
int mod_add(int a, int b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b);}
 
int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    
    int t;
    cin>>t;
    while(t--){
         
         int n;
         cin>>n;
         vector<int>a(n),b(n);
           unordered_map<int,int>mp;
         for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]++;
         }
         for(int i=0;i<n;i++){
            cin>>b[i];
            mp[b[i]]++;
         }
         int ans = INT_MIN;
         for(auto it:mp){
            if(it.second>ans){
                ans = it.second;
            }
         }

       
         cout<<ans<<endl;
    }
     
    
 }
 






