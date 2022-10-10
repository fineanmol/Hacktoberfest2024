import java.util.*;  
public class SphenicNumber
{  
//create a global array of size 100000  
static boolean arr[] = new boolean[10000];  
//finds all the primes smaller than the limit  
static void findPrime()  
{  
//marks all entries as true      
//A value in mark[p] will finally be false if 'p' is Not a prime, else true.  
Arrays.fill(arr, true);  
//iterate over all the numbers so that their multiples can be marked as composite  
for(int p = 2; p * p < 10000; p++)  
{  
//if p is not changed, then it is a prime  
if(arr[p])  
{  
//update all the multiples of p  
for(int i = p * 2; i < 10000; i = i + p)  
arr[i] = false;  
}  
}  
}  
//user-defined function that checks if the given number is sphenic or not  
static int isSphenic(int N)  
{  
//creating an array that stores the 8 divisors      
int []arr1 = new int[8];   
//counts the divisors  
int count = 0;    
int j = 0;  
for(int i = 1; i <= N; i++)    
{  
if(N % i == 0 && count < 8)    
{  
//increments the count by 1      
count++;  
arr1[j++] = i;  
}  
}  
//checks that there is exactly 8 divisors or not and all the numbers are distincit prime or not  
//if yes returns 1, else returns 0  
if(count == 8 && (arr[arr1[1]] && arr[arr1[2]] && arr[arr1[3]]))  
return 1;  
return 0;  
}  
//driver code  
public static void main(String args[])  
{  
//calling user-defined function that find the priime numbers  
findPrime();  
Scanner sc=new Scanner(System.in);  
System.out.print("Enter a number to check: ");  
//reading an iteger from the user  
int n=sc.nextInt();  
int result = isSphenic(n);  
if(result == 1)  
//prints yes if the above condition returns true  
System.out.print("Yes, the given number is sphenic.");  
else  
//prints no if the above condition returns false  
System.out.print("No, the given number is not a sphenic.");  
}  
}  
