import java.util.Scanner;

class BinarySearch
{
  public static int getIndex(int[] arr, int ele)
  {
    int start = 0, end = arr.length - 1;
    while (start <= end)
    {
      int mid = (start + end)/2;
      if (arr[mid] == ele){
        return mid;
      }
      if (arr[mid] > ele){
        end = mid - 1;
      }else{
        start = mid + 1;
      }
    }
    return -1;
  }
  
  public static void main(String argc[])
  {
    int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Scanner in = new Scanner(System.in);
    int ele = in.nextInt();
    int idx = getIndex(arr, ele);
    if (idx == -1){
      System.out.println("Not Found!");
    }else{
      System.out.println("Found at index " + idx);
    }
  }
}