class Main
{
    // Values (stored in array `v`)
    // Weights (stored in array `w`)
    // Total number of distinct items `n`
    // Knapsack capacity `W`
    public static int knapsack(int[] v, int[] w, int n, int W)
    {
        // base case: Negative capacity
        if (W < 0) {
            return Integer.MIN_VALUE;
        }

        // base case: no items left or capacity becomes 0
        if (n < 0 || W == 0) {
            return 0;
        }

        // Case 1. Include current item `v[n]` in the knapsack and recur for
        // remaining items `n-1` with decreased capacity `W-w[n]`

        int include = v[n] + knapsack(v, w, n - 1, W - w[n]);

        // Case 2. Exclude current item `v[n]` from the knapsack and recur for
        // remaining items `n-1`

        int exclude = knapsack(v, w, n - 1, W);

        // return maximum value we get by including or excluding the current item
        return Integer.max(include, exclude);
    }

    // 0–1 Knapsack problem
    public static void main(String[] args)
    {
        // input: a set of items, each with a weight and a value
        int[] v = { 20, 5, 10, 40, 15, 25 };
        int[] w = { 1, 2, 3, 8, 7, 4 };

        // knapsack capacity
        int W = 10;

        System.out.println("Knapsack value is " +
                knapsack(v, w, v.length - 1, W));
    }
}
