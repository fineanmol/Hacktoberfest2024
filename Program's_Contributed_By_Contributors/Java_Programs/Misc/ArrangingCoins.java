public class ArrangingCoins {
    // Question Link:
    // https://leetcode.com/problems/arranging-coins/
    
    public static void main(String[] args) {
        int coins = 8;
        System.out.print(arrangeCoins(coins));
    }
    // 1. Brute-force:
    /*
    static int arrangeCoins(int n) {
        int i = 1;
        while (n >= i) {
            n = n - i;
            i++;
        }
        return i - 1;
    }
     */

    // 2. Optimized Approach (Binary Search):
    static int arrangeCoins(int n) {
        long start = 0;
        long end = n;
        while (start <= end) {
            long mid = start + (end - start) / 2;
            if (n > (mid*(mid+1)/2)) {
                start = mid + 1;
            } else if (n < (mid*(mid+1)/2)) {
                end = mid - 1;
            } else {
                return (int)mid;
            }
        }
        return (int)end;
    }

    // 3. Constant Time (using Mathematical Approach):
    /*
    static int arrangeCoins(int n) {
        return (int)(-0.5 + Math.sqrt(2 * (long)n + 0.25));
    }
     */
}