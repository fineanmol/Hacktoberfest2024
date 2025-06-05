class Solution {
public:
    // // Purely Bit Manipulation
    // vector<int> countBits(int n) {
    //     vector<int> ans;
    //     for(int i = 0; i <= n; i++){
    //         int sum = 0;
    //         int num = i;

    //         while(num){
    //             sum += num % 2;
    //             num /= 2;
    //         }

    //         ans.push_back(sum);
    //     }
    //     return ans;
    // }

    // Bit Manipulation with optimization using DP
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            ans[i] = ans[i >> 1] + (i & 1);
        }

        return ans;
    }
};