import java.util.Scanner;

public class palindrome {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int x = in.nextInt();
int ok = x;

        int rem, rev = 0;

        while (x != 0)
        {
            rem = x % 10;
            rev = (rev * 10) + rem;
            x = x / 10;
        }
        System.out.println(rev);
        if (ok == rev) {
            System.out.println("true");
        }
    }
}
