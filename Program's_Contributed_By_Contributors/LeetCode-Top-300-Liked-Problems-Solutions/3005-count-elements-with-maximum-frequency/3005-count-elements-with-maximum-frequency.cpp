class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> f;
        
    for (int num : nums) {
        f[num]++;
    }

    int maxFrequency = 0;
    int maxFrequencyCount = 0;

    for (auto entry : f) {
        int frequency = entry.second;
        if (frequency > maxFrequency) {
            maxFrequency = frequency;
            maxFrequencyCount = 1;
        } else if (frequency == maxFrequency) {
            maxFrequencyCount++;
        }
    }

    return maxFrequencyCount * maxFrequency;
    }
};