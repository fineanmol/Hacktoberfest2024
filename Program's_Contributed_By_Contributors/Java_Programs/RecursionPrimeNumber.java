// geeksforgeeks.org/recursive-program-prime-number/
package com.sharan;

public class RecursionPrimeNumber {
    public static void main(String[] args) {
        System.out.println(prime(982451653,0));
    }
    public static boolean prime(double n,int k){
        if((n == 1 || n == 0) && k < 1){
            return false;
        }
        if (n == 2 && k < 1){
            return true;
        }
        if(n % 2 == 0){
            return false;
        }
        if (n % 2 == 1){
            k++;
            return prime(n/2,k);
        }
        return true;
    }
}
