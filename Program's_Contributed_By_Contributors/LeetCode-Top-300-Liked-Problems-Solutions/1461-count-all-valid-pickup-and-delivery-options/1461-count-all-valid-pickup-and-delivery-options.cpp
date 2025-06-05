class Solution {
public:
    int countOrders(int n) {
        long long res = 1;
        for (int i = 2 * n; i > 0; i -= 2)
            res = (res * i * (i - 1) / 2) % 1000000007;
        return res;
    }
};