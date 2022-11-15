class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int closest = nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i == 0 || nums[i] != nums[i-1])
            {
                int j = i+1;
                int k = nums.size()-1;
                
                while(j<k)
                {
                    int sum = nums[i]+nums[j]+nums[k];
                    if(sum == target)return sum;
                    if(abs(target - sum) < abs(target-closest))
                    {
                        closest = sum;
                    }
                    else if(target > sum )
                    {
                        j++;
                    }
                    else
                        k--;
                }
            }
        }
        return closest;
        
    }
};