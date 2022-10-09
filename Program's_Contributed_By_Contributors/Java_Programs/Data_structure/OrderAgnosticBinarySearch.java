//Order Agnostic Binary Search in java
//Binary Search is sorted array of both ascending and descending order

public class OrderAgnosticBinarySearch{
	public static void main(String[] args){
		int[] arr={5,4,3,2,1};
		int target=1;
		System.out.println("Index of the target is:"+binarySearch(arr,target));
	}
	static int binarySearch(int[] arr,int target){
		int start=0;
		int end=arr.length-1;
		boolean isAsc=arr[start]<arr[end];
		while(start<=end){
			int mid=start+(end-start)/2;
			if(arr[mid]==target){
				return mid;
			}
			if(isAsc){
				if(target<arr[mid]){
					end=mid-1;
				}
				else{
					start=mid+1;
				}
			}
			else{
				if(target>arr[mid]){
					end=mid-1;
				}
				else{
					start=mid+1;
				}
			}
		}
		return -1;
	}
}
