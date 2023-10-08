package Array;

import java.util.Arrays;
import java.util.Scanner;

public class SortArray {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int arr[]= new int[n];
		for(int i = 0; i<n; i++) {
			arr[i]=sc.nextInt();
		}
		
//		for(int i = 0; i<n; i++) {
//			if(arr[i]==0) {
//				System.out.print(arr[i]+" ");
//			}
//			
//		}
//		for(int i = 0; i<n; i++) {
//			if(arr[i]==1) {
//				System.out.print(arr[i]+" ");
//				
//			}
		Arrays.sort(arr);
		for(int x:arr) {
			System.out.println(x);
		
		}
	}

}
