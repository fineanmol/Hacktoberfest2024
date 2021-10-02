//coded by shreeyachatzz
// Find whether a number is a Keith number
import java.util.Scanner;
public class KeithNumberChecker 
{
 
    public static void main()//Main function 
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Please enter a number: "); 
        String n = scanner.nextLine(); 
        // Keith numbers must be > 10
        if (n.length() > 1 && isKeithNumber(n)) 
        {
            System.out.println(n + " is a Keith number!");
        } 
        else 
        {
            System.out.println(n + " is NOT a Keith number!");
        } 
        scanner.close(); 
    } 
    // Checks whether n number is a Keith number
    public static boolean isKeithNumber(String n) 
    {
        int b = n.length();
        // we keep only last n elements of the a
        long[] a = new long[b];
 
        for (int i = 0; i < b; i++) 
        {
            a[i] = Long.valueOf(n.substring(i, i + 1));
        }
        long next = 0;
        long no = Long.valueOf(n);
 
        while (next < no) 
        {
            next = 0;
            for (int i = 0; i < b; i++) 
            {
                next += a[i];
                if (i < b - 1) 
                {
                    a[i] = a[i + 1]; // shift a to left
                } 
                else 
                {
                    a[i] = next; // add new value to the a
                }
            }
            if (next == no) 
            {
                return true;
            }
        }
        return false;
    }
}
/*
(1)
Please enter a number: 197
197 is a Keith number!
*//*
(2)
Please enter a number: 12
12 is NOT a Keith number!
*//*
(3)
Please enter a number: 14
14 is a Keith number!
(4)
Please enter a number: 93993
93993 is a Keith number!
*/
