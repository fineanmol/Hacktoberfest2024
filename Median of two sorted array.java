import java.util.*;
import java.io.*;
import java.lang.*;



class Solution
{ 

	static double getMed(int a1[], int a2[], int n1, int n2)
	{
		int begin1 = 0, end1 = n1;

		while(begin1 <= end1)
		{
			int i1 = (begin1 + end1) / 2;
			int i2 = ((n1 + n2 + 1) / 2 )- i1;

			int min1 = (i1 == n1)?Integer.MAX_VALUE:a1[i1];
			int max1 = (i1 == 0)?Integer.MIN_VALUE:a1[i1 - 1];
			
			int min2 = (i2 == n2)?Integer.MAX_VALUE:a2[i2];
			int max2 = (i2 == 0)?Integer.MIN_VALUE:a2[i2 - 1];

			if(max1 <= min2 && max2 <= min1)
			{
				if((n1 + n2) % 2 == 0)
					return ((double)Math.max(max1, max2) + Math.min(min1, min2)) / 2;
				else
					return (double) Math.max(max1, max2);
			}
			else if(max1 > min2)
				end1 = i1 - 1;
			else 
				begin1 = i1 + 1;
		}
		
		return -1;
	}

  
