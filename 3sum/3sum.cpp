class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
         vector<vector<int>> ans;
        if(nums.size() <=2)return ans;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i == 0 || nums[i] != nums[i-1])
            {
                int low = i+1;
                int high = nums.size()-1;
                int sum = 0 - nums[i];
                
                while(low<high)
                {
                    int currsum = nums[low] + nums[high];
                    if(currsum == sum)
                    {
                        vector <int> temp(3);
                        temp[0] = nums[i];
                        temp[1]= nums[low];
                        temp[2]= nums[high];
                        ans.push_back(temp); 
                        
                        
                    while(high>low && nums[low] == nums[low+1])low++;
                    while(high>low && nums[high] == nums[high-1])high--;
                    
                    low++;
                    high--;
                    }
                    else if(currsum>sum)
                    {
                        high--;
                    }
                    else
                    {
                        low++;
                    }
                    
                }  
            }
        }
        return ans;
    }
};