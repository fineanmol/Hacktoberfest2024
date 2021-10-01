import java.util.Arrays;

/**
 * 
 * In this algorithm each pair of adjacent elements is compared and the elements are swapped if they are not in order.
 * 
 * @author Tumin Sheth (https://github.com/tuminzee)
 * Time Complexity - O(n^2)
 * Space Complexity - O(1)
 * 
 * Resources
 * https://en.wikipedia.org/wiki/Bubble_sort
 * https://www.geeksforgeeks.org/bubble-sort/
 * 
 */




public class BubbleSort {

    public static void main(String[] args) {
        int [] arr = {10,9,8,7,6,5,4,3,2,1};
        System.out.println("Before sort\n" + Arrays.toString(arr));
        Sort(arr);
        System.out.println("After sort\n" + Arrays.toString(arr));

    }

    public static void Sort(int arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n-1; i++)
            for (int j = 0; j < n-i-1; j++)
                if (arr[j] > arr[j+1])
                {
                    // swap arr[j+1] and arr[j]
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
    }
    
}
