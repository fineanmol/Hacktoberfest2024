import java.util.*;

public class MergeSort {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the size of the Array: ");
    int size_of_arry = sc.nextInt(); // size of array, to b entered by the user
    int arr[] = new int[size_of_arry];
    System.out.println("Enter Array Elements ");
    for (int i = 0; i < size_of_arry; i++)
      arr[i] = sc.nextInt(); // element of array, to be entered by the user
    arr = Merge_sort(arr, size_of_arry);
    System.out.println("Array after Merge Sort is: ");
    for (int i = 0; i < size_of_arry; i++)
      System.out.print(arr[i] + " ");
    System.out.println("\n");
  }

  static int[] Merge_sort(int arr[], int size) {
    if (size > 1) {
      int mid = size / 2;
      int[] first = Arrays.copyOfRange(arr, 0, mid);
      first = Merge_sort(first, mid); // recursive call for first half array
      int[] second = Arrays.copyOfRange(arr, mid, size);
      second = Merge_sort(second, size - mid); // recursive call for second half array
      arr = Merge_arrays(first, second, mid, size - mid);
    }
    return arr;
  }

  static int[] Merge_arrays(int first[], int second[], int n, int m) // respectively
  {
    int arr[] = new int[n + m];
    int i = 0, f = 0, s = 0;
    while (f < n && s < m) {
      if (first[f] < second[s])
        arr[i++] = first[f++];
      else
        arr[i++] = second[s++];
    }
    while (f < n)
      arr[i++] = first[f++];
    while (s < m)
      arr[i++] = second[s++];
    return arr;
  }
}
