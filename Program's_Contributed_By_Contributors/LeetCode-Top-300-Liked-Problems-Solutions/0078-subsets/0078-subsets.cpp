class Solution {
public:

    void solve(int ind, vector<int> &arr, vector<vector<int>> &ans, vector<int> &nums)
    {
        if(ind == nums.size())
        {
            ans.push_back(arr);
            return;
        }
        //taking
        arr.push_back(nums[ind]);
        solve(ind + 1, arr, ans, nums);
        arr.pop_back();
        // not taking
        solve(ind + 1, arr, ans, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        solve(0, arr, ans, nums);
        return ans;
    }
};