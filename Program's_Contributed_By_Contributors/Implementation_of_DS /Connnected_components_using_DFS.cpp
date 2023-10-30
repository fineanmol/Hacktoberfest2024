#include <bits/stdc++.h>
using namespace std;

int n,m,k;
const int N = 100;
const int M = 100;
int visited[N][M];
char adj[N][M];



void dfs(int i,int j,int &ans){

    if((i>n-1 or j>m-1 or i<0 or j<0) ){
        return;
    }

    if(adj[i][j]=='*'){
        return;
    }

    visited[i][j]=1;
    ans++;


    for(int dx=-1;dx<=1;dx++){
        for(int dy=-1;dy<=1;dy++){
            if((abs(dx)+abs(dy))!=2){
                if(visited[i+dx][j+dy]==0){
                   dfs(i+dx,j+dy,ans);
                }
            }
        }
    }

    if((i==n-1 or j==m-1 or i==0 or j==0) ){
         if(adj[i][j]=='.'){
            ans=0;
         }
    }

}

void solve(){
    cin>>n>>m>>k;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>adj[i][j];
        }
    } 

    memset(visited,0,sizeof visited);

    vector<pair<int,pair<int,int>>> ans;
    int cnt =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]=='.' and visited[i][j]==0){
               int x=0;
               dfs(i,j,x);
               ans[cnt].first=x;
               ans[cnt].second.first = i;
               ans[cnt].second.second = j;
               cnt++;
            }
        }
    } 


    sort(ans.begin(),ans.end());
    int res =0; 
    for(int i=0;i<ans.size()-k;i++){
         res+=ans[i].first;
    }
    cout<<res<<"\n";



}

int  main()
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
