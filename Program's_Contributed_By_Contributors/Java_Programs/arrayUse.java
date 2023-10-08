package Array;

import java.util.Scanner;

public class arrayUse {
	public static  int[] takeInput() {
		try (Scanner sc = new Scanner(System.in)) {
			int size = sc.nextInt();
			int input[]= new int[size];
			for(int i = 0; i<size; i++) {
				input[i]=sc.nextInt();
			}
			return input;
		}
	}
	public static void printarr(int input[]) {
		int size = input.length;
	
		for(int i = 0; i<size; i++) {
			System.out.print(input[i]+" ");
		}
		System.out.println();
	}
	
public static void main(String[] args) {
	int arr[] = takeInput();
	printarr (arr);
	
}
}
