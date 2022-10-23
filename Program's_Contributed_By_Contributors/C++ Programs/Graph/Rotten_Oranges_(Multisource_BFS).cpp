#include <bits/stdc++.h>
using namespace std;

// start BFS from all rotten oranges initiallly and Cnt time in every level
// until all oranges becomes rottten
int inf  = 1e5;

int orangesRotting(vector<vector<int>>& grid) {
    
    int r = grid.size(), c = grid[0].size();
    
    queue<pair<int,int>>q;
    vector<vector<int>>dis(r+1,vector<int>(c+1,inf));
    int time=0;
        
    // Multisource BFS
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==2){
                q.push({i,j});  //pushing all the rotten oranges intially in the queue
                dis[i][j] = 0;  // make 0 for all the starting points
            }
        }
    }
    
    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};
    
    while(!q.empty()){  
        
        int i = q.front().first, j = q.front().second;
        q.pop();

        for(int k=0;k<4;k++){
            int nx = i + dx[k], ny = j + dy[k];
            // going for fresh oranges to all its adjacent 
            if(nx>=0&&nx<r&&ny>=0&&ny<c && grid[nx][ny]==1 && dis[nx][ny]==inf){

                // if  we get fresh orange then mark it rotten and push into queue
                // update the distance of (nx,ny) means we can reach (nx,ny) from                               (i,j) in one step;     

                    q.push({nx,ny}); 
                    dis[nx][ny] = dis[i][j]+1;
                    time = max(time, dis[nx][ny]);
            }     
        }      
    }
    
    // If any rotten orange is remaining where we can't reach return -1
     for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==1 && dis[i][j]==inf){  
                return -1;
            }
        }
    } 
    return time;
}


 
// Input: 
// grid = [[2,1,1],
//         [1,1,0],
//         [0,1,1]]

// Output: 4