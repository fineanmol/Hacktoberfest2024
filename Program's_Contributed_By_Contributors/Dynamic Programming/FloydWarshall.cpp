#include<iostream>
using namespace std;

//All pairs shortest path using DP.
#define V 4
#define INF 10000000

void allPairShortest(int graph[][V]){
int dp[V][V];

for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
        dp[i][j] = graph[i][j];
    }
}

for(int k=0;k<V;k++){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            dp[i][j] = min( dp[i][k]+dp[k][j],dp[i][j]);

        }
    }
}

for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
        cout<<dp[i][j]<<" ";
    }
    cout<<endl;
}

return;
}


int main(){
int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
allPairShortest(graph);

return 0;
}
