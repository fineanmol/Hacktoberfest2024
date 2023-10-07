import java.util.Scanner;

public class AgnosticBinary {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        int n = in.nextInt();
        int[] num = new int[n];
        System.out.print("Enter the array elements in a sorted order: ");
        for(int i=0;i<n;i++){
            num[i] = in.nextInt();
        }
        System.out.print("Enter the element to find: ");
        int target = in.nextInt();
        System.out.println(binarySearch(num,target));
    }

    static int binarySearch(int[] num, int target){
        if(num[0] > num[num.length-1]){
            return descending(num, target);
        }
        else{
            return ascending(num, target);
        }
    }

    static int ascending(int[] num, int target){
        int start = 0;
        int end = num.length - 1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(target == num[mid]){
                return mid;
            }
            else if(target < num[mid]){
                end = mid-1;
            }
            else{
                start = mid + 1;
            }
        }
        return -1;
    }

    static int descending(int[] num, int target){
        int start = 0;
        int end = num.length - 1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(target == num[mid]){
                return mid;
            }
            else if(target < num[mid]){
                start = mid + 1;
            }
            else{
                end = mid-1;
            }
        }
        return -1;
    }
}
