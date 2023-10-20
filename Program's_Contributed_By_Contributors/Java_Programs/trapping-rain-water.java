package practical17.Program//Question : https://leetcode.com/problems/trapping-rain-water/description/

class Solution {
    public int trap(int[] h) {
        int n=h.length;

        //left and ryt boundary
        int lb=h[0], rb=h[n-1];

        //traversing range ,start and end within boundary
        int l=1, r= n-2;

        int tw=0; //total_water
        
        //traverse
        while(l<=r)
        {
            if(lb<=rb)
            {
                int hw=lb; //theight of water (smallest of(left and ryt boundary))
                
                //whether water can be stored at top of building(h[l])
                if(h[l]<hw)
                {
                    int ac= hw - h[l]; //actual height(i.e.. water on top of the building)
                    tw+= ac; //add to total water
                }
                lb= Math.max(lb,h[l]);
                l++;
            }
            else
            {
               int hw=rb; //tot height of water
                
                //whether water can be stored at top of building
                if(h[r]<hw)
                {
                    int ac= hw - h[r]; //actual height(i.e.. water on top)
                    tw+= ac;  //add to total water
                }
                rb= Math.max(rb,h[r]);
                r--;
            }
        }
        return tw;

    }
}