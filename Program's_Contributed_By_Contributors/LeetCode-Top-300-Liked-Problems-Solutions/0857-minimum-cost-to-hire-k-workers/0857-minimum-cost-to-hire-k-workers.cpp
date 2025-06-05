class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage,
                                int k) {
        int n = quality.size();
        double minCost = DBL_MAX; // Equivalent to float('inf') in Python
        double qualityTillNow = 0;

        // Vector to store ratio and quality, which will be used to create a
        // min-heap
        vector<pair<double, int>> wageQualityRatio;
        for (int i = 0; i < n; ++i) {
            wageQualityRatio.emplace_back(
                static_cast<double>(wage[i]) / quality[i], quality[i]);
        }

        // Sort by ratio to mimic a min-heap pop operation
        sort(wageQualityRatio.begin(), wageQualityRatio.end());

        // Max-heap to store qualities; C++ priority_queue is a max-heap by
        // default
        priority_queue<int> highQualityWorkers;

        for (int i = 0; i < n; ++i) {
            double ratio = wageQualityRatio[i].first;
            int qua = wageQualityRatio[i].second;

            qualityTillNow += qua;
            highQualityWorkers.push(qua);

            // If we have more than k workers, remove the one with the highest
            // quality
            if (highQualityWorkers.size() > k) {
                qualityTillNow -= highQualityWorkers.top();
                highQualityWorkers.pop();
            }

            // Calculate cost when we have exactly k workers
            if (highQualityWorkers.size() == k) {
                minCost = min(minCost, qualityTillNow * ratio);
            }
        }

        return minCost;
    }
};