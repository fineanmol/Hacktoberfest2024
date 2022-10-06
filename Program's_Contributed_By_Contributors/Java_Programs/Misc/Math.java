import java.util.*;

import javax.swing.text.DefaultStyledDocument.ElementSpec;

public class Math {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        double num1;
        double num2;
        double num3;
        System.out.println(
                "Welcome to math! This is a basic addition, subtraction, multiplication, and division calculator.");
        System.out.println("Input A (addition), S (subtraction), M (multiplication), or D (division");
        String type = sc.nextLine();

        if (type.equals("A") || type.equals("a")) {
            System.out.println("Enter in the first number you want to add");
            num1 = sc.nextInt();
            System.out.println("Enter the second number you want to add");
            num2 = sc.nextInt();

            num3 = num1 + num2;
            System.out.println(num1 + " plus " + num2 + " equals " + num3 + ".");
        } else if (type.equals("S") || type.equals("s")) {
            System.out.println("Enter in the first number");
            num1 = sc.nextInt();
            System.out.println("Enter the second number you want to subtract from the first number");
            num2 = sc.nextInt();

            num3 = num1 - num2;
            System.out.println(num1 + " minus " + num2 + " equals " + num3 + ".");
        } else if (type.equals("m") || type.equals("M")) {
            System.out.println("Enter in the first number you want to multiply");
            num1 = sc.nextInt();
            System.out.println("Enter the second number you want to multiply");
            num2 = sc.nextInt();

            num3 = num1 * num2;
            System.out.println(num1 + " times " + num2 + " equals " + num3 + ".");
        } else if (type.equals("d") || type.equals("D")) {
            System.out.println("Enter in the first number");
            num1 = sc.nextInt();
            System.out.println("Enter the second number you want to divide the first number by");
            num2 = sc.nextInt();

            num3 = num1 / num2;
            System.out.println(num1 + " divided by " + num2 + " equals " + num3 + ".");
        } else {
            System.out.println("Please enter a valid input.");
        }
    }
}
