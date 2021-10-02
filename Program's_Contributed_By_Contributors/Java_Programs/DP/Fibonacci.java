/**
 * 
 * It is a sequence such that each number is the sum of the two preceding ones; and the sequence will start from the number 0 and 1.
 * Resources
 * https://en.wikipedia.org/wiki/Fibonacci_number
 * 
 */



import java.util.*;
class Fibonacci
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        fibo(n);
    }

    static void fibo(int n){
        int a = 0, b = 1, i;
        if(n<1){ return; }

        System.out.print(a + " ");
        for(i = 1; i<n ; i++){
            System.out.print(b + " ");
            int c = a+b;
            a = b;
            b = c;
        }
    }
}