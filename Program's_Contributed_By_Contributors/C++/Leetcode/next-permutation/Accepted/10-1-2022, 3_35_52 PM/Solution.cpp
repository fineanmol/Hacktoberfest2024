// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int f = -1;
        for (int i = nums.size()-2;i>=0;i--){
            if (nums[i+1]>nums[i]){
                f = i;
                break;
            }
        }
        // cout<<"hello"<<endl;
        if (f==-1){
            reverse(nums.begin(),nums.end());
        } else {
            int mini = f+1;
            
            for (int i = f+2;i<nums.size();i++){
                if (nums[f]<nums[i] && nums[mini]>nums[i]){
                    mini = i;
                    if (nums[i] == nums[f]+1){
                        break;
                    }
                }
            }
            
            swap(nums[f],nums[mini]);
            
            sort(nums.begin()+f+1,nums.end());
        }
        
        
    }
};