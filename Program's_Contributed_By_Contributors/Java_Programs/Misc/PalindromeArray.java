//Coded by shreeyachatzz
//Accept integer numbers from user and print only the palindrome numbers.
import java.util.*;//importing
public class palin//declaring class
{
    void checkpalin(int m)//to check if number is palindrome
    {
        int s=0;
        for( int i= m; i>0 ; i=i/10)//finding the reverse of the number using for-loop
        {
            int p= i%10;
            s = s*10+p;
        }
        if( s== m )//to check if rev is equal to the original 
        {
            System.out.print(m+" ");
        }
    } 
    
    public static void main (String args[])//main method
    {
        Scanner sc= new Scanner (System.in);//Scanner class
        int a[]= new int[500];//Declaring array
        System.out.println("Enter the no. of integers you want to input:");
        int n= sc.nextInt();//accepting the number of integers to be checked
        System.out.println("Enter the Integers:");//use for-loop to accept integers from user
        for( int i= 0; i<n; i++)
        {
            a[i]= sc.nextInt();
        }
         palin ob= new palin();//calling function palin()
         //printing the palindrome numbers of all the numbers entered
         System.out.println("The palindrome numbers of the "+n+" numbers entered are as follows: ");
         for (int i=0; i<n; i++)
         {
             ob.checkpalin(a[i]);
          }
    }
}
/*
 OUTPUT(1):
Enter the no. of integers you want to input
5
Enter the Integers
121
223
116
242
678
The palindrome numbers of the 5 numbers entered are as follows: 
121 242 

OUTPUT(2):
Enter the no. of integers you want to input
5
Enter the Integers
22322
11711
222222
34567
112233
The palindrome numbers of the 5 numbers entered are as follows: 
22322 11711 222222 
 * 
 */
  
