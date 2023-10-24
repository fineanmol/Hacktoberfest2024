
#include <bits/stdc++.h>

using namespace std;
void getUnion(int a[], int n, int b[], int m)
{
	set<int> s;
	for (int i = 0; i < n; i++)
	s.insert(a[i]);

	for (int i = 0; i < m; i++)
		s.insert(b[i]);
	cout << "Number of elements after union operation: " << s.size() << endl;
	cout << "The union set of both arrays is :" << endl;
	for (auto itr = s.begin(); itr != s.end(); itr++)
		cout << *itr
			<< " ";
}

int main()
{
	int a[9] = { 1, 2, 5, 6, 2, 3, 5, 7, 3 };
	int b[10] = { 2, 4, 5, 6, 8, 9, 4, 6, 5, 4 };

	getUnion(a, 9, b, 10);
}
