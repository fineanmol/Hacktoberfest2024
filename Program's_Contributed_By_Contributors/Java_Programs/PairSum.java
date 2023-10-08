package Array;

import java.util.Scanner;

public class PairSum {

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
				if(i!=j) {
				if(arr[i]+arr[j]==x) {
					a=a+1;
				}
				}
			}
		}
		System.out.println(a/2);
	}

}
