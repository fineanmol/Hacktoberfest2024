package com.sharan;

public class BinaryGap {
    public int binaryGap(int n) {
        int ans = 0;
        int count = 0;
        boolean one = false;
        while(n > 0){
            if((n & 1) == 1){
                one = true;
                ans = Math.max(count,ans);
                count = 0;
            }
            if(one){
                count++;
            }
            n = n >> 1;
        }
        return ans;
    }
}
