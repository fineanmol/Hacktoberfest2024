public class BinarySearchSQRT {
    public static void main(String[] args) {

        int n = 40;
        int p = 3;
        System.out.println(sqrt(n, p));
    }

    // tc = O(p*log(n))
    static double sqrt(int n, int p) {
        // double root = 0.0;
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int s = 1; // start
        int e = n; // end
        while (s > e) {
            int m = s + (e - s) / 2;
            if (m * m == n) {
                return m;
            }
            if (m * m > e)
                e = m - 1;
            else
                s = m + 1;
        }
        double root = e;
        double incr = 0.1;
        for (int i = 0; i < p; i++) {
            while (root * root < n) {
                root += incr;
            }
            root -= incr;
            incr /= 10;
        }
        return root;
    }
}
