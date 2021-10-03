import java.io.*;

public class Kadane {

        public static void main (String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                //size of array
                int n = Integer.parseInt(br.readLine().trim());
                int arr[] = new int[n];
                String inputLine[] = br.readLine().trim().split(" ");

                //adding elements
                for(int i=0; i<n; i++){
                    arr[i] = Integer.parseInt(inputLine[i]);
                }

                Kadane obj = new Kadane();

                //calling maxSubarraySum() function
                System.out.println(obj.maxSubarraySum(arr, n));
        }

        // Function to find subarray with maximum sum
        int maxSubarraySum(int arr[], int n) {
            if(n==0)
                return 0;
            int max_ending_here = 0, max_so_far = arr[0];

            for(int i=0;i<n;i++) {
                max_ending_here += arr[i];
                if(max_ending_here < 0)
                    max_ending_here = 0;
                else if(max_so_far <= max_ending_here) {
                    max_so_far = max_ending_here;
                }
            }
            return max_so_far;
        }
    }





/** 
    Input:
    5
    1 2 3 -2 5
    Output:
    9
    Explanation:
    Max subarray sum is 9
    of elements (1, 2, 3, -2, 5) which 
    is a contiguous subarray.
*/