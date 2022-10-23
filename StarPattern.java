import java.util.*;

public class StarPattern {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = 5;
        int ch = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print('*');
            }
            System.out.println();
        }
    }
}