// Java program for fibonacci series using recursion.

import java.util.Scanner;

public class fibonacci {
    public static void main(String[] argS){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int no= fib(n);
        System.out.println("The fibonacci series upto "+n+" is:");
        for (int i = 0; i < n; i++) {

            System.out.print(fib(i) + " ");
        }
    }
    public static int fib(int n){
        if (n <= 1)
            return n;
        else{
            return fib(n-1)+fib(n-2);
        }
     }
}
