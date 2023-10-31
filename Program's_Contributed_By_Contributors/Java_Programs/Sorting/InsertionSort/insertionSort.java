import java.io.*;
import java.util.*;

public class insertionSort
{
	// public static void inputArray(int[] arr){
 //    	Scanner sc = new Scanner(System.in);
	// 	int length = arr.length;
	// 	for(int i=0;i<length;i++){
	// 		arr[i]=sc.nextInt();
	// 	}
	// }

	// public static void printArray(int[] arr){
	// 	int length = arr.length;
	// 	for(int i=0;i<length;i++){
	// 		System.out.println(arr[i]);
	// 	}
	// }

	public static void main(String[] args)
	{
    	Scanner sc = new Scanner(System.in);
    	int length=sc.nextInt();
    	int[] arr=new int[length];
    	for(int i=0;i<length;i++){
    		arr[i]=sc.nextInt();
    	}
    	int temp;
    	for(int i=1;i<arr.length;i++){
    		temp = arr[i];
    		int j=i-1;
    		for(;j>=0 && arr[j]>temp;j--){
    				arr[j+1]=arr[j];
    		}
    			arr[j+1]=temp;
    	}
    	for(int j=0;j<arr.length;j++){
    		System.out.println(arr[j]);
    	}
    	
	}
}