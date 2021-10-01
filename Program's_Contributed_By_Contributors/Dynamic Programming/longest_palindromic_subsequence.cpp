// A Dynamic Programming based C++ program for LPS problem
// Returns the length of the longest palindromic subsequence in seq
#include<stdio.h>
#include<string.h>

int max (int x, int y) { return (x > y)? x : y; }

int lps(char *str)
{
int n = strlen(str);
int i, j, cl;
int L[n][n]; 

for (i = 0; i < n; i++)
	L[i][i] = 1;

	for (cl=2; cl<=n; cl++)
	{
		for (i=0; i<n-cl+1; i++)
		{
			j = i+cl-1;
			if (str[i] == str[j] && cl == 2)
			L[i][j] = 2;
			else if (str[i] == str[j])
			L[i][j] = L[i+1][j-1] + 2;
			else
			L[i][j] = max(L[i][j-1], L[i+1][j]);
		}
	}

	return L[0][n-1];
}

/* Driver program to test above functions */
int main()
{
	char seq[] = "GEEKS FOR GEEKS";
	int n = strlen(seq);
	printf ("The length of the LPS is %d", lps(seq));
	getchar();
	return 0;
}
