// https://leetcode.com/problems/4sum

class Solution {
    
    vector<vector<int>> ksum(vector<int>& nums,int k,long target,int s,int e){
        
        long prod1 = (long)nums[s]*k;
        long prod2 = (long)nums[e]*k;
        if (e-s+1<k ||prod1 >target || prod2<target){
            return {};
        }
        
        if (k==2){
            int i = s,j = e;
            vector<vector<int>> result;
            while (i<j){
                int sum = nums[i] + nums[j];
                
                if (sum==target){
                    result.push_back({nums[i],nums[j]});
                    while (i<j && nums[i+1]==nums[i]){
                        i++;
                    }
                    i++;
                    
                    while (i<j && nums[j-1]==nums[j]){
                        j--;
                    }
                    j--;
                }
                
                else if (sum>target){
                    while (i<j && nums[j-1]==nums[j]){
                        j--;
                    }
                    j--;
                } else {
                    while (i<j && nums[i+1]==nums[i]){
                        i++;
                    }
                    i++;
                }
            }
            
            return result;
        }
        
        else {
            vector<vector<int>> result;
            for (int i = s;i<e;i++){
                
                auto sresult = ksum(nums,k-1,(long)target-nums[i],i+1,e);
                
                for (auto v:sresult){
                    if (v.size()>0){
                        v.push_back(nums[i]);
                        result.push_back(v);
                    }
                }
                
                while (i<e && nums[i+1] == nums[i]){
                    i++;
                }
                
            }
            
            return result;
        }
        
        
    }
    
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int e = nums.size()-1;
        
        return ksum(nums,4,target,0,e);
        
        
    }
};