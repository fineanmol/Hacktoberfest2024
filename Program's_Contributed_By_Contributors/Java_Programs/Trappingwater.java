
import java.io.*;
import java.util.*;
import java.lang.*;
class Trappingwater{
    static long trappingWater(int arr[], int n) { 
        int left[]=new int[n];
        int right[]=new int[n];
        left[0]=0;
        right[n-1]=0;
        int leftmax=0;
        int rightmax=0;
        for(int i=1;i<n;i++){
            if(arr[i-1]>leftmax)
                leftmax=arr[i-1];
            left[i]=leftmax;
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i+1]>rightmax)
                rightmax=arr[i+1];
            right[i]=rightmax;
        }
        long amount=0;
        for(int i=1;i<n-1;i++){
            int trapped_water= Math.min(left[i],right[i])-arr[i];
            if(trapped_water>0)
                amount+=trapped_water;
        }
        return amount;
    } 
	public static void main(String args[]) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine().trim());// for inputting the testcases
		while(t-->0) {
			int n=Integer.parseInt(br.readLine().trim());
			int arr[]=new int[n];
			String inputLine[]=br.readLine().trim().split(" ");
			for(int i=0;i<n;i++) {
				arr[i]=Integer.parseInt(inputLine[i]);
			}
			System.out.println(trappingWater(arr,n));
		}
	}
}
