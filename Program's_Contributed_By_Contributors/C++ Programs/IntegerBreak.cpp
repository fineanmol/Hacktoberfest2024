/*
  Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.
 */ 
  class Solution {
public:
    int integerBreak(int n) {
        // handle base cases
        if (n == 2) return 1;
        if (n == 3) return 2;

        // Dynamic programming table to store maximum products
        vector<int> maxProduct(n + 1, 0);

        // Base cases for numbers 1, 2, and 3 -only for computing for rest of numbers-
        maxProduct[1] = 1;
        maxProduct[2] = 2;
        maxProduct[3] = 3;

        // Fill the dynamic programming table for larger numbers
        for (int num = 4; num <= n; ++num) {
            int maxProductForNum = 0;
            // Iterate through smaller numbers to calculate the maximum product
            for (int subNum = 1; subNum <= num / 2; ++subNum) {
                maxProductForNum = max(maxProductForNum, maxProduct[subNum] * maxProduct[num - subNum]);
            }
            // Update the maximum product for the current number
            maxProduct[num] = maxProductForNum;
        }

        return maxProduct[n];
    }
};
