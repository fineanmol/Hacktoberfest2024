package Array;

import java.util.Scanner;

public class duplicatenum {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int arr[]= new int[n];
		for (int i = 0; i<n; i++) {
			arr[i]= sc.nextInt();
		}
		int num = 0;
		for(int i = 0; i<n; i++) {
			num = 0;
			for(int j = 0; j < n; j++) {
				if(arr[i]==arr[j]) {
					num = num+1;	
				}
			}if(num == 2) {
				System.out.println(arr[i]);
				break;
			}
		}
	}
}