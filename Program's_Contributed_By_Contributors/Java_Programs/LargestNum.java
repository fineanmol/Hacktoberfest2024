package Array;

import java.util.Scanner;

public class LargestNum {
	public static int largest(int arr[]) {
		int max = Integer.MIN_VALUE;
		for(int i = 0; i<arr.length; i++) {
			if(arr[i]>max) {
				max = arr[i];
			}
			
		}
		return max;
	}
	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			int n = sc.nextInt();
			int arr[]= new int[n];
			for(int i=0; i<n; i++) {
				arr[i]= sc.nextInt();
			}
			for(int i=0; i<n; i++) {
				System.out.print(arr[i]+" ");
			}
			System.out.println();
			int largest = largest(arr);
			System.out.println(largest);
		}
		

	}

}
