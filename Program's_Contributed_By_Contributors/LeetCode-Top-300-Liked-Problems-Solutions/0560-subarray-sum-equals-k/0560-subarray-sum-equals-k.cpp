class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix;
        prefix[0] = 1;
        int cnt = 0, sum = 0, n = nums.size();

        for(int i = 0; i < n; i++){
            sum += nums[i];
            cout << "sum: " << i << ": " << sum << endl;
            if(prefix.find(sum - k) != prefix.end())
                cnt += prefix[sum - k];
            cout << "cnt: " <<  i << ": " << cnt << endl;
            if(prefix.find(sum) != prefix.end())
                prefix[sum] += 1;
            else
                prefix[sum] = 1;
        }
        return cnt;
    }
};


// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         unordered_map<int, int> prefix;
//         prefix[0] = 0;
//         int cnt = 0, sum = 0, n = nums.size();

//         for(int i = 1; i <= n; i++)
//             prefix[i] = prefix[i - 1] + nums[i - 1];

//         for(int i = 0; i <= n; i++){
//             for(int j = i + 1; j <= n; j++){
//                 sum = prefix[j] - prefix[i];
//                 if(sum == k)
//                     cnt += 1;
//             }
//         }
//         return cnt;
//     }
// };