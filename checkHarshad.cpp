#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n = 378;
	int temp = n;
	int sum = 0;
	while (temp!=0) {
		sum += temp % 10;
		temp /= 10;
	}
	if (n % sum == 0) {
		cout << "YES it is Harshad Number" << "\n";
	}
	else {
		cout << "NO it is not Harshad Number" << "\n";
	}

}
