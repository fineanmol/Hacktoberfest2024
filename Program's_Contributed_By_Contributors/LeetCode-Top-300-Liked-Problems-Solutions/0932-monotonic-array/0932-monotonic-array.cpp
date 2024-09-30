class Solution {
public:
    // bool isMonotonic(vector<int>& nums) {
    //     int n = nums.size();
    //     if(nums[0] < nums[n - 1]){
    //         for(int i = 0; i < n - 1; i++){
    //             if(nums[i] > nums[i + 1])
    //                 return false;
    //         }
    //     }
    //     else{
    //         for(int i = 0; i < n - 1; i++){
    //             if(nums[i] < nums[i + 1])
    //                 return false;
    //         }
    //     }
    //     return true;
    // }

    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        bool increase = true;
        bool decrease = true;
        for(int i = 0; i < n - 1; i++) {
            if(A[i] > A[i+1]) increase = false;
            if(A[i] < A[i+1]) decrease = false;
            if(increase == false && decrease == false) return false;
        }
        return true;
    }
};