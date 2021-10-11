//Java program for Calculator : 
import java.util.Scanner;

public class Calculator {

  public static void main(String[] args) {

    // Declaration of  variables
    double num1 = 0.0, num2 = 0.0;
    char operator = '\0';

    Scanner scan = new Scanner(System.in);
    System.out.print("Enter two numbers: ");
    num1 = scan.nextDouble();
    num2 = scan.nextDouble();

    // Read operator
    System.out.println("Available Operators" + "are::  (+ - * / % ^)");
    System.out.print("Enter operator: ");
    operator = scan.next().charAt(0);

    // Using switch-case statements
    switch (operator) {

      case '+':
        System.out.println("Result = " + (num1 + num2));
        break;

      case '-':
        System.out.println("Result = " + (num1 - num2));
        break;

      case '*':
        System.out.println("Result = " + (num1 * num2));
        break;

      case '/':
        System.out.println("Result = " + (num1 / num2));
        break;

      case '%':
        System.out.println("Result = " + (num1 % num2));
        break;

      case '^':
        System.out.println("Result = " + Math.pow(num1, num2));
        break;

      default:
        System.out.println("Invalid operator");
    } // end of switch-case

    // close Scanner class object
    scan.close();

  }
}
//Program End 
