#include <bits/stdc++.h>
using namespace std;

/*
    Dreams never shine!
    It's you that shine while chasing your dreams :)
*/

using ll = long long;

/* 
    example 1
    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4

    example 2
    Input: nums = [4,5,6,7,0,1,2], target = 3
    Output: -1
*/


/*
    time complexity: O(logn)
    space complexity (considering only extra space): O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        
        int index = -1;
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            
            if (target == nums[mid])
            {
                index = mid;
                break;
            }
            
            if (nums[left] < nums[mid])
            {
                // left half is sorted
                if (target == nums[left])
                {
                    index = left;
                    break;
                }
                if (target > nums[left] and target < nums[mid])
                    right = mid;
                else
                    left = mid;
            }
            else
            {
                // right half is sorted
                if (target == nums[right])
                {
                    index = right;
                    break;
                }
                
                if (target > nums[mid] and target < nums[right])
                    left = mid;
                else
                    right = mid;
            }
        }
        
        if (target == nums[left])
            return left;
        if (target == nums[right])
            return right;
        
        return index;
    }
};

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    return 0;
}
