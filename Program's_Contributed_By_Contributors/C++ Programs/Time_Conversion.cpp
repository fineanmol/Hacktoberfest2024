// C++ program to convert 12 hour to 24 hour format
#include<iostream>
using namespace std;

void convertto24(string str)
{
	int h1 = (int)str[1] - '0';
	int h2 = (int)str[0] - '0';
	int hh = (h2 * 10 + h1 % 10);

	// If time is in "AM"
	if (str[8] == 'A')
	{
		if (hh == 12)
		{
			cout << "00";
			for (int i=2; i <= 7; i++)
				cout << str[i];
		}
		else
		{
			for (int i=0; i <= 7; i++)
				cout << str[i];
		}
	}

	// If time is in "PM"
	else
	{
		if (hh == 12)
		{
			cout << "12";
			for (int i=2; i <= 7; i++)
				cout << str[i];
		}
		else
		{
			hh = hh + 12;
			cout << hh;
			for (int i=2; i <= 7; i++)
				cout << str[i];
		}
	}
}

int main()
{
string str = "09:25:30PM";
  convertto24(str);
return 0;
}
