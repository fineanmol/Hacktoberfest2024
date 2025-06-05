class Solution {
public:
    int search(vector<int>& nums, int target) {
        //find the Rotation point!
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
               return mid;
            }
            else if(nums[mid]>=nums[low]){//sorted left half
                if(nums[mid]>target && nums[low]<=target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else if(nums[mid]<=nums[high]){//sorted right half
                if(nums[mid]<target && nums[high]>=target){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};
