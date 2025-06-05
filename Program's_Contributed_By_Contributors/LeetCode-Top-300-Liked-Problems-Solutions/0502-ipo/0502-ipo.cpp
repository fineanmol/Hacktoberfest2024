class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();
        std::vector<std::pair<int, int>> projects;

        // Creating vector of pairs (capital, profits)
        for (int i = 0; i < n; ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }

        // Sorting projects by capital required
        std::sort(projects.begin(), projects.end());

        // Max-heap to store profits, using greater to create a max-heap
        std::priority_queue<int> maxHeap;
        int i = 0;

        // Main loop to select up to k projects
        for (int j = 0; j < k; ++j) {
            // Add all profitable projects that we can afford
            while (i < n && projects[i].first <= w) {
                maxHeap.push(projects[i].second);
                i++;
            }

            // If no projects can be funded, break out of the loop
            if (maxHeap.empty()) {
                break;
            }

            // Otherwise, take the project with the maximum profit
            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};