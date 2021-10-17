/*package whatever //do not write package name here */
import java.util.*;
import java.lang.*;
import java.io.*;
class KadaneAlgo {
    static int maxSubArraySum(int a[], int size) 
    { 
    int sum = a[0]; 
    int curr_max = a[0]; 
    for (int i = 1; i < size; i++) 
    { 
           curr_max = Math.max(a[i], curr_max+a[i]); 
        sum = Math.max(sum, curr_max); 
    } 
    return sum; 
    }  
	public static void main (String[] args) 
	{
	Scanner sc = new Scanner(System.in);
	int t = sc.nextInt();
	while(t-->0)
	{
	int n = sc.nextInt();
	int a[]=new int[n];
	for (int i = 0; i < n; i++) 
	{ 
	    a[i]=sc.nextInt();	    
	}
	System.out.println(maxSubArraySum(a,n));
    }
}
}
