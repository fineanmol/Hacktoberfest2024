class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle special cases
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool isPositive = !((dividend < 0) ^ (divisor < 0));

        // Convert both dividend and divisor to positive
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        long long ans = 0;

        while (n >= d) {
            int cnt = 0;
            while(n >= (d << (cnt + 1))){
                cnt += 1;
            }
            ans += (1 << cnt);
            n -= (d << cnt);
        }

        if(ans > INT_MAX && isPositive) 
            return INT_MAX;
        if(ans > INT_MAX && !isPositive)
            return INT_MIN;

        return isPositive ? ans : -1 * ans;

    }
};
