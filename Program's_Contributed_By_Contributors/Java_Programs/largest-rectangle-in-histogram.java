package practical17.Program//Question : https://leetcode.com/problems/largest-rectangle-in-histogram/description/

class Solution {
    public int largestRectangleArea(int[] h) {

        //monotonic stack
        
        int n=h.length;
        int left[]=new int[n];  //left small elem's ind'
        int ryt[]=new int[n];  //ryt smaller elem's ind'
        
        Stack<Integer> lin=new Stack<>(); //storing index in stacks
        Stack<Integer> rin=new Stack<>();
        
        int ans[]=new int[n]; //ans array

        //1.store each elem's ryt side next small elem index in ryt[]
        for(int i=0;i<n;i++)
        {
            //before add cur elem index to stack, 
            //we check if its the ryt next small of elems in stack
            while( rin.size()>0 && h[i]< h[rin.peek()] )
            {
                ryt[rin.peek()]=i;
                rin.pop();
            }
            rin.push(i);
        }   
        //if no small elem present in ryt, assign n.
        while(rin.size()>0) 
        {
            ryt[rin.pop()]=n;
        }


        //2.store each elem's left side next small elem index in left[]
        for(int i=n-1;i>=0;i--)
        {
            //before add cur elem index to stack, 
            //we check if its the left next small of elems in stack
            while( lin.size()>0 && h[i]<h[lin.peek()] )
            {
                left[lin.pop()]=i;
            }
            lin.push(i);
        }
        //if no small elem present in left, assign '-1'.
        while(lin.size()>0)
        {
            left[lin.pop()]=-1;
        }


        //3. calculate area of rectangle(i.e area=width*height)
        //store ans arr in left[]  //height=value at an ind
        for(int i=0;i<n;i++)
        {
            int w=ryt[i]-left[i] - 1; //width
            ans[i]= w * h[i] ; //area
        }

        //4. return max of ans arr(i.e...left[])
        return Arrays.stream(ans).max().getAsInt();
    }
}