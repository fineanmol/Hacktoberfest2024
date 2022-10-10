import java.io.*;
import java.util.*;import java.util.collections;

class Anurag
{
    public static void main(String args[])throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int p = sc.nextInt();
        int i;
        while(p>0)
        {
            int N = sc.nextInt();
            int A[] = new int[N];
            int B[] = new int[N];

             for(i = 0; i < N; i++)
                A[i] = sc.nextInt();

             for(i = 0; i < N; i++)
                B[i] = sc.nextInt();
        
            Solution ob = new Solution();
            long ans = ob.findMinSum(A,B,N);
            System.out.println(ans);
            t--;
        }
    }
}

class Solution { 
    long findMinSum(int[] A,int[] B,int N) 
    { 
               Arrays.sort(A);
        Arrays.sort(B);
        long answer=0;
        for(int i = 0 ; i < N; i++)
        {
            answer+= Math.abs(A[i]-B[i]);
        }
        return answer;
    }
}