import java.util.Arrays;
import java.util.Scanner;

public class BinarySearch2D {

    public static int[] searchAns(int[][] arr, int target)
    {
        int row = arr.length;
        int col = arr[0].length;
        int l = 0, h = row * col - 1;
 
        while (l <= h) {
            int mid = l + (h - l) / 2;
 
            int tC = mid % col;
            int tR = mid / col;
            int val = arr[tR][tC];
            if (val == target)
                return new int[] { tR, tC };
 
            if (val < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
 
        return new int[] { -1, -1 };
    }

    public static void main(String args[]){
        
        System.out.print("Enter 2D array size : ");
        Scanner sc=new Scanner(System.in);
        int rows=sc.nextInt();
        int columns=sc.nextInt();
        
        System.out.println("Enter array elements : ");    
         
        int twoD[][]=new int[rows][columns];
         
           
        for(int i=0; i<rows;i++) {            
            for(int j=0; j<columns;j++) {
                twoD[i][j]=sc.nextInt();
            }
        }
        System.out.println("Enter a number to Search in 2D Array: ");
        int target = sc.nextInt();
        int[] ans = searchAns(twoD, target);
        System.out.println("Element found at index : " + Arrays.toString(ans));
    }
}
