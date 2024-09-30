class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> intervals;
        
        for (int i = 0; i <= n; ++i) {
            intervals.emplace_back(max(0, i - ranges[i]), min(n, i + ranges[i]));
        }
        
        sort(intervals.begin(), intervals.end());
        
        int taps = 0, i = 0, end = 0, nextEnd = 0;
        
        while (end < n) {
            while (i <= n && intervals[i].first <= end) {
                nextEnd = max(nextEnd, intervals[i].second);
                ++i;
            }
            
            if (end == nextEnd) {
                return -1;
            }
            
            end = nextEnd;
            ++taps;
        }
        
        return taps;
    }
};