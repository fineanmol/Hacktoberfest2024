package Array;

import java.util.Scanner;

public class TripletSum {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int arr[]= new int[n];
		for(int i = 0; i<n; i++) {
			arr[i]=sc.nextInt();
		}
		int x = sc.nextInt();
		int a = 0;
		for(int i = 0; i<n; i++) {
			for(int j = 0; j<n; j++) {
				for(int k = 0; k<n; k++) {
					if(i!=j && j!=k && i!=k) {
						if(arr[i]+arr[j]+arr[k]==x) {
							a++;
				}
				}
				}
			}
			
		}
		System.out.println(a/6);
	}
}