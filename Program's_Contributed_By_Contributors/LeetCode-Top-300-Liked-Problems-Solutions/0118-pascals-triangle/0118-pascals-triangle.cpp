class Solution {
public:
    vector<int> getRow(int n) {
        if(n == 0) return {1};
        long ans = 1;
        vector <int> v;
        v.push_back(ans);

        for(int i = 1; i <= n; i++){
            ans = ans * (n - i + 1);
            ans /= i;
            v.push_back(ans);
        }
        return v;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i < numRows; i++)
            ans.push_back(getRow(i));
        return ans;
    }
};