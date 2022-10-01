//https://leetcode.com/problems/find-the-duplicate-number/

//code
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]<=mid){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
