import java.util.*;

// Generates a random value and prints it
public class GeneratesRandomValue {
    public static void main(String[] args) {
        Random random = new Random(); 
        int number1 = random.nextInt(100000);
        int randomnumber = encryption(number1);
        System.out.println(randomnumber);
    }
    public static int encryption(int num) {
        Random random = new Random(); 
        int x = random.nextInt(10057003);
        int y = random.nextInt(10037262);
        if (num % 2 == 0) {
            num /= 8;
            num = num + num * (x / 2);
        }
        else {
            num /= 86;
            num = num + num * (y / 5);
        }
        return num;
    }
}