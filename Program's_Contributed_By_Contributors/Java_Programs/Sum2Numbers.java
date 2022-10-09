import java.util.Scanner;

public class Sum2Numbers {
  public static void main(String[] args) 
  {
    final var input = new Scanner (System.in);
    System.out.print("Input the first number: ");
    final var num1 = input.nextInt();
    System.out.print("Input the second number: ");
    final var num2 = input.nextInt();
    final var sum = num1 + num2;
    System.out.println();
    System.out.println("Sum: "+sum);
  }
}