// Revisit
package com.sharan;
// 100% Faster Solution with explanation below.
public class KthSymbolInGrammar {
    // Memory Limit Exceeded
    public static void main(String[] args) {
        int n = 5;
        int k = 11;
        System.out.println(kthGrammar(n,k));
    }
    public static int kthGrammars(int n, int k) {
        String ans = ans(n,"0");
        return ans.charAt(k-1) == '0' ? 0 : 1;
    }
    public static String ans(int n, String s){
        if(n == 1){
            System.out.println(s);
            return s;
        }
        return ans(n-1,modifiedString(s));
    }
    public static String modifiedString(String s){
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '0'){
                ans.append("01");
            }
            else{
                ans.append("10");
            }
        }
        return ans.toString();
    }
    /*
    Observations:
    For row n, it would have pow(2,n-1) no. of elements.
    k would always lie from 1 to pow(2,n-1).
    Say n=5 then grammar is
    0
    0 1
    0 1 1 0
    0 1 1 0 1 0 0 1
    0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0

    If above grammar is observed carefully, for every row say nth having pow(2,n-1) elements,
    1st pow(2,n-1)/2 elements will be same as of all (n-1)th row elements, And 2nd pow(2,n-1)/2 elements of nth row
    will be complement of all (n-1)th row elements.
    For example if we take n=5,k=6  solution would be equal to that of n=4,k=6
                if we take n=5,k=11 solution would be equal to !(n=4, k=11-8) where 8 is size of 1st half
    */
    // 100% Faster
    public static int kthGrammar(int n, double k) {
        // base condition
        if(n==1 && k==1){
            return 0;
        }
        // mid is size of 1st half of grammar generated
        // 1st half elements of row n would always equal to that of row (n-1)
        double mid = Math.pow(2,n-1) / 2;
        // hypothesis:
        // kthGrammar(n,k) returns result for nth row THEN
        // kthGrammar(n-1,k) would give result for (n-1)th row
        if(k<=mid){
            return kthGrammar(n-1, k);
        }else{
            int t = kthGrammar(n-1, k-mid);
            return t^1; // 0^1 returns 1 AND 1^1 returns 0
        }
    }
}
