class Solution {
public:
    const int MOD = 1e9 + 7;

    int sumSubarrayMins(const vector<int>& arr) {
        int n = arr.size();
        vector<long long> left(n), right(n);
        stack<int> s;

        // Calculate the nearest smaller element to the left for each element
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            left[i] = s.empty() ? i + 1 : i - s.top();
            s.push(i);
        }

        // Clear the stack for the next iteration
        while (!s.empty()) {
            s.pop();
        }

        // Calculate the nearest smaller element to the right for each element
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n - i : s.top() - i;
            s.push(i);
        }

        long long result = 0;

        // Calculate the sum of min(b) for each subarray
        for (int i = 0; i < n; ++i) {
            result = (result + arr[i] * left[i] * right[i]) % MOD;
        }

        return static_cast<int>(result);
    }
};