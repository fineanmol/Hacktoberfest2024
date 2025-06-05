//This program check weather a number is strong or not

#include <iostream>
using namespace std;
int main()
{
	int sum, num, temp, x;
	sum = 0;
	cout << "Enter number\n";
	cin >> num;
	temp = num;
	while (num != 0)
	{
		x = num % 10;
		if (x == 0)				//special case in factorial for 0
			sum += 1;
		else 
		{
			for (int i = x - 1; i >= 1; i--)	//find factorial		
			{
				x = x * i;
			}
			sum += x;
		}
		num = num / 10;
	}
	if (sum == temp)
		cout << "A number is strong\n";
	else
		cout << "A number is not strong\n";
	
	return 0;
}