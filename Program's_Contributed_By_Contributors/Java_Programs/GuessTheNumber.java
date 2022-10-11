package com.sharan;

import java.util.Scanner;

public class GuessTheNumber {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the length of the array = ");
        int n = in.nextInt();
        System.out.println("Enter the number to be found = ");
        int num = in.nextInt();
        int ans = guessTheNumber(n, num);
    }
        static int guessTheNumber ( int n, int num){
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = i + 1;
            }
            int start = 0;
            int end = arr.length - 1;
            while (start <= end) {
                if (arr[start] == num || arr[end] == num) {
                    return num;
                }
                int mid = start + (end - start) / 2;
                if (arr[mid] == num) {
                    return arr[mid];
                } else if (mid > num) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            return num > n ? 1 : -1;
        }
    }

