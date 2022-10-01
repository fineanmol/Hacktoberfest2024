class Solution{

    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long maxSubarraySum(int arr[], int n){
        // Your code here
        int currentsum=0;
		int maxSum =Integer.MIN_VALUE;
		
		for(int i=0;i<arr.length;i++) {
			currentsum+=arr[i];
			if(maxSum<currentsum) maxSum=currentsum;
			if(currentsum<0) currentsum=0;
		}
		return maxSum;
        
    }
    
}
