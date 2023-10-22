//Brute Force
//Not optimised approach
//Time Complexity: O(n^3)
public class MaxSubarraySum {
    public static void maxSubarraySum(int numbers[]){
        int currsum = 0;
        int maxSum = Integer.MIN_VALUE;
        for(int i=0; i<numbers.length; i++){
            int start = i;
            for(int j=i; j<numbers.length; j++){
                int end = j;
                currsum = 0;
                for(int k=start; k<=end; k++){
                    currsum += numbers[k];
                }
                System.out.println(currsum);
                if(maxSum < currsum){
                    maxSum = currsum;
                }
            }
            System.out.println();
        }
        System.out.println("Max Sum = " +maxSum);
    }
    public static void main(String args[]){
        int numbers[] = {2,3,6,8,1,4};
        maxSubarraySum(numbers);
    }
}
