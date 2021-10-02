//coded by shreeyachatzz
//Converting the digits of a number to words
import java.util.*;
public class numword
{
    public static void main(String args[])
    {
        Scanner sc= new Scanner (System.in);
        System.out.println("Enter the number");//Accepting the number from userd
        int num= sc.nextInt();
        int a[] =new int[]{0,1,2,3,4,5,6,7,8,9};//creating a digits array
        //creating an array with the corresponding words of the numbers
        String w[] = new String[]{"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
        String s= " ";
        //Printing the digits of the number in words using nested for loop
        System.out.println("The Digits Of The Number In Words:"); int m =0;
        for( int i= num; i>0; i= i/10)
        {
            int p=i%10;
            for ( int j =0 ; j<10; j++ )
            { 
                if( p == a[j] )
                {
                    s=" "+w[j]+s;
                    break;
                }
            }
        }
        System.out.print(s);
    }
}
/*
OUTPUT(1):
Enter the number
7112611
The Digits Of The Number In Words:
 SEVEN ONE ONE TWO SIX ONE ONE 
 
 OUTPUT(2):
 Enter the number
15122021
The Digits Of The Number In Words:
 ONE FIVE ONE TWO TWO ZERO TWO ONE 
 */
            
        
        

                    
                    
               
            
        
