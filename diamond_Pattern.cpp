#include <bits/stdc++.h>
using namespace std;

int main() {
int n, s, i, j;
cout << "Enter number of rows: ";
cin >> n;
for(i = 0; i <= n; i++)
{
for(s = n; s > i; s--)
cout << " ";
for(j=0; j<i; j++)
cout << "* ";
cout << endl;
}

for(i = 1; i < n; i++)
{
for(s = 0; s < i; s++)
cout << " ";

for(j = n; j > i; j--)
cout << "* ";

cout << endl;
}
	return 0;
}
