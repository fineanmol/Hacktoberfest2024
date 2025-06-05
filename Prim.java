package see_Practice;

import java.util.Scanner;
import java.util.Arrays;
public class Prim {

	static int n;
	static int a[][];
		public static void main(String[] args) {
			// TODO Auto-generated method stub
	Scanner in=new Scanner(System.in);
	System.out.println("enter the number of vertices:");
	n=in.nextInt();
	a=new int[n][n];
	System.out.println("enter the cost matrix");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=in.nextInt();
		}
	}
prims();
in.close();
}
		public static void prims()
		{
			int no_edge=0,sum=0;
			boolean[] selected=new boolean[n];
			Arrays.fill(selected, false);
			selected[0]=true;
			while(no_edge<=n-1)
			{
				int x=0,y=0,min=999;
				for(int i=0;i<n;i++)
				{
					if(selected[i]==true)
					{
					for(int j=0;j<n;j++)
					{
						if(!selected[j]&& a[i][j]!=0)
						{
							if(a[i][j]<min)
							{
								min=a[i][j];
							    x=i;
							    y=j;
							}
						}
					}
				}
				}
				System.out.println(x+":"+y+"->"+a[x][y]);
				sum=sum+a[x][y];
				selected[y]=true;
				no_edge++;
			}
			System.out.println("minimum spanning cost is"+sum);
		}
}
