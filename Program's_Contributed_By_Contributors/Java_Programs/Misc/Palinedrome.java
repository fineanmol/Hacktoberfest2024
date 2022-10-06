import java.util.*;

public class Palinedrome {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a number to check if its a Palindrome");
        int input = sc.nextInt();
        int pleng = 0;
        int x = input;
        int c = 0;
        int rev;
        int revt = 0;
        int in = input;
        while (input != 0) {
            input = input / 10;
            pleng++;
        }
        pleng--;
        while (pleng >= 0) {
            double dleng = pleng;
            double pow = Math.pow(10, dleng);
            int ipow = (int) (pow);
            rev = ipow * (in % 10);
            in = in / 10;
            revt = revt + rev;
            pleng--;
        }
        if (revt == x) {
            System.out.println("Your number is a palindrome");
        }
        if (revt != x) {
            System.out.println("Your number is NOT a palindrome");
        }
        System.out.println(revt + "," + x);
    }
}
