// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
package com.sharan;
// 40% faster :(
public class PrimeNumberSetBits {
    public static void main(String[] args) {
        int start = 6;
        int end = 10;
        System.out.println(countPrimeSetBits(start,end));
    }
    public static int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i = left; i <= right; i++){
            int count = 0;
            int n = i;
            while(n > 0){
                if((n & 1) == 1){
                    count++;
                }
                n = n >> 1;
            }
            if(isPrime(count)){
                ans+=1;
            }
        }
        return ans;
    }
    public static boolean isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        int c = 2;
        while (c * c <= n) {
            if(n % c == 0) {
                return false;
            }
            c++;
        }
        return true;
    }
}
