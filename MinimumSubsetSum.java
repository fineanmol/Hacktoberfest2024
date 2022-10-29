import java.util.*;

public class MinimumSubsetSum
{
	boolean t[][];

	MinimumSubsetIter(int s, int n)
	{
		t = new boolean [n+1][s+1];

		for (int i=0; i<n+1; i++)
		{
			t[i][0] = true;
		}
	}

	int subset(int val[], int s, int n)
	{

		int i,j;

		for (i=1; i<n+1; i++)
		{
			for (j=1; j<s+1; j++)
			{
				if(val[i-1] <= j)
					t[i][j] = t[i-1][j-val[i-1]] || t[i-1][j];
				else
					t[i][j] = t[i-1][j];
			}
		}

		i=s/2;

		while(i>=0)
		{
			if(t[n][i] == true)
				return i;
			i--;
		}
		return s;
	}

	public static void main(String[] args)
	{
		int n,s=0;
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		int val[] = new int [n];
		for (int i=0; i<n; i++)
		{
			val[i] = in.nextInt();
			s=s+val[i];
		}

		MinimumSubsetIter ob = new MinimumSubsetIter(s,n);
		System.out.print((s-2*(ob.subset(val,s,n))));
	}
}
