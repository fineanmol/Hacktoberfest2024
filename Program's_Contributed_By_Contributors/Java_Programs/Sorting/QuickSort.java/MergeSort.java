
// Merge sort ( Divide and conqure )

import java.util.*;
public class MergeSort{
    public static void Recc(int arr[], int si, int ei) {
        // Base case 
        if(si>=ei){
            return;
        }
        int mid = si+(ei-si)/2;
        // Left sort 
        Recc(arr, si, mid);
        // Right sort 
        Recc(arr, mid+1, ei);
        // Call merge 
        merge(arr, si, ei, mid);
    }
    public static void merge(int arr[], int si, int ei, int mid) {
        // Create a temperarory array 
        int temp[] = new int [ei-si+1];
        // Make 3 iterators 
        int i = si; // Left iterator
        int j = mid+1; //Right iterator
        int k = 0; // Temperory arr iterator 
        // Checking the values 
        while(i<=mid && j<=ei){
            if(arr[i]<arr[j]){
                temp[k]=arr[i];  // Left side array element is smaller than right 
                i++;
            }
            else{
                temp[k]=arr[j];  // Right side element is smaller 
                j++;
            }
            k++;
        }
        // Some elements may be left for them
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        while(j<=ei){
            temp[k++]=arr[j++];
        }
        // Till here we got our sorted array but it is stored in temp 
        // Change temp with original 
        for(k=0,i=si;k<temp.length;k++,i++){
            arr[i]=temp[k];
        }
        // Done we got final array now print it 
    }
    public static void print(int arr[]) {
        System.out.println("The final sorted array ");
        for(int i = 0; i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
        
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println();
        System.out.print("Enter the size of the Array: ");
        int a = sc.nextInt();
        int arr [] = new int [a];
        System.out.print("Enter the Array: ");
        for(int i = 0; i<a;i++){
            arr[i]=sc.nextInt();
        }
        Recc(arr, 0, arr.length-1);
        print(arr);
        sc.close();
    }
}


