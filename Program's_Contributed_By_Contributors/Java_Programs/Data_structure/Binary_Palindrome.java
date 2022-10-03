// Binary Plaindrom in JAVA
// Write a program to check if the binary representation of a number is palindrome or not.

import java.util.*;
public class Main
{
	public static void main(String[] args) 
	{
	    Scanner sc = new Scanner(System.in);
	    int n = sc.nextInt();
	    int m = n;
	    int rev =0;
	    while(m>0)
	    {
	        rev<<= 1;
	        if((m & 1) == 1)
	        {
	            rev^= 1;
	        }
	        m >>= 1;
	    }
	    if(n == rev)
	    {
	        System.out.println("Binary representation of " + n + " is palindrome");   
	    }
	    else{
	        System.out.println("Binary representation of " + n + " is not palindrome");
	    }
	}
}
