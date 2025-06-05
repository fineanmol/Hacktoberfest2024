class Solution {
public:
    int isAlmostEqual(int x, int y){
        string s = to_string(x), t = to_string(y);
        int n = s.length(), m = t.length();
        int maxLen = max(n, m);

        while(n != maxLen){
            s = "0" + s;
            n++;
        }
        while(m != maxLen){
            t = "0" + t;
            m++;
        }
        unordered_map<int, int> mp1, mp2;
        int diff = 0;
        for(int i = 0; i < maxLen; i++){
            diff += (s[i] != t[i]);
            mp1[s[i]]++;
            mp2[t[i]]++;
            if(diff > 2) return 0;
        }
        return diff <= 2 && mp1 == mp2;
    }
    int countPairs(vector<int>& nums) {
        int totalCnt = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                totalCnt += isAlmostEqual(nums[i], nums[j]);
            }
        }
        return totalCnt;
    }
};