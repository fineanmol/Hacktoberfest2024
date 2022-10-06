/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		try{
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		sc.nextLine();
		while(t-->0)
		{
		    String s=sc.nextLine();
		  //  System.out.println(s);
		    int l=s.length();
		    for(int i=0; i<l; i++)
		    {
		        if(i<(l-2))
		        {
		            if(s.charAt(i)=='a'||s.charAt(i)=='e'||s.charAt(i)=='i'||s.charAt(i)=='o'||s.charAt(i)=='u')
		            {
		                if(s.charAt(i+1)=='a'||s.charAt(i+1)=='e'||s.charAt(i+1)=='i'||s.charAt(i+1)=='o'||s.charAt(i+1)=='u')
		                {
		                    if(s.charAt(i+2)=='a'||s.charAt(i+2)=='e'||s.charAt(i+2)=='i'||s.charAt(i+2)=='o'||s.charAt(i+2)=='u')
		                    {
		                        System.out.println("Happy");
		                        break;
		                    }
		                }
		            }
		        }
		        else
		        {
		        System.out.println("Sad");
		        break;
		        }
		    }
		}
		}
		catch(Exception e)
		{
		    return;
		}
	}
}
