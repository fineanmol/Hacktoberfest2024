//Find the position of an element in an infinite sorted array
// For Ex - arr[] = [1, 3, 5, 6, 8, .....], key = 8, Output -> 4
import java.util.Scanner;

public class InfiniteSearchArray {
    public static void main(String[] args){             //main function
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int arr[] = new int[n];
        for(int i =0; i<n;i++){
            arr[i]= sc.nextInt();
        }
        int ans = searchInfinite(arr, m);
        if(ans == -1)
            System.out.println("Element not found");
        else
            System.out.println("Element found at index " + ans);
    }
    public static int searchInfinite(int[] arr, int key){           //method takes an infinite size array and a key to be
                                                                        // searched and returns its position
        int low =0;
        int high = 1;
        while(arr[high] < key){                                 //using the concept of range
                                                                //taking range exponentially
            low = high;
            high = 2*high;
        }
        return binarySearch(arr, key, low, high);
    }
    public static int binarySearch(int[] arr, int k, int l, int h){        //simple binary search algorithm
        if(h >= l){
            int mid = l + (h-l)/2;
            if(arr[mid] == k)
                return mid;
            if(arr[mid] > k)
                return binarySearch(arr, k, l, mid-1);
            return binarySearch(arr, k, mid+1,h);
        }
        return -1;
    }
}


//Time Complexity -> O(logn)