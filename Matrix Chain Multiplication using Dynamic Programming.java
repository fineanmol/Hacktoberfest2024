
class Main
{
    // Function to find the most efficient way to multiply
    // a given sequence of matrices
    public static int matrixChainMultiplication(int[] dims, int i, int j)
    {
        // base case: one matrix
        if (j <= i + 1) {
            return 0;
        }
 
        // stores the minimum number of scalar multiplications (i.e., cost)
        // needed to compute matrix `M[i+1] … M[j] = M[i…j]`
        int min = Integer.MAX_VALUE;
 
        // take the minimum over each possible position at which the
        // sequence of matrices can be split
 
        /*
            (M[i+1]) × (M[i+2]………………M[j])
            (M[i+1]M[i+2]) × (M[i+3…………M[j])
            …
            …
            (M[i+1]M[i+2]…………M[j-1]) × (M[j])
        */
 
        for (int k = i + 1; k <= j - 1; k++)
        {
            // recur for `M[i+1]…M[k]` to get an `i × k` matrix
            int cost = matrixChainMultiplication(dims, i, k);
 
            // recur for `M[k+1]…M[j]` to get an `k × j` matrix
            cost += matrixChainMultiplication(dims, k, j);
 
            // cost to multiply two `i × k` and `k × j` matrix
            cost += dims[i] * dims[k] * dims[j];
 
            if (cost < min) {
                min = cost;
            }
        }
 
        // return the minimum cost to multiply `M[j+1]…M[j]`
        return min;
    }
 
    // Matrix Chain Multiplication Problem
    public static void main(String[] args)
    {
        // Matrix `M[i]` has dimension `dims[i-1] × dims[i]` for `i=1…n`
        // input is 10 × 30 matrix, 30 × 5 matrix, 5 × 60 matrix
        int[] dims = { 10, 30, 5, 60 };
 
        System.out.print("The minimum cost is " +
                matrixChainMultiplication(dims, 0, dims.length - 1));
    }
}
