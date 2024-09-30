class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // Map to track of the frequencies of elements
        unordered_map<int, int> map;
        for (int i : arr) {
            map[i]++;
        }

        // Vector to track all the frequencies
        vector<int> frequencies;
        for (auto it : map) {
            frequencies.push_back(it.second);
        }

        // Sorting the frequencies
        sort(frequencies.begin(), frequencies.end());

        // Tracking the number of elements removed
        int elementsRemoved = 0;

        for (int i = 0; i < frequencies.size(); i++) {
            // Removing frequencies[i] elements which equates to
            // removing one unique element
            elementsRemoved += frequencies[i];

            // If the number of elements removed exceeds k, we'll return
            // the remaining number of unique elements.
            if (elementsRemoved > k) {
                return frequencies.size() - i;
            }
        }

        // We have removed all elements, so no unique integers remain
        // Return 0 in this case
        return 0;
    }
};