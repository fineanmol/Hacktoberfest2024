class Backtracking {
    private static long[] fC;
    static boolean flag = true;

    private static long fibonacci(int n) {
        if (n <= 1) {
            return n;
        }
        if (fC[n] != 0) {
            if (flag) {
                for (long i : fC) {
                    System.out.print("fC:  " + i + " ");
                    System.out.println();
                    flag = false;
                }
            }
            return fC[n];
        }
        long FibonacciNumber = (fibonacci(n - 1)) + fibonacci(n - 2);
        fC[n] = FibonacciNumber;
        return FibonacciNumber;
    }

    public static void main(String args[]) {
        String str = "ABCD";
        int n = 50;
        fC = new long[n + 1];
        System.out.println(fibonacci(n));
        System.out.print("Main: ");
        for (long i : fC) {
            System.out.print(i + " ");
        }
    }
}