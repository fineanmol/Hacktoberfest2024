package practical17.Program//Question : https://leetcode.com/problems/sliding-window-maximum/description/

class Solution {

    //helper class to combine cur_index's value & cur_index
    public class pair
    {
        int val; //value
        int ind; //index

        pair(int val,int ind)
        {
            this.val=val;
            this.ind=ind;
        }
    } 

    public int[] maxSlidingWindow(int[] nums, int k) {

        int n=nums.length;

        //stores ans
        int ans[]=new int[n-(k-1)];

        //queue of descending order by cur_index's value (max heap)
        PriorityQueue<pair> pque=new PriorityQueue<>((a,b)->{
           return b.val-a.val;
        });

        //start range (1st range)
        for(int i=0;i<k;i++)
        {
            pque.add(new pair(nums[i],i));
        }

        ans[0]=pque.peek().val;

        //start from k 
        for(int i=k;i<n;i++)
        {
            //adds ans only in range of each subarr
            //if ans's index not in range, then that elem in rmved from que

            while(pque.size()>0 && pque.peek().ind <= (i-k) )
                pque.remove();

            pque.add(new pair(nums[i],i));
            ans[i-k+1]=pque.peek().val; //storing every k window's max
        }
        return ans;
       }   

}