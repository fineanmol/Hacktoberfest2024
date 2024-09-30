class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0, n = fruits.size(), maxLen = 0;
        unordered_map<int, int> mp;

        while(r < n){
            mp[fruits[r]]++;
            while(mp.size() > 2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) 
                    mp.erase(fruits[l]);
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};