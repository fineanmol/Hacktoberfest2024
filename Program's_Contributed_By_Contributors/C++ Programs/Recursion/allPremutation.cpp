/*
====================================================================================
Title:  all possible permutation using recursion
Author: Bhupendra Dangwal
====================================================================================
*/
#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &res, vector<int> &nums, int i)
{
    if (i == nums.size())   // base condition
    {
        res.push_back(nums);
        return;
    }
    for (int j = i; j < nums.size(); j++)
    {
        swap(nums[i], nums[j]);
        helper(res, nums, i + 1);
        swap(nums[i], nums[j]);
    }
    return;
}

void permute(vector<int> &nums)
{
    vector<vector<int>> res;
    helper(res, nums, 0);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j<res[0].size();j++){
            cout<<res[i][j];
        }
        cout<<endl;
    }
}

int main()
{

    vector<int> nums = {1, 2, 3};
    int size = sizeof(nums) / sizeof(nums[0]);
    permute(nums);
    return 0;
}