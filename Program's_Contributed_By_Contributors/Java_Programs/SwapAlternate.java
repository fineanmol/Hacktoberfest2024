package Array;

import java.util.Scanner;

public class SwapAlternate {

	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			int temp = 0;
			int n = sc.nextInt();
			int arr[]= new int[n];
			for(int i =0; i< n; i++) {
				arr[i]=sc.nextInt();
			}
			if(n%2==0) {
				for(int i = 0; i<n; i=i+2) {
					temp = arr[i];
					arr[i]=arr[i+1];
					arr[i+1]=temp;
				}
			}
			else {
				for(int i = 0; i<n-1; i=i+2) {
					temp = arr[i];
					arr[i]=arr[i+1];
					arr[i+1]=temp;
			}
			
			}
			for(int i = 0; i<n; i++) {
			System.out.print(arr[i]+" ");
			}
		}

	}

}
