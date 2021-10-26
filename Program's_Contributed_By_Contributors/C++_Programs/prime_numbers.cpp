#include <iostream>
#include <math.h>
using namespace std;
int main() {
int x; //  Declaring a variable x
cout << "Please enter the number : "; //  cout to get the input value from user
cin >> x;
cout << "Here is the list of all the prime numbers Below "<< x << endl;
for ( int m=2; m<x; m++)      //implementing for loop to find out prime numbers
for ( int n=2; n*n<=m; n++)
{
if ( m % n == 0)
break;
else if ( n+1 > sqrt (m)) {
cout << m << endl;
}
}
return 0;
}
