class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() == 0)
            return ans;
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int rem = target -nums[i] - nums[j];
                
                int low = j+1;
                int high = n-1;
                
                while(high>low)
                {
                 int two_sum = nums[low]+nums[high];
                    if(two_sum == rem)
                    {
                        vector<int> temp(4,0);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[low];
                        temp[3] = nums[high];
                        ans.push_back(temp);
                        
                        while(high>low && nums[low] == nums[low+1])
                            low++;
                        while(high>low && nums[high] == nums[high-1])
                            high--;
                        
                        low++;
                        high--;
                    }
                    else if(two_sum < rem)
                    {
                        low++;
                    }
                    else
                        high--;
                        
                }
                 while(j + 1 < n && nums[j + 1] == nums[j]) ++j;
            }
             while (i + 1 < n && nums[i + 1] == nums[i]) ++i;
        }
        return ans;
    }
};