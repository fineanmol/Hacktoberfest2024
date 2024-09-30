class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> mp;
        long long ans = 0;
        for(int i = 0; i < rectangles.size(); i++){
            double val =  rectangles[i][0] / (rectangles[i][1] * 1.0);
            ans += (1LL * mp[val]);
            mp[val]++;
        }
        return ans;
    }
};