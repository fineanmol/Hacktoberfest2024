// Iterative C++ program to compute modular power
#include <iostream>
using namespace std;

// function to calculate power
int power(long long x, unsigned int y, int p)
{
	int res = 1;	 // Initialize result

	x = x % p; // Update x if it is more than or
				// equal to p

	if (x == 0) return 0; // In case x is divisible by p;

	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res*x) % p;

		// y must be even now
		y = y>>1; //dividing y by 2
		x = (x*x) % p;
	}
	return res;
}

int main()
{
	int x = 2;
	int y = 5;
	int p = 13;
	cout << "Power of the number  is " << power(x, y, p);
	return 0;
}

