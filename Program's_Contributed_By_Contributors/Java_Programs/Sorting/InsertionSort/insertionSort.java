import java.util.*;

public class InsertionSort {

  public static void main(String[] args) {
    
    Scanner sc = new Scanner(System.in);
    int length = sc.nextInt();
    int[] arr = new int[length];
    
    for(int i=0; i<length; i++){
      arr[i] = sc.nextInt();
    }
    
    for(int i=1; i<arr.length; i++){
      int temp = arr[i];
      int j = i-1;
      while(j>=0 && arr[j] > temp){
        arr[j+1] = arr[j];
        j--;
      }
      arr[j+1] = temp;
    }
    
    for(int i=0; i<arr.length; i++){
      System.out.println(arr[i]);
    }
    
  }

}