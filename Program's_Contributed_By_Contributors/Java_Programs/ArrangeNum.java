package Array;

import java.util.Scanner;

public class ArrangeNum {

	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			int n = sc.nextInt();
			int arr[]= new int[n];
			    int a = 1;
			    int mid = n%2;
			    int b =  n - mid;
			    if (mid == 0){
			        b=b-2;
			    }
			    
			    for(int i =0; i<n; i++){
			        if (i<n/2){
			            arr[i] = a;
			            a = a+2;
			        }
			        
			        if (i==n/2){
			            arr[i] = n;
			        }
			        
			        if (i>n/2){
			            arr[i] = b;
			            b = b-2;
			        }
			        System.out.print(arr[i]+" ");
			    }
		}

	}

}
