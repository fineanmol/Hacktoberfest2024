package practical17.Program//Question : https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/

//Question exp : convert all 0 -> 1 by doing k bit flip
//given star
//Ans approach : greedy approach
class Solution {
    public int minKBitFlips(int[] nums, int k) {
        int n=nums.length;
        int flipCount=0; // range [cur - (k-1)elem] will be flipped this much times
        int totalFlips=0 ; //final ans

        //true will be marked for all range's(cur indx - k-1th indx) end elem.
        //While traversing, if visited[cur elem]=true,
        //then we reduce the flipCount of cur_range ,as we move towards nxt range
        boolean[] visited=new boolean[n];

        for(int i=0;i<n;i++)
        {
            //only works if, (which is flipped flipCount no of times) cur_elem's value = 0
                // 0 flipped even times = 0
                //1 flipped odd times = 0
            if( (nums[i]==0 && flipCount%2==0) || (nums[i]==1 && flipCount%2!=0) )
            {
                flipCount++;
                totalFlips++;

                if( i+(k-1) < n )
                {
                    //mark end of cur range as true
                    //so, we can rmv the flipCount of this range, after reaching this endPoint.
                    visited[i+(k-1)]=true;
                }
                else
                {
                    //if end elem goes out of range
                    //hence, all of arr elems cannot be flipped to 1
                    return -1; 
                }
            }

            if(visited[i]==true)
            {
                //end point of cur_range is reached.
                //so reduce the flipCount of cur_range 
                flipCount--;
            }

        } 

        return totalFlips;
    }
}