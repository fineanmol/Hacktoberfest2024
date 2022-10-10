import java.util.*;

public class MergeSort{

  public static int[] mergeSort(int[] arr, int lo, int hi) {
    if(lo>=hi){
        return new int[]{arr[lo]};
    }
    int mid=lo+(hi-lo)/2;
    int[] arr1=mergeSort(arr,lo,mid);
    int[] arr2=mergeSort(arr,mid+1,hi);
    return mergeTwoSortedArrays(arr1,arr2);
  }

  //used for merging two sorted arrays
  public static int[] mergeTwoSortedArrays(int[] a, int[] b){
    int i = 0, j =0, k = 0;
    int[] ans = new int[a.length + b.length];
    while(i < a.length && j < b.length){
        if(a[i] <= b[j]){
          ans[k] = a[i];
          i++;
          k++;
        }else{
          ans[k] = b[j];
          j++;
          k++;
        }
    }

    while(i < a.length){
      ans[k] = a[i];
      k++;
      i++;
    }

    while(j < b.length){
      ans[k] = b[j];
      k++;
      j++;
    }
    
    return ans;
  }

  public static void print(int[] arr) {
    for (int i = 0; i < arr.length; i++) {
      System.out.print(arr[i] + " ");
    }
    System.out.println();
  }

  public static void main(String[] args) throws Exception {
    int[] arr = {3,2,5,7,1,9,10,1,4};
    int[] sa = mergeSort(arr,0,arr.length - 1);
    System.out.print("Sorted Array -> ");
    print(sa);
  }

}