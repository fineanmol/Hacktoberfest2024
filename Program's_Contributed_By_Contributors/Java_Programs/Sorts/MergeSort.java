/**
 * 
 * In this algorithm each pair of adjacent elements is compared and the elements are swapped if they are not in order.
 * 
 * @author Tumin Sheth (https://github.com/tuminzee)
 * Time Complexity - O(n log n)
 * Space Complexity - O(n)
 * 
 * Resources
 * https://en.wikipedia.org/wiki/Merge_sort
 * https://www.geeksforgeeks.org/merge-sort/
 * 
 */

import java.util.Arrays;

public class MergeSort {
    public static void main(String[] args) {
        int [] arr = {10,9,8,7,6,5,4,3,2,1};
        System.out.println("Before sort\n" + Arrays.toString(arr));
        int l = 0;
        int r = arr.length - 1;
        Sort(arr, l , r); 
        System.out.println("After sort\n" + Arrays.toString(arr));

    }

    public static void Sort(int arr[], int l, int r)
    {
        if (l < r) {
            // Find the middle point
            int m =l+ (r-l)/2;
  
            // Sort first and second halves
            Sort(arr, l, m);
            Sort(arr, m+1, r);    
  
            // Merge the sorted halves
            Merge(arr, l, m, r);
        }
    }

    public static void Merge(int arr[], int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;
  
        int L[] = new int[n1];
        int R[] = new int[n2];
  
        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];
  
        int i = 0, j = 0;

        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
  
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
}
