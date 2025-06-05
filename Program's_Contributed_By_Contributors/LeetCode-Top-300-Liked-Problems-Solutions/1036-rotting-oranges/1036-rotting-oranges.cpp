class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0)); 
        queue<pair<pair<int, int>, int>> q; // {{r, c}, t}
        int cntFresh = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else
                    vis[i][j] = 0;
                
                if(grid[i][j] == 1)
                    cntFresh++;
            }
        }

        int cnt = 0;
        int dr[] = {0, 0, 1, -1};
        int dc[] = {-1, 1, 0, 0};
        int tmax = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tmax = max(tmax, t);
            for(int i = 0; i < 4; i++){
                int nrow = r + dr[i];
                int ncol = c + dc[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }

        if(cnt != cntFresh) return -1;

        return tmax;

    }
};