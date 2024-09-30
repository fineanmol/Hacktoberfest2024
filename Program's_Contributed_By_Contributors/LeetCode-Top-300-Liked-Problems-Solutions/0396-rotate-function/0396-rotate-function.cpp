class Solution {
public:
    // int maxRotateFunction(vector<int>& nums) {
    //     int n = nums.size();
    //     int maxVal = INT_MIN;
    //     for(int i = 0; i < n; i++){
    //         int prod = 0;
    //         for(int j = 0; j < n; j++){
    //             prod += j * nums[(i + j) % n];
    //         }
    //         maxVal = max(prod, maxVal);
    //     }

    //     return maxVal;
    // }

    // Siliding window 
    int maxRotateFunction(vector<int>& nums){
        int n = nums.size();

        int sum = 0, f0 = 0;
        // Calculate for first element
        for(int i = 0; i < n; i++){
            sum += nums[i];
            f0 += nums[i] * i;
        }
        // For remaining elements, f(n) = f(n - 1) + sum - n * nums[n - 1]; 
        // where n * nums[n - 1] => multiplication value of previous's last element

        int ans = f0;

        for(int i = n - 1; i >= 1; i--){
            f0 = f0 + sum - (n * nums[i]);
            ans = max(ans, f0);
        }

        return ans;
        
    }

};

/*
n - size of array
f0 = 0*nums[0] + 1 * nums[1] + ... + (n-1)*nums[n-1];
f1 = 1*nums[0] + 2 * nums[1] +     + 0 * nums[n-1];
f1 - f0 = (nums[0] + nums[1] + ... + nums[n-1]) - n * (nums[n-1]);

=> f1 = f0 + sum - n * (nums[n - 1]);

f(x) = f(x-1) + (sum of array) - (product value of the last element of previous state);

*/