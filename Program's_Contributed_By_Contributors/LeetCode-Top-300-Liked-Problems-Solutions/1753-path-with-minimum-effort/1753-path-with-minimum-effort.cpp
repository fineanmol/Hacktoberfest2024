class Solution {
    bool dfs(int i, int j, vector<vector<int>>& heights, int effort, int parent, vector<vector<int>>& vis)
     {                                                                      // make sure 'effort' should be max among all paths
        if(i<0 || i==heights.size() || j<0 || j==heights[0].size() || vis[i][j] || abs(parent - heights[i][j]) > effort)
         return false;

        if(i == heights.size()-1 && j == heights[0].size()-1)
         return true; //termination step

        vis[i][j] = 1; //visit current cell
        return dfs(i-1,j,heights,effort,heights[i][j],vis)
            || dfs(i,j+1,heights,effort,heights[i][j],vis)
            || dfs(i+1,j,heights,effort,heights[i][j],vis)
            || dfs(i,j-1,heights,effort,heights[i][j],vis);
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ans = INT_MAX, m = heights.size(), n = heights[0].size(), p = heights[0][0], curr = 0;
        int low = 0, high = 1e6;
        //apply binary search on possible values of effort
        while(low <= high)
        {
            int mid = (low + high)/2;
            vector<vector<int>> vis(m,vector<int>(n,0));

            //check if we can reach last cell having 'mid' as the maximum effort
            if(dfs(0,0,heights,mid,heights[0][0],vis)) //if possible
             high = mid - 1; //then, find a lesser effort to reach the end
            else
             low = mid + 1; //otherwise, we have to find a higher effort
        }
    return low;
    }
};