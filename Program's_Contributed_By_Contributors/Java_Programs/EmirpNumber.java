import java.io.*;  
import java.util.*;  
public class EmirpNumber 
{  
//function that checks the given number is prime or not  
public static boolean isPrime(int n)  
{  
//base case  
if (n <= 1)  
return false;  
//loop executes from 2 to n-1  
for (int i = 2; i < n; i++)  
if (n % i == 0)  
//returns false if the condition returns true  
return false;  
//returns true if the condition returns false  
return true;  
}  
//function that checks if the given number is emirp or not  
public static boolean isEmirp(int n)  
{  
//checks if the given number is prime or not  
if (isPrime(n) == false)  
return false;  
//variable that stores the reverse of the number  
int reverse = 0;  
//the while loop executes until the specified condition becomes false  
while (n != 0)   
{  
//finds the last digit of the number (n)  
int digit = n % 10;  
//finds the reverse of the given number  
reverse = reverse * 10 + digit;  
//removes the last digit  
n = n/10;  
}  
//calling the user-defined function that checks the reverse number is prime or not  
return isPrime(reverse);  
}  
//driver code  
public static void main(String args[])   
{  
Scanner sc=new Scanner(System.in);  
System.out.print("Enter a number to check: ");  
//reading an integer from the user  
int n=sc.nextInt();  
if (isEmirp(n) == true)  
System.out.println("Yes, the given number is an emirp number.");  
else  
System.out.println("No, the given number is not an emirp number.");  
}  
}  
