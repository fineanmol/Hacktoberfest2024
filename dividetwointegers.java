class Solution {
    public int divide(int dividend, int divisor) {
        if(dividend==Integer.MIN_VALUE&&divisor==-1) return Integer.MAX_VALUE;
        int sign = (dividend < 0 && divisor > 0) || (dividend >0 && divisor < 0) ? -1 : 1;
        divisor = divisor < 0 ? divisor : -divisor;
        dividend = dividend < 0 ? dividend : -dividend;
        int sol = divRec(dividend,divisor);
        return sign < 0 ? -sol : sol;
    }
    
    public int divRec(int dividend, int divisor)
    {
        if(divisor<dividend) return 0;
        if(divisor==dividend) return 1;
        int sol =1;
        int current = divisor;
        
        while(dividend - current < current)
        {
            sol+=sol;
            current +=current;
        }
        
        return sol + divRec(dividend - current, divisor);
    }
}