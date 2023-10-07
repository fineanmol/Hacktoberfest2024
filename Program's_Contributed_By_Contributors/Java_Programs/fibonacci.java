import java.util.Scanner;
public class Fibonacci {
    public static void main(String[] args) {
        int n, t1 = 0, t2 = 1;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a positive integer: ");
        n = sc.nextInt();
        System.out.print("First " + n + " terms: ");

        for (int i = 1; i <= n; ++i) {
            System.out.print(t1 + " + ");

            int sum = t1 + t2;
            t1 = t2;
            t2 = sum;
        }
    }
}