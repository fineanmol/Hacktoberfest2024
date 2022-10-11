package com.sharan;

public class FalseTestCaseBootifulCode {
    public int divide(int dividend, int divisor) {
        long sum = 0;
        long count = 0;
        int negativeCount = 0;
        if(dividend == 0){
            return 0;
        }
        if (divisor < 0 && dividend < 0){
            divisor *= -1;
            dividend *= -1;
            for(int i = divisor; i <= dividend; i++){
                if (divisor == 1 && dividend == 1){
                    return dividend;
                }
                if (divisor == 1){
                    return dividend * -1;
                }
                if(sum < dividend && dividend - sum >= divisor){
                    sum += divisor;
                    negativeCount--;
                }
            }
            return (int) negativeCount * -1;
        }
        if(divisor < 0){
            divisor *= -1;
            for(int i = divisor; i <= dividend; i++){
                if(sum < dividend && dividend - sum >= divisor){
                    sum += divisor;
                    negativeCount--;
                }
            }
            return (int) negativeCount;
        }
        if(dividend < 0){
            dividend *= -1;
            for(int i = divisor; i <= dividend; i++){
                if(sum < dividend && dividend - sum >= divisor){
                    sum += divisor;
                    negativeCount--;
                }
            }
            return (int) negativeCount;
        }
        for(int i = divisor; i <= dividend; i++){
            if(sum < dividend && dividend - sum >= divisor){
                sum += divisor;
                count++;
            }
        }
        return (int) count;
    }
}
