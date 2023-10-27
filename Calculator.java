import java.util.Scanner;

public class MirrorInverse {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int number = scanner.nextInt();

        if (isMirrorInverse(number)) {
            System.out.println(number + " is a mirror-inverse number.");
        } else {
            System.out.println(number + " is not a mirror-inverse number.");
        }

        scanner.close();
    }

    // Function to check if a number is a mirror-inverse number
    static boolean isMirrorInverse(int number) {
        String numStr = String.valueOf(number);

        for (int i = 0; i < numStr.length(); i++) {
            int digit = Character.getNumericValue(numStr.charAt(i));
            int mirrorPosition = numStr.length() - 1 - i;

            if (digit != mirrorPosition) {
                return false;
            }
        }

        return true;
    }
}
