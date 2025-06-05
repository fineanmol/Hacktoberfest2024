class Solution {
public:
    int nextGreaterElement(int num) {
        if (num < 10) return -1;

        string s = to_string(num);
        int n = s.length();

        int break_pt = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] < s[i + 1]) {
                break_pt = i;
                break;
            }
        }

        if (break_pt == -1) {
            return -1; // No greater integer is possible
        }

        int rightmost = -1;
        for (int i = n - 1; i > break_pt; i--) {
            if (s[i] > s[break_pt]) {
                if (rightmost == -1 || s[i] < s[rightmost]) { // edge case
                    rightmost = i;
                }
            }
        }

        swap(s[break_pt], s[rightmost]);
        reverse(s.begin() + break_pt + 1, s.end());

        long long ans = stoll(s); // Use long long to avoid overflow
        if (ans <= INT_MAX) // Check if ans fits within 32-bit integer range
            return static_cast<int>(ans);

        return -1;
    }
};
