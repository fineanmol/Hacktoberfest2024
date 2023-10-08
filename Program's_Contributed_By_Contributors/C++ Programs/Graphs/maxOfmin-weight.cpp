int maximumSafenessFactor(vector<vector<int>>& grid) {
        int x=grid.size();
        int y=grid[0].size();
        if(grid[0][0]==1 || grid[x-1][y-1]==1) return 0;
        vector<vector<int>> minDis(x,vector<int>(y,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            pair<int,int> index=q.front().first;
            int dis=q.front().second+1;
            q.pop();
            int row[4]={-1,0,+1,0};
            int col[4]={0,-1,0,+1};
            for(int i=0;i<4;i++){
                int nrow=index.first+row[i];
                int ncol=index.second+col[i];
                if(nrow>=0 && ncol>=0 && nrow<x && ncol<y && grid[nrow][ncol]==0){
                    if(minDis[nrow][ncol]>dis || minDis[nrow][ncol]==0){
                        minDis[nrow][ncol]=dis;
                        q.push({{nrow,ncol},dis});
                    }
                }
            }
        }
        vector<vector<int>> maxPathDis(x,vector<int>(y,0));
        vector<vector<int>> vis(x,vector<int>(y,0));
        priority_queue<pair<int,pair<int,int>> >pq;
        pq.push({minDis[0][0],{0,0}});
        maxPathDis[0][0]=minDis[0][0];
        while(!pq.empty()){
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            int dis=pq.top().first;
            pq.pop();
            if(vis[r][c]) continue;
            vis[r][c]=1;
            int row[4]={-1,0,+1,0};
            int col[4]={0,-1,0,+1};
            for(int i=0;i<4;i++){
                int nrow=r+row[i];
                int ncol=c+col[i];
                if(nrow>=0 && ncol>=0 && nrow<x && ncol<y && minDis[nrow][ncol]>0){
                    int temp=min(dis,minDis[nrow][ncol]);
                    if(maxPathDis[nrow][ncol]<temp){
                      maxPathDis[nrow][ncol]=temp;
                      pq.push({temp,{nrow,ncol}});
                    }
                }
            }
        }
        return maxPathDis[x-1][y-1];
    }