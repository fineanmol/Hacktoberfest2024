import java.util.*;

public class Fibonacci_DP {

    public static Integer Fib(int n){
        int sum=0;
        if(n==0){return 0;}
        if(n==1){return 1;}
        sum=Fib(n-1)+Fib(n-2);
        return sum;
    }

    public static Integer Fib_topdown(int n, Integer arr[]) {
        if(arr[n] != null){
            //System.out.println("found "+arr[n]);
            return arr[n];
        }else{
            if(n==0){return 0;}
            if(n==1){return 1;}
            arr[n]=Fib_topdown(n-1, arr)+Fib_topdown(n-2, arr);
            /*for(int i=0;i<arr.length;i++){
                System.out.println("arr "+arr[i]);
            }System.out.println("---");*/
            return arr[n];
        }
    }

    public static Integer Fib_bottomup(int n, Integer arr[]) {
        for(int i=2;i<=n;i++){
            arr[i]=arr[i-1]+arr[i-2];
        }return arr[n];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter position to calculate for-> ");
        int n=sc.nextInt();sc.close();
        Integer[] arr1= new Integer[n+1];
        Integer[] arr2= new Integer[n+1];arr2[0]=0;arr2[1]=1;
        System.out.println("\nResult using Recursion approach -> "+Fib(n));
        System.out.println("and using Top-Down approach -> "+Fib_topdown(n, arr1));
        System.out.println("and using Bottom-Up approach -> "+Fib_bottomup(n, arr2));
    }
}
