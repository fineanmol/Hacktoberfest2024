#include <bits/stdc++.h>
using namespace std;

// Function to return gcd of a and b
int gcd(int a, int b)
{
	while(b)
  {
    a = a % b;
    swap(a,b);
  }
  return a;
}

// Driver Code
int main()
{
	int a,b;
  cout<<"Enter the two numbers";
  cin>>a>>b;
	cout << "GCD(" << a << ", " << b << ") = "<<gcd(a, b)<< endl;
	return 0;
}

//code written by Trisha Moitra
