// This Code Is contributed by Kunal Chauhan
// github:- https://github.com/Kunal-Chauhan7

import java.util.Arrays;

public class Main{
  public static void main(String[] args) {
        int array[] = {65,7,51,1,3,74,14,55}; // declaring array
        InserctionSort(array); //calling out the function to sort the array and passing the array
        System.out.println(Arrays.toString(array)); // printing the sorted array and converting array into string
    }

  static void InserctionSort(int[] arr){ // taking a array as arguments
        for (int i = 1; i < arr.length; i++) { // loop will start from 1st index till the end
            int j = i-1;
            int key = arr[i]; // making the current element as key 
            for (; j >= 0 ; j--) {
                if (key < arr[j]){ // comparing the key with the sorted array
                    arr[j+1] = arr[j]; // if key is smaller then shift elements 
                }
                else {
                    break;
                }
            }
            arr[j+1] = key; // assigning key to the element next to j
        }
    }
}
