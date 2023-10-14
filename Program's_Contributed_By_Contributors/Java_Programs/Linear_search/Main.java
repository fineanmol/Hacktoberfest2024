package Linear_search;

import java.util.Scanner;

public class Main {
	public static void main(String [] args) {
		long start = System.nanoTime();
		Scanner object = new Scanner(System.in);
		 System.out.println("Enter the array size: ");
		  int size = object.nextInt();
		  
		  
		  int arr[]= new int[size];
		  
		  for (int i=0;i < size; i++){
		  System.out.println("Enter the array elements: ");
			  arr[i] = object.nextInt();
					  }
		  System.out.println("Enter the key element");
		  int key = object.nextInt();
		  int res =linearSearch(arr,key);		// fuction call
		 
		  if (res!=-1) {
			  System.out.println("Element foound at "+res+""+"position");
			  
		  }
		  else {
			  System.out.println("Not found");
		  }
		  long Duration =(System.nanoTime()-start)/1000000;
		  System.out.println("duration is " +Duration +"ms");
		  object.close();  
		
	}

	private static int linearSearch(int[] arr, int key) {
		for(int i=0; i<arr.length;i++) {
			if(arr[i]==key) {
				return i;
				
			}
			
		}
		return -1;
		
	}

}
