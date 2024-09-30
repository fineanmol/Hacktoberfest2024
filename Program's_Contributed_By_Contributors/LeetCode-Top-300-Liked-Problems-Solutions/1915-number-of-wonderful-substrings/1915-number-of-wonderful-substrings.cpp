class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<long long> count(1024, 0); // 2^10 to store XOR values
        long long result = 0;
        int prefixXor = 0;
        count[prefixXor] = 1;

        for (char ch : word) {
            int charIndex = ch - 'a';
            prefixXor ^= 1 << charIndex;
            result += count[prefixXor];
            for (int i = 0; i < 10; i++) {
                result += count[prefixXor ^ (1 << i)];
            }
            count[prefixXor]++;
        }

        return result;
    }
};