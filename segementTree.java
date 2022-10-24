package Arrays;

import java.util.ArrayList;

public class segmenttree {
    class NumArray {
        ArrayList<Integer> arr=new ArrayList<>();
        // int sum=0;
        int segtree[];
        int n;
        int[] num;
        public NumArray(int[] nums) {
            n=nums.length;
            num=nums;
            int height=(int)Math.ceil(Math.log(n)/Math.log(2));
            segtree=new int[(int)(2*Math.pow(2,height)-1)];
            constructST(nums,0,n-1,0);
            
            for(int i=0;i<(int)(2*Math.pow(2,height)-1);i++){
                // arr.add(nums[i]);
                System.out.print(segtree[i]+" ");
            }
            // return;
        }
        int constructST(int arr[],int s,int e,int c){
            if(e==s){
                segtree[c]=arr[s];
                return segtree[c];
            }
            else{
                int mid=s+((e-s)/2);
                segtree[c]=constructST(arr,mid+1,e,2*c+1)+constructST(arr,s,mid,2*c+2);
                return segtree[c];
            }
        }
        int getSumUtil(int ss, int se, int qs, int qe, int si)
        {
            // If segment of this node is a part of given range, then return
            // the sum of the segment
            if (qs <= ss && qe >= se)
                return segtree[si];
      
            // If segment of this node is outside the given range
            if (se < qs || ss > qe)
                return 0;
      
            // If a part of this segment overlaps with the given range
            int mid = ss+((se-ss)/2);
            return getSumUtil(ss, mid, qs, qe, 2 * si + 1) +
                    getSumUtil(mid + 1, se, qs, qe, 2 * si + 2);
        }
        int getSum(int n, int qs, int qe)
        {
            // Check for erroneous input values
            if (qs < 0 || qe > n - 1 || qs > qe) {
                System.out.println("Invalid Input");
                return -1;
            }
            return getSumUtil(0, n - 1, qs, qe, 0);
        }
        void updateValueUtil(int ss, int se, int i, int diff, int si)
        {
            // Base Case: If the input index lies outside the range of 
            // this segment
            if (i < ss || i > se)
                return;
      
            // If the input index is in range of this node, then update the
            // value of the node and its children
            segtree[si] = segtree[si] + diff;
            if (se != ss) {
                int mid = ss+((se-ss)/2);
                updateValueUtil(ss, mid, i, diff, 2 * si + 1);
                updateValueUtil(mid + 1, se, i, diff, 2 * si + 2);
            }
        }
        void updateValue(int arr[], int n, int i, int new_val)
        {
            // Check for erroneous input index
            if (i < 0 || i > n - 1) {
                System.out.println("Invalid Input");
                return;
            }
      
            // Get the difference between new value and old value
            int diff = new_val - arr[i];
      
            // Update the value in array
            arr[i] = new_val;
      
            // Update the values of nodes in segment tree
            updateValueUtil(0, n - 1, i, diff, 0);
        }
        public void update(int index, int val) {
            // arr.set(index,val);
            // nums[index]=val;
            updateValue(num,n,index,val);
            return;
        }
        
        public int sumRange(int left, int right) {
            // int sum=0;
            
            // for(int i=left;i<=right;i++){
            //     sum+=arr.get(i);
            // }
            return getSum(n,left,right);
        }
    }
    
    /**
     * Your NumArray object will be instantiated and called as such:
     * NumArray obj = new NumArray(nums);
     * obj.update(index,val);
     * int param_2 = obj.sumRange(left,right);
     */
}
