/*
====================================================================================
Title:  all possible permutation using recursion
Author: Bhupendra Dangwal
Date:   16-09-2022
====================================================================================
*/
#include <bits/stdc++.h>
using namespace std;
// void allPermutation(int nums[], int size){
//     int l = 0;
//     int r = size-1;
//     for(int i = 0; i < size-1; i++){
//         for(int j = 0; j < size-1; j++){
//             if(i != j){
//                 swap(nums[i], nums[j]);
//             }
//             for(int i = 0; i < size; i++){
//         cout<<nums[i];
//         }
//         cout<<endl;
//     }

//     }

// }

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