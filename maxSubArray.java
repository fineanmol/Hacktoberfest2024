class Solution {
    public int maxSubArray(int[] nums) {
        
        int l=nums.length;
        int i=0,s=0,max=nums[0];
        int[] b = new int[l];
        
        while(i!=l)
        {
            b[i]=nums[i];
            i++;
        }
        // if(l==1)
        //     return nums[0];
        Arrays.sort(b);
        if(b[l-1]<=0)
            return b[l-1];
    
        i=0;
        while(i!=l)
        {
            s+=nums[i];
            if(s<0)
            {
                s=0;
            }
            else if(s>max)
                max=s;
            System.out.println(max);
            i++;
        }
        System.out.println(max);
        return max;
    }
}
