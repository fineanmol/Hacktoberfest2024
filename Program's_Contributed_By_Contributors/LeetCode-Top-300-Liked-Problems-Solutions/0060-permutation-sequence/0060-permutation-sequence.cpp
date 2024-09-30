class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> nums;
        for(int i = 1; i < n; i++){
            fact = fact * i;
            nums.push_back(i);
        }
        nums.push_back(n);
        string ans = "";
        k -= 1;
        while(true){
            ans = ans + to_string(nums[k / fact]);
            nums.erase(nums.begin() + k / fact);
            if(nums.size() == 0) break;
            k = k % fact;
            fact = fact / nums.size();
        }

        return ans;
    }
};