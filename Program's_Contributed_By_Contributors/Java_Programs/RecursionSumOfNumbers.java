// https://www.geeksforgeeks.org/sum-of-natural-numbers-using-recursion/
package com.sharan;

public class RecursionSumOfNumbers {
    public static void main(String[] args) {
        System.out.println(sum(1000,0,0,1));
    }
    public static int sum(int n, int count, int a,int i){
        if(count == n){
            return a;
        }
        else{
            a+=i;
            count++;
            i++;
            return sum(n,count,a,i);
        }
    }
}
