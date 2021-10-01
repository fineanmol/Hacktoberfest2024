
/**
 * 
 * In selection sort algorithm, we search for the lowest element and arrange it to the proper location. We swap the current element with the next lowest number.
 * @author Tumin Sheth (https://github.com/tuminzee)
 * Time Complexity - O(n^2)
 * Space Complexity - O(1)
 * 
 * Resources
 * https://en.wikipedia.org/wiki/Selection_sort
 * https://www.geeksforgeeks.org/selection-sort/
 * 
 * 
 * 
 */


import java.util.Arrays;

public class SelectionSort {
    public static void main(String[] args) {
        int[] arr = {5, 4, 3, 2, 1};
        System.out.println("Before sort\n" + Arrays.toString(arr));
        Sort(arr);
        System.out.println("After sort\n" +Arrays.toString(arr));

    }

    public static void Sort(int [] arr){
        for(int i = 0; i < arr.length; i++){
            int min = i;
            //find the smallest element in the array
            for(int j = i + 1; j < arr.length; j++){
                if(arr[j] < arr[min]){
                    min = j;
                }
            }
            //swap the lowest with the current element
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
