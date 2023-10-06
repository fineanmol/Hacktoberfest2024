#include<iostream> // preprocessor directive or header file
using namespace std; //standard library
main()// main funtion
{
	for getting output
	cout << "Hello World"<<endl;
	cout << "Hello World2";
	
	// Calculate the average age of a class of ten students. Prompt the user to enter the age of each student. 

	int age1, age2, age3;
	
	cout << "Enter age one: ";
	cin >> age1;
	
	cout << "Enter age two: ";
	cin >> age2;
	
	cout<< "Enter age three: ";
	cin >> age3;
	
	int total;
	total = age1 + age2+ age3;
	
	cout << "The Total age is: "<< total <<endl;
	
	int avg;
	avg = total/3;
	
	cout << "The average age is: "<< avg;

// Write a program that takes a four digits integer from user and shows the digits on the screen separately i.e. if user enters 7531, it displays 1, 3, 5, 7 separately. 
	
	int num , dig;
	
	cout << "Enter 4 digit number: ";
	cin >> num;
	
	dig = num % 10;
	cout << dig << ",";
	
	num = num / 10;
	
	dig = num % 10;
	cout << dig << ",";
	
	num = num / 10;
	
	dig = num % 10;
	cout << dig << ",";
	
	num = num / 10;
	dig = num % 10;
	cout << dig << ",";
	
	// Write a program that takes radius of a circle from the user and calculates the diameter,circumference and area of the circle and display the result
	
	 
// float radius, diameter, circumference, area; 

cout << "Please enter the radius of the circle " ; 
cin >> radius ; 


diameter = radius * 2 ; 
circumference = 2 * 3.14 * radius ; // 3.14 is the value of (Pi) 
area = 3.14 * radius * radius ; 

cout << "The diameter of the circle is : " << diameter << endl; 
cout << "The circumference of the circle is : " << circumference <<endl; 
cout << "The area of the circle is : " << area ;
 
// Tables;

	int counter ;
	for(counter = 1; counter<= 10; counter++)
	{
		cout << "2x" << counter << "=" << 2*counter<<"\n";
	}
	
		


}


