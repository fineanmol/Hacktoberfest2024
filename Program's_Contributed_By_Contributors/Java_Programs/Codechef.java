/*PROBLEM NAME: 7 RINGS
In Chefland, a valid phone number consists of 5 digits with no leading zeros.
For example, 98765,10000,98765,10000, and 7102371023 are valid phone numbers 
while 04123,9231 and 872310 are not.
Chef went to a store and purchased �N items, where the cost of each item is �X.
Find whether the total bill is equivalent to a valid phone number.*/


import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
        public static void main (String[] args) throws java.lang.Exception
        {
            // your code goes here
            Scanner sc= new Scanner(System.in);
                int N = sc.nextInt();
                int X = sc.nextInt();
                System.out.println((N*X)>=10000 && (N*X)<=99999? "YES" : "NO");
            }
        }
    
    
    