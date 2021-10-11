//Given an array of positive and negative numbers, find if there is a subarray (of size at-least one) with 0 sum.

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
public class subarray_withzerosum {
        static Boolean subArrayExists(int arr[]) {
            Set<Integer> hs = new HashSet<Integer>();
            int sum = 0;
            for (int i = 0; i < arr.length; i++) {
                sum += arr[i];
                if (arr[i] == 0 || sum == 0 || hs.contains(sum))
                    return true;
                hs.add(sum);
            }

            return false;
        }
        public static void main(String[] args) {
            Scanner sc= new Scanner(System.in);
            int n=sc.nextInt();
            int arr[] = new int[n];
            for (int i=0;i<n;i++){
                arr[i]=sc.nextInt();
            }
            if (subArrayExists(arr))
                System.out.println("Yes");
            else
                System.out.println("No");
        }
    }

