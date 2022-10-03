/* 
Leetcode problem no. - 7
https://leetcode.com/problems/reverse-integer/
*/

import java.util.*;
import java.lang.Math;
class Solution {
    public int reverse(int x) {
        int rev=0,rem=0;
        if(x>=(-Math.pow(2,31)) && x<=(Math.pow(2,31)-1)) {
            while(x!=0)
            {
                rem=x%10;
                if(rev>Integer.MAX_VALUE/10 || rev<Integer.MIN_VALUE/10)
                    return 0;
                rev=(rev*10)+rem;
                x=x/10;
            }
        }
        return rev;
    }
}
class Result {
    public static void main(String arg[]) {
        Solution obj=new Solution();
        Scanner sn=new Scanner(System.in);
        int n=sn.nextInt();
        System.out.println(obj.reverse(n));
    }
}
