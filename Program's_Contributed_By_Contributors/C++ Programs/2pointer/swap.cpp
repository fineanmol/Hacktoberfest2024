// C++ program to swap two
// numbers using 3rd variable
#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
	int a = 2, b = 3;

	cout << "Before swapping a = " << a << " , b = " << b
		<< endl;

	// temporary variable
	int temp;

	// appying swapping algorithm
	temp = a;
	a = b;
	b = temp;
	cout << "After swapping a = " << a << " , b = " << b
		<< endl;

	return 0;
}
