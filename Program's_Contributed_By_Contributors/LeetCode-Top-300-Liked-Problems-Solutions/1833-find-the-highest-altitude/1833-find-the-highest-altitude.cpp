class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0, n = gain.size();
        vector<int> alt(n + 1, 0);
        for(int i = 0; i < n; i++){
            alt[i + 1] = alt[i] + gain[i];
            maxi = max(alt[i + 1], maxi);
        }
        return maxi;

        // alt[i-1] + gain[i]
        // 0, -5 => -5 
        // -5, 1 => -4
        // -4, 5 => 1
        // 1, 0 => 1
        // 1, -7 => -6
    }
};