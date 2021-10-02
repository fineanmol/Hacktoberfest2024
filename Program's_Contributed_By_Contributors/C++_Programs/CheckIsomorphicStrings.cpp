
#include <iostream>

using namespace std;
// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
#define MAX_CHARS 256

// This function returns true if
// str1 and str2 are ismorphic
bool areIsomorphic(string str1, string str2)
{
	int n = str1.length(), m = str2.length();

	// Length of both strings must be
	// same for one to one
	// correspondence
	if (n != m)
		return false;

	// For counting the previous appearances of character in
	// both the strings
	int count[MAX_CHARS] = { 0 };
	int dcount[MAX_CHARS] = { 0 };

	// Process all characters one by one
	for (int i = 0; i < n; i++) {
		count[str1[i]]++;
		dcount[str2[i]]++;

		// For string to be isomorphic the previous counts
		// of appearances of
		// current character in both string must be same if
		// it is not same we return false.
		if (count[str1[i]] != dcount[str2[i]])
			return false;
	}
	return true;
}

// Driver Code
int main()
{
	

	cout << areIsomorphic("cpp", "yzz") << endl;
	cout << areIsomorphic("java", "data") << endl;
	cout << areIsomorphic("bba", "qwt") << endl;
	return 0;
}

