import java.io.*;

import java.util.*;

public class Main {

  public static void radixSort(int[] arr) {
    int max = Integer.MIN_VALUE;
    for (int i = 0; i < arr.length; i++) {
      max = Math.max(max, arr[i]);
    }
    //call countSort for every digit from right to left
    for (int exp = 1; max / exp >= 1; exp *= 10)
      countSort(arr, exp);
  }

  public static void countSort(int[] arr, int exp) {

    int[] ans = new int[arr.length];
    // make frequency arr
    int[] farr = new int[10];
    for (int i = 0; i < arr.length; i++) {
      farr[(arr[i] / exp) % 10]++;
    }
    // convert it into prefix sum array
    for (int i = 1; i < farr.length; i++) {
      farr[i] += farr[i - 1];
    }
    // stable sorting(filling ans array)
    for (int i = arr.length - 1; i >= 0; i--) {
      int pos = farr[(arr[i] / exp) % 10] - 1;
      ans[pos] = arr[i];
      farr[(arr[i] / exp) % 10]--;
    }
    // filling original array with the help of ans array
    for (int i = 0; i < arr.length; i++) {
      arr[i] = ans[i];
    }
    System.out.print("After sorting on " + exp + " place -> ");
    print(arr);
  }

  public static void print(int[] arr) {
    for (int i = 0; i < arr.length; i++) {
      System.out.print(arr[i] + " ");
    }
    System.out.println();
  }

  public static void main(String[] args) throws Exception {
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) {
      arr[i] = scn.nextInt();
    }
    radixSort(arr);
    print(arr);
  }
}
