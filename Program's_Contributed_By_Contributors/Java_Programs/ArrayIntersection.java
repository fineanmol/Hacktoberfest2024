package Array;

import java.util.Scanner;

public class ArrayIntersection {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int arr[]=new int [n];
		for(int i = 0; i<n; i++) {
			arr[i]=sc.nextInt();
		}
		int m = sc.nextInt();
		int ary[]= new int [m];
		for(int i = 0; i<m; i++) {
			ary[i]=sc.nextInt();
		}
		for(int i =0; i<n;i++){
			for (int j=0;j<m;j++){
				
				if (arr[i]==ary[j])
				System.out.print(arr[i]+" ");
			}
		}
		}
}