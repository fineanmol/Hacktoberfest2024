class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // Max heap by default
        priority_queue<int> pq; 

        // Push all the happiness values into the priority queue
        for(const auto& h: happiness)
            pq.push(h); 

        long long totalHappinessSum = 0;
        int turns = 0;

        for(int i = 0; i < k; i++) {
            // Add the current highest value to the total happiness sum
            totalHappinessSum += max(pq.top() - turns, 0);

            // Remove the highest value after using it
            pq.pop(); 

            // Increment turns for the next iteration
            turns++; 
        }

        return totalHappinessSum;
    }
};