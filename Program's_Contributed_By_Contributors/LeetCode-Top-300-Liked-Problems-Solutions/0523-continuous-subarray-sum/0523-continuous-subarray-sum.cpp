class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> rems;
        rems[0] = -1;
        int sum = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int rem = sum % k;

            if(rems.count(rem)){
                if(i - rems[rem] > 1)
                    return true;
            }
            else
                rems[rem] = i;
        }
        return false;
    }
};


// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         if (k == 1)
//             return nums.size() >= 2;

//         int n = nums.size();
//         vector<int> prefix(n + 1, 0);

//         for (int i = 1; i <= n; i++) {
//             prefix[i] = prefix[i - 1] + nums[i - 1];
//             if (k != 0 && prefix[i] != 0 && i > 1 && prefix[i] % k == 0)
//                 return true;
//         }

//         if (k == 0) { // Handle case when k is 0
//             for (int i = 2; i <= n; i++) {
//                 if (prefix[i] == 0)
//                     return true;
//             }
//             return false;
//         }

//         for (int i = 1; i <= n; i++) {
//             for (int j = i + 1; j <= n; j++) { // Corrected loop
//                 int sum = prefix[j] - prefix[i - 1];
//                 if (sum % k == 0)
//                     return true;
//             }
//         }

//         return false;
//     }
// };
