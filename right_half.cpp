// C++ Program To Print Right Half 
// Pyramid Pattern using for loop
#include <iostream>
using namespace std;

int main()
{
	int rows = 5;

	// first for loop is used to identify number of rows
	for (int i = 1; i <= rows; i++) {
	
		// second for loop is used to identify number of
		// columns and here the values will be changed
		// according to the first for loop
		for (int j = 1; j <= i; j++) {
		
			// printing the required pattern
			cout << "* ";
		}
		cout << "\n";
	}
	return 0;
}
