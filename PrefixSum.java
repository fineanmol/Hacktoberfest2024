// max prefix sum in 2d array {Matrix}

public class MatrixPrefixSum {

    public static void prefixSum2D(int[][] a)
    {
        int R = a.length;
        int C = a[0].length;

        int[][] psa = new int[R][C];

        psa[0][0] = a[0][0];

        // Filling first row and first column
        for (int i = 1; i < C; i++)
            psa[0][i] = psa[0][i - 1] + a[0][i];
        for (int i = 1; i < R; i++)
            psa[i][0] = psa[i - 1][0] + a[i][0];

        // updating the values in the
        // cells as per the general formula.
        for (int i = 1; i < R; i++)
            for (int j = 1; j < C; j++)

                // values in the cells of new array
                // are updated
                psa[i][j] = psa[i - 1][j] + psa[i][j - 1]
                        - psa[i - 1][j - 1] + a[i][j];

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++)
                System.out.print(psa[i][j] + " ");
            System.out.println();
        }
    }

    // driver code
    public static void main(String[] args)
    {
        int[][] a = { { 1, 2, 3, 4, 5 },
                      { 2, 3, 4, 5, 6 },
                      { 3, 4, 5, 6, 7 },
                      { 4, 5, 6, 7, 8 } };
        prefixSum2D(a);
    }
}
