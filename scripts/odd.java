import java.util.Scanner;

class odd
{
    public static void main(String args[])   
    {  
    	Scanner sc = new Scanner(System.in);
	System.out.print("Enter the Number : ");
	int number = sc.nextInt();
   	System.out.print("List of odd numbers from 1 to "+number+": \n");  
    	for (int i=1; i<=number; i++)   
    	{  
    		if (i%2!=0)   
    		{  
    			System.out.println(i + " ");  
    		}  
    	}  
    }  
}  
