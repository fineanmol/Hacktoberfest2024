class Solution {
public:
    double distance(vector<int>& point) {
        return sqrt(point[0] * point[0] + point[1] * point[1]);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<double, vector<int>>> pq;

        for (vector<int>& pt : points) {
            double dist = distance(pt);
            pq.push({dist, pt});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};