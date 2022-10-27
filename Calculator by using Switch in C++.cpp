// C++ program.
#include <iostream>
#include <math.h>
using namespace std;

// Class calculator
class Calculator
{
float a, b;
public:

	// Function to take input
	// from user
	void result()
	{
		cout << "Enter First Number: ";
		cin >> a;
		cout << "Enter Second Number: ";
		cin >> b;
	}

	// Function to add two numbers
	float add()
	{
		return a + b;
	}

	// Function to subtract two numbers
	float sub()
	{
		return a - b;
	}

	// Function to multiply two numbers
	float mul()
	{
		return a * b;
	}

	// Function to divide two numbers
	float div()
	{
		if (b == 0)
		{
			cout << "Division By Zero" <<
					endl;
			return INFINITY;
		}
		else
		{
			return a / b;
		}
	}
};

// Driver code
int main()
{
	int ch;
	Calculator c;
	cout << "Enter 1 to Add 2 Numbers" <<
			"\nEnter 2 to Subtract 2 Numbers" <<
			"\nEnter 3 to Multiply 2 Numbers" <<
			"\nEnter 4 to Divide 2 Numbers" <<
			"\nEnter 0 To Exit";
		
	do
	{
		cout << "\nEnter Choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			
			// result function invoked
			c.result();	
			
			// add function to calculate sum
			cout << "Result: " <<
					c.add() << endl;
			break;
		case 2:
			
			// sub function to calculate
			// difference
			c.result();
			cout << "Result: " <<
					c.sub() << endl;
			break;
		case 3:
			c.result();
			
			// mul function to calculate product
			cout << "Result: " <<
					c.mul() << endl;
			break;
		case 4:
			c.result();
			
			// div function to calculate division
			cout << "Result: " <<
					c.div() << endl;
			break;
		}
		
	} while (ch >= 1 && ch <= 4);
	
	return 0;
}
