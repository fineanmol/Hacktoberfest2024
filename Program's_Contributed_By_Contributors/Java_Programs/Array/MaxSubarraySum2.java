//Prefix Sum
//Time Complexity: O(n^2)
public class MaxSubarraySum2 {
    public static void maxSubarraySum(int numbers[]){
        int currsum = 0;
        int maxSum = Integer.MIN_VALUE;
        int prefix[] = new int[numbers.length];
        
        prefix[0] = numbers[0];
        for(int i=1;i<prefix.length; i++){
            prefix[i] = prefix[i-1] + numbers[i];
        }

        for(int i=0; i<numbers.length; i++){
            int start = i;
            for(int j=i; j<numbers.length; j++){
                int end = j;
                currsum = start == 0 ? prefix[end] : prefix[end] - prefix[start - 1];
                
                if(maxSum < currsum){
                    maxSum = currsum;
                }
            }
        }
        System.out.println("Max Sum = " +maxSum);
    }
    public static void main(String args[]){
        int numbers[] = {2,3,6,8,1,4};
        maxSubarraySum(numbers);
    }
}

