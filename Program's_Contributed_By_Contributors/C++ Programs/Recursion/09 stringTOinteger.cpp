// given  a string has n character and convert it into digits integer 
// convert string into integer
// eg :- "123"-> 123

#include<iostream>
using namespace std;
int stringTOint(string str, int n){

	//base case
	if(str=="") //n==0  or str.empty()
	{
		return 0;
	}

		//recursive case
	string substring=str.substr(0,n-1); //extract substring 
	int myfriend=stringTOint(substring,n-1);
	return myfriend*10+(str[n-1]-'0');
}
int main(){
	string str="12345";
	int n=str.length();
	int x=stringTOint(str,n);
	cout<<x+1;
	return 0;
}
