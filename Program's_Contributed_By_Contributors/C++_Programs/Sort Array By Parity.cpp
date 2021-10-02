#include <iostream>
#include <vector>
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        int count=0,t=0;
        vector<int> j;
        if(nums.size()!=1)
        {
            for (int i = 0; i < nums.size(); i++)
                if (nums[i]%2==0)
                {
                    nums[count++] = nums[i];
                }
                else
                {
                    j.push_back(nums[i]);
                }
            while (count < nums.size())
            {
                nums[count++] = j[t++];
            }
        }
        return nums;
    }
};
