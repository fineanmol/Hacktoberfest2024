class Solution {
    int firstOccurance(vector<int>& nums,int target)
    {
        int n = nums.size();
        int low = 0, high = n - 1, ans = -1;
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            if(nums[mid] >= target)
            {
                if(nums[mid] == target) ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1; 
        }
        return ans;
    }

    int lastOccurance(vector<int>& nums,int target)
    {
        int n = nums.size();
        int low = 0, high = n - 1, ans = -1;
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            if(nums[mid] <= target)
            {
                if(nums[mid] == target) ans = mid;
                low = mid + 1; 
            }
            else
                high = mid - 1;
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccurance(nums, target);
        if(first == -1) return {-1, -1};
        int last = lastOccurance(nums, target);
        return {first, last};
    }
};