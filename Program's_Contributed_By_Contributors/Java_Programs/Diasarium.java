//coded by shreeyachatzz
//To check if a number is diasrium or not 
import java.util.*;
public class dias
{
    //To find the sum of the digits raised to the power of their positional value present in the number'num'
    int sumofsq( int num)
    {
        int s= 0; int f=0;
        for( int i= num; i>0; i=i/10)//counting the number of digits
        {
            f=f+1;
        }
        for( int i= num; i>0; i=i/10)//To find sum of the digits raised to the power of their positional value
        {
            int p = i%10;
            s=s+(int)(Math.pow(p,f));
            f=f-1;//Decrementing the positional value with each iteration
        }
        return(s);
    }

    void checkdias(int num)//To prnt the final result
    {
        if((sumofsq(num))==num)
        {
            System.out.println("The Number Is Diasarium !!");
        }

        else
        {
            System.out.println("The Number Is NOT Diasarium !!");
        }
    }

    public static void main ()//Main method
    {
        Scanner sc= new Scanner (System.in);
        int n;
        System.out.println("Enter the number:");//Accepting number from user
        n= sc.nextInt();
        dias ob= new dias();//Creating object
        ob.checkdias(n);
    }
}
/*
(1)Enter the number:
135
The Number Is Diasarium !!
 *//*
(2)Enter the number:
56
The Number Is NOT Diasarium !!
 */

