class Solution {
public:
    vector<vector<int>> generate(int n) {
        if(n==1){
            return {{1}};
        }
        vector<vector<int>>ans=generate(n-1);
        int x=n-2;
        vector<int>y;
        y.push_back(ans[x][0]);
        for(int i=0;i<ans[x].size()-1;i++){
            y.push_back(ans[x][i]+ans[x][i+1]);
        }
        y.push_back(ans[x][ans[x].size()-1]);
        ans.push_back(y);
        return ans;
    }
};
