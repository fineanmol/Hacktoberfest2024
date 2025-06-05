class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int smallest = INT_MAX, largest = INT_MIN;

        for(int num : nums){
            smallest = min(num, smallest);
            largest = max(num, largest);
        }

        // edge case: largest - k < smallest + k => In that case, the diff could be taken as 0

        return max(0, largest - k - (smallest + k));

    }

    //        <|------------------------|>
    //  smallest                      largest

    // To get minimum difference,
    //        <---------|-----|--------->
    //       smallest + k     largest - k 
};