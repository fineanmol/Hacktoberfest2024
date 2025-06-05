public class IsSortedRecursion {	
	private static boolean isSorted(int[] arr, int index) {
		//base case
		if(index == arr.length-1)
			return true;
    // recurrence relation
    if (arr[index] > arr[index + 1]) {
		      return false;
		    }
    return isSorted(arr, index + 1);
	}
  public static void main(String[] args){
	  
    int arr[] = {1,2,3,4,5,8,9};
    boolean ans = isSorted(arr,0);
    System.out.println(ans);    
  }
}
