public class TrianglePattern {
    public static void main(String[] args) {

        /*
                   1
                 1   1
               1   2   1
             1   3   3   1
           1   4   6   4   1
         1   5  10  10   5   1
       1   6  15  20  15   6   1
     1   7  21  35  35  21   7   1
                                          */

        int n = 8;
        for (int i = 0; i < n; i++)
        {
            int number = 1;
            System.out.printf("%" + (n - i) * 2 + "s", "");
            for (int j = 0; j <= i; j++)
            {
                System.out.printf("%4d", number);
                number = number * (i - j) / (j + 1);
            }
            System.out.println();
        }
    }
}
