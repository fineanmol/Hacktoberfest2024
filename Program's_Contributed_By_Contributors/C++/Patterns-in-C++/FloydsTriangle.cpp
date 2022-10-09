//C++ implementation of floyd's triangle
#include<iostream>
using namespace std;

void floyds_triangle(int n)
{
    int static k=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<k<<" ";
            k++;
        }
    cout<<endl;
    }
}
int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    floyds_triangle(n);
    return 0;
}
//Sample test case :
//	Enter a number : 5
//1 
//2 3 
//4 5 6 
//7 8 9 10 
//11 12 13 14 15 
