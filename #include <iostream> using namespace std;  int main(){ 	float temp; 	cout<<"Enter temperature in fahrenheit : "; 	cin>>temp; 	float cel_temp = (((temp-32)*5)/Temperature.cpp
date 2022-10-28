#include <iostream>
using namespace std;

int main(){
	float temp;
	cout<<"Enter temperature in fahrenheit : ";
	cin>>temp;
	float cel_temp = (((temp-32)*5)/9);
	cout<<"Temperature in celsius : "<<cel_temp<<endl;
	
}
