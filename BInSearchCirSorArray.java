import java.util.*;
public class BInSearchCirSorArray {
    static int binsearch(int arr[],int n,int target){
        int st=0,en=n-1;
        while(st<=en){
            int mid = (st+en)/2;
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]>=arr[st]){
                if(target>=arr[st] && target<arr[mid]) en=mid-1;
                else st = mid+1;
            }
            else if(arr[mid]<=arr[en]){
                if(target>arr[mid] && target<=arr[en]) st=mid+1;
                else en=mid-1;
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        int arr[] = {7,8,10,12,2,3,4};
        int indx = binsearch(arr,arr.length,10);
        System.out.println(indx);
    }
}
