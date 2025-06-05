class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftPrefix(n, 0), rightPrefix(n, 0);
        leftPrefix[0] = nums[0];
        rightPrefix[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i++){
            leftPrefix[i] = leftPrefix[i - 1] + nums[i];
        }
        for(int i = n - 2; i >= 0; i--){
            rightPrefix[i] = rightPrefix[i + 1] + nums[i];
        }

        // int left = 0, right = n - 1;
        // int ans = -1;
        // while(left <= right){
        //     int mid = (left + right) >> 1;
        //     if(leftPrefix[mid] >= rightPrefix[mid]){
        //         if(leftPrefix[mid] == rightPrefix[mid])
        //             ans = mid;
        //         right = mid - 1;
        //     }
                
        //     else if(leftPrefix[mid] < rightPrefix[mid])
        //         left = mid + 1;      
        // }

        for(int i = 0; i < n; i++){
            if(leftPrefix[i] == rightPrefix[i])
                return i;
        }

        return -1;
    }
};