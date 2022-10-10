import java.io.*;  
import java.util.*;  
public class PetersonNumber
{  
//an array is defined for the quickly find the factorial  
static long[] factorial = new int[] { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};  
//driver code  
public static void main(String args[])  
{  
//constructor of the Scanner class  
Scanner sc = new Scanner(System.in);  
System.out.print("Enter a number to check: ");  
//reading a number from the user  
int n=sc.nextInt();  
//calling the user-defined function to check Peterson number  
if (isPeterson(n))  
System.out.println("The given number is a Peterson number.");  
else  
System.out.println("The given number is not a Peterson number.");  
}  
//function to check the given number is Peterson or not  
static boolean isPeterson(int n)  
{  
int num = n;  
int sum = 0;  
//loop executes until the condition becomes false  
while (n > 0)   
{  
//determines the last digit of the given number      
int digit = n % 10;  
//determines the factorial of the digit and add it to the variable sum  
sum += factorial[digit];  
//removes the last digit of the given number  
n = n / 10;  
}  
//compares sum with num if they are equal returns the number itself  
return (sum == num);  
}  
}  
