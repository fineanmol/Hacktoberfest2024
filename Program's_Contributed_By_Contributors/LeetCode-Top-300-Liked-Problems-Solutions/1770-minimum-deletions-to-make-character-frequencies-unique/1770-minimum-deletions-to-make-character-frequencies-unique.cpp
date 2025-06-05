class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> freq;
        int del = 0;

        for (char c : s) {
            freq[c]++;
        }

        unordered_set<int> usedFrequencies;

        for (auto& pair : freq) {
            int count = pair.second;
            while (usedFrequencies.count(count) > 0) {
                count--;  
                del++;    
            }
            if (count > 0) {
                usedFrequencies.insert(count);
            }
        }

        return del;
    }
};
