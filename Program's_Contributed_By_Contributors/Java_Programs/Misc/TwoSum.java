public class TwoSum {
    static int[] twoSum(int arr[],int n,int target){
        int start=0;
        int end=n-1;
        while(start<=end) {
            int currSum=arr[start]+arr[end];
            if(currSum<target)
                start++;
            else if(currSum>target)
                end--;
            else
                return new int[]{start,end};
        }
        return  new int[] {};
    }
    public static void main(String[] args) {
        int arr[]={3,2,4};
        int n=arr.length;
        int target=9;
        int res[]=twoSum(arr,n,target);
        for(int i:res){
            System.out.println(i);
        }
    }
}
