/*
Name : Rounak Ghosh
Username : Rounak-Ghosh
About : 4th year undergrad student at GCETTB
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter no of rows - ";
    cin >> n;
    int c=1,i,j;
    for(i=1;i<=n;i++)
    {
	    for(j=1;j<=i;j++)
	    {
		    cout<<c<<" ";
		    c++;
	    }
	    cout << endl;
    }
}