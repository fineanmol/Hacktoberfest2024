
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

my solution using floyd Warshall
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0 ; i < n ; ++i) {
            dp[i][i] = 0;
        }
        
        for (const auto& e : edges) {
            int s = e[0];
            int d = e[1];
            int c = e[2];
            dp[s][d] = c;
            dp[d][s] = c;
        }
        
        for (int k = 0 ; k < n ; ++k) {
            for (int i = 0 ; i < n ; ++i) {
                for (int j = 0 ; j < n ; ++j) {
                    if (dp[i][j] > dp[i][k] + dp[k][j]) {
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                }
            }
        }
        
        int min = INT_MAX;
        vector<int> counts(n, 0);
        for (int i = 0 ; i < n ; ++i) {
            int count = 0;
            for (int j = 0 ; j < n ; ++j) {
                if (i == j) {
                    continue;
                }
                if (dp[i][j] <= distanceThreshold) {
                    ++count;
                }
            }
            min = std::min(min, count);
            counts[i] = count;
        }
        
        for (int i = n - 1 ; i >= 0 ; --i) {
            if (counts[i] == min) {
                return i;
            }
        }
        
        return -1;
    }
};
