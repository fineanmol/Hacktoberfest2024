// C++ program to reverse an equation
#include <bits/stdc++.h>
using namespace std;

// Function to reverse order of words
string reverseEquation(string s)
{
	// Resultant string
	string result;
	int j = 0;
	for (int i = 0; i < s.length(); i++) {
		
		// A space marks the end of the word
		if (s[i] == '+' || s[i] == '-' ||
			s[i] == '/' || s[i] == '*') {
			
			// insert the word at the beginning
			// of the result string
			result.insert(result.begin(),
				s.begin() + j, s.begin() + i);
			j = i + 1;
			
			// insert the symbol
			result.insert(result.begin(), s[i]);
		}
	}
	
	// insert the last word in the string
	// to the result string
	result.insert(result.begin(), s.begin() + j,
									s.end());
	return result;
}

// driver code
int main()
{
	string s = "a+b*c-d/e";
	cout << reverseEquation(s) << endl;
	return 0;
}
