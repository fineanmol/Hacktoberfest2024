import java.util.Scanner;

public class Reverse_Integer {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        sc.close();
        int result = 0;


        while (num != 0) {

            int remainder = num % 10;
            result = result * 10 + remainder;
            num = num / 10;
        }
        System.out.println(result);
    }
}
