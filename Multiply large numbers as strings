// C++ program to multiply two numbers represented
// as strings.
#include<bits/stdc++.h>
using namespace std;

// Multiplies str1 and str2, and prints result.
string multiply(string num1, string num2)
{
	int len1 = num1.size();
	int len2 = num2.size();
	if (len1 == 0 || len2 == 0)
	return "0";

	// will keep the result number in vector
	// in reverse order
	vector<int> result(len1 + len2, 0);

	// Below two indexes are used to find positions
	// in result. 
	int i_n1 = 0; 
	int i_n2 = 0; 
	
	// Go from right to left in num1
	for (int i=len1-1; i>=0; i--)
	{
		int carry = 0;
		int n1 = num1[i] - '0';

		// To shift position to left after every
		// multiplication of a digit in num2
		i_n2 = 0; 
		
		// Go from right to left in num2			 
		for (int j=len2-1; j>=0; j--)
		{
			// Take current digit of second number
			int n2 = num2[j] - '0';

			// Multiply with current digit of first number
			// and add result to previously stored result
			// at current position. 
			int sum = n1*n2 + result[i_n1 + i_n2] + carry;

			// Carry for next iteration
			carry = sum/10;

			// Store result
			result[i_n1 + i_n2] = sum % 10;

			i_n2++;
		}

		// store carry in next cell
		if (carry > 0)
			result[i_n1 + i_n2] += carry;

		// To shift position to left after every
		// multiplication of a digit in num1.
		i_n1++;
	}

	// ignore '0's from the right
	int i = result.size() - 1;
	while (i>=0 && result[i] == 0)
	i--;

	// If all were '0's - means either both or
	// one of num1 or num2 were '0'
	if (i == -1)
	return "0";

	// generate the result string
	string s = "";
	
	while (i >= 0)
		s += std::to_string(result[i--]);

	return s;
}

// Driver code
int main()
{
	string str1 = "1235421415454545454545454544";
	string str2 = "1714546546546545454544548544544545";
	
	if((str1.at(0) == '-' || str2.at(0) == '-') && 
		(str1.at(0) != '-' || str2.at(0) != '-' ))
		cout<<"-";


	if(str1.at(0) == '-')
		str1 = str1.substr(1);

	if(str2.at(0) == '-')
		str2 = str2.substr(1);

	cout << multiply(str1, str2);
	return 0;
}
