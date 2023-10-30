#include <bits/stdc++.h>
using namespace std;


// hamiltonian cycle is a cycle covering every node once and 
// ends at starting node 
// here we need to minimise the hamiltonian cylce total coast 
 
const int n=4; 
const int dist[4][4]={{0,20,42,25},{20,0,30,34},{42,30,0,10},{25,34,10,0}};
const int visited_all = (1<<n)-1;

// this approch can only be used if no of nodes are less than 64


int tsp(int pos,int mask){
    if(mask==visited_all){
        return dist[pos][0];
        // from pos to zero 
    }
    int ans =INT_MAX;
    // try to go to an unvisited city 
    for(int city=0;city<n;city++){
        if((mask&(1<<city))==0){
            int newans = dist[pos][city]+tsp(city,(mask|(1<<city)));
            ans = min(ans,newans);
        }
    }
    return ans;
}

//     int flag = tsp(0,1);
//     cout<<flag<<"\n";
// 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t=1;
    cin>>t;
    while(t--){
        cout<<tsp(0,1)<<"\n";
    }
    return 0;
    
}
