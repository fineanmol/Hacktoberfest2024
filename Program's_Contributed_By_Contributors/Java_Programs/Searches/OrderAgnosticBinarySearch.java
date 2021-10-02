
public class OrderAgnosticBinarySearch {
    public static void main(String[] args) {
//      int [] arr ={-18,-10,-7,-2,0,4,45,55,65,75,79,99};
        int[] arr ={99,79,54,46,22,18,4,2,0,-2,-10,-18,-22};
      int target = 4;
      int ans = orderAgnosticBinarySearch(arr,target);
        System.out.println(ans);
    }
    static int orderAgnosticBinarySearch(int [] arr,int target){
        int start = 0;
        int end = arr.length-1;
        boolean isAsc = arr[start] < arr[end];
        while(start <= end){
            //int mid = (start + end) /2;
            int mid = start + (end - start) /2;

            if(arr[mid] == target){
                return mid;
            }

            if(isAsc){
                if(target < arr[mid]){
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
            }
            else{
                if(target > arr[mid]){
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
            }
        }
        return -1;
    }

}
