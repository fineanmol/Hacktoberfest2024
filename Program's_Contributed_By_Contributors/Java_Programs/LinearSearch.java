package Array;

import java.util.Scanner;

public class LinearSearch {

	public static void main(String[] args) {
		try(Scanner sc = new Scanner(System.in)){;
		int n = sc.nextInt();
		int arr[]= new int[n];
		for(int i = 0; i<n; i++) {
			arr[i]= sc.nextInt();
		}
		int a=sc.nextInt();
		int j;
		for(j =0; j<n; j++) {
			if(a == arr[j]) {
				System.out.println(j);
				break;
			}
		}
		if(j==n) {
			System.out.println("-1");
		}
	}

}
}