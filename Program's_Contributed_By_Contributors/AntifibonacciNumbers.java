import java.util.*;
public class AntifibonacciNumbers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt();
            ArrayList<Integer> arr = new ArrayList<>();
            for(int i = n;i>=1;i--)
                arr.add(i);
                System.out.println(arr);
            for(int i = n-1;i>=1 ;i--){
                
                for(int j = 0;j< n ; j++)
                    System.out.print(arr.get(j)+" ");
                System.out.println();
                Collections.swap(arr,i,i-1);
            }
            // Collections.swap(arr, n-2, n-1);
            for(int j = n-1;j>= 0 ; j--)
                System.out.print(arr.get(j)+" ");
                System.out.println();

            
        }
    }
}


