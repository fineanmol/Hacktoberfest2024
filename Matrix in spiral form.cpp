// C++ Program to print a matrix spirally

#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4

void spiralPrint(int m, int n, int a[R][C])
{
	int i, k = 0, l = 0;

	while (k < m && l < n) {
		for (i = l; i < n; ++i) {
			cout << a[k][i] << " ";
		}
		k++;

		for (i = k; i < m; ++i) {
			cout << a[i][n - 1] << " ";
		}
		n--;

		if (k < m) {
			for (i = n - 1; i >= l; --i) {
				cout << a[m - 1][i] << " ";
			}
			m--;
		}

		if (l < n) {
			for (i = m - 1; i >= k; --i) {
				cout << a[i][l] << " ";
			}
			l++;
		}
	}
}

int main()
{
	int R,C;
	cin>>R>>C;
	int a[R][C];
	for(int i=0;i<R;i++){
	    for(int j=0;j<C;j++){
	        cin>>a[i][j];
	    }
	}
	spiralPrint(R, C, a);
	return 0;
}

// This is code is contributed by rathbhupendra
