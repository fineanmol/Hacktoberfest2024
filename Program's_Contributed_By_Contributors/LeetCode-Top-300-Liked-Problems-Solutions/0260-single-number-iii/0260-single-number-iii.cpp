class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long Xor = 0;

        for(int n : nums)
            Xor = Xor ^ n;
        
        // Find the rightMost bit that's different in both elements that appear exactly once
        int retainedLeftBits = (Xor & (Xor - 1));
        int rightMostBit = retainedLeftBits ^ Xor;

        int bucket1 = 0, bucket2 = 0;
        for(int n : nums){
            if(n & rightMostBit)
                bucket1 ^= n;
            else
                bucket2 ^= n;
        }
        return {bucket1, bucket2};
    }
};