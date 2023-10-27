class Solution {
    public int numberOfSteps(int num) {
        int n=num;
        int i=0,k=0;
        while(n!=0)
        {
        if(n%2==0)
        {
            n=n/2;
            i++;
        }
        if(n%2!=0)
        {
            n=n-1;
            i++;
        }
        }
    
    return i;
}}
