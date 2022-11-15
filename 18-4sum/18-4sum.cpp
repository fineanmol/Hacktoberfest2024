class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<4)return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++)
        {
            if(i==0 || nums[i] != nums[i-1])
            {
                for(int j=i+1;j<nums.size()-2;j++)
                {
                    if(j==i+1 || nums[j] != nums[j-1])
                    {
                        int k = j+1;
                        int l = nums.size()-1;
                        
                        while(k<l)
                        {
                            long long int sum = ( long long int)nums[i]+( long long int)nums[j]+( long long int)nums[k]+( long long int)nums[l];
                            if(sum == target)
                            {
                                ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                                
                                while(k<l && nums[k] == nums[k+1])k++;
                                while(k<l && nums[l] == nums[l-1])l--;
                                
                                k++;
                                l--;
                            }
                            else if(sum > target)
                            {
                                l--;
                            }
                            else
                                k++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};