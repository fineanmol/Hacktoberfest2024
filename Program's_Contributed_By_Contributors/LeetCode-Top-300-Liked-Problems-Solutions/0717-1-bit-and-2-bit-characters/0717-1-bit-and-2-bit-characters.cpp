class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;

        while (i < n - 1) {
            if (bits[i] == 1) { // If the current bit is 1, skip the next bit as it's part of a two-bit character
                i += 2;
            } else {
                i++;
            }
        }
        return i == n - 1;
    }
};
