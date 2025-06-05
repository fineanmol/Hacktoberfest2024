import java.util.Scanner;
import java.util.Random;

public class mergesort {

		static final int MAX= 10005;
		static int[] a=new int[MAX];
		public static void main(String[] args) {
			Scanner input=new Scanner(System.in);
			System.out.println("Enter the number of elements");
			int n=input.nextInt();
			Random random=new Random();
			//System.out.println("Enter the array elements");
			for(int i=0;i<n;i++)
				//a[i]=input.nextInt();
				a[i]=random.nextInt(1000);
				MergesortAlgorithm(0,n-1);
			long startTime = System.nanoTime();
			MergesortAlgorithm(0,n-1);
			long stopTime = System.nanoTime();
			long elapsedTime = stopTime-startTime;
			System.out.println("time elapsed for "+n+ " elements in ms: "+(double)elapsedTime/1000000);
//			System.out.println("The sorted array elements:");
//			for(int i=0;i<n;i++)
//				System.out.print(a[i]+" ");
			input.close();

	}
		public static void MergesortAlgorithm(int low,int high)
		{
			int mid;
			if(low<high)
			{
				mid = (low+high)/2;
				MergesortAlgorithm(low,mid);
				MergesortAlgorithm(mid+1,high);
				merge(low,mid,high);
			}
		}
		public static void merge(int low,int mid,int high)
		{
			int b[]=new int[MAX];
			int i,j ,k ,h;
			i=h=0;
			j=mid+1;
					while(h<=mid&&j<=high)
					if(a[h]<a[j]) b[i++]=a[h++];
					else b[i++]=a[j++];
					if (h>mid)
						for(k=j;k<=high;k++)
						b[i++]=a[k];
					else
						for(k=h;k<=mid;k++)
							b[i++]=a[k];
					for(k=low;k<=high;k++)
						a[k]=b[k];
		}

}
