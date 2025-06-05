/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

https://leetcode.com/problems/product-of-array-except-self/
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numZeros = 0;
        int product = 1;

        for (auto i : nums) {
            if (i != 0)
                product *= i;
            else
                numZeros++;
        }

        vector<int> products(nums.size(), 0);

        if (numZeros == 0) {
            for (int i = 0; i < nums.size(); i++) {
                products[i] = product / nums[i];
            }
        } 
        else if (numZeros == 1) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0)
                    products[i] = product;
            }
        }

        return products;
    }
};