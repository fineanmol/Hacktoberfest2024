// https://leetcode.com/problems/arranging-coins/
package com.sharan;

public class ArrangingCoins {
    public static void main(String[] args) {
        int n = 5;
        System.out.println(arrangeCoins(n));
    }
    public static int arrangeCoins(int n) {
        int temp = n;
        for(int i = 1; i <= n; i++){
            temp-=i;
            if(temp == 0) return i;
            if(temp < 0){
                return i - 1;
            }
        }
        return - 1;
    }
}
