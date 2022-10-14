#include <iostream>
using namespace std;
int main() 
{
    int x, y, z;
    cout << "Enter first number= ";
    cin >> x;
    cout << "Enter second number= ";
    cin >> y;
    cout << "Enter third number= ";
    cin >> z;
    if (x>y) 
    {
    	if (x>z)
    	{
    		cout << "The Largest number= " << x;
		}     
        else
        {
        	cout << "The Largest number= " << z;       	
		}   	
	}     
    else 
	{
        if (y>z)
        {
        	cout << "The Largest number= " << y;  	
		}          
        else
        {
        	cout << "The Largest number= " << z;        	
		}
    }
    return 0;
}
