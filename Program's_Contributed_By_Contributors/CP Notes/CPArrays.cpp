#include <bits/stdc++.h>
using namespace std;
//if you declare the array here then the size limit is 10^7, global variables are stored in Data Segments that have no memory limit.
//const int n = 2e7;
//int arr[n];

//⚠️in competative programming always delcare the array globally when you need to have a function along with the main function

void swaper(int &a, int &b) //This is pass by reference,especially useful when you need to return more than one result
{
    int temp = a;
    a = b;
    b = temp;
}

void modify(int arr[])  //We dont need to specify size of a 1D array while passing, 2D array me arr[][n], ie pehla dena optional hai lekin uske bad pass karna padega
{
    arr[1]=69; //Arrays are always passed by reference, modify it here and the orignal array is altered.
}

int main()
{
/*
The limit of the size of array declared inside the main method is 10^5, coz its stored in
Stack memory with a memory limit of around 8MB, if the size is more than this then it results in STACK OVERFLOW😂
*/
    int a = 5, b = 6;
    swaper(a,b);    //The value returned by a function can be directly printed out, no need to store the value in a variable first.
    cout<<a<<" "<<b<<endl;

    int arr[] = {1,2};
    cout<<"Arrays are always passed by reference"<<endl;
    modify(arr);
    cout<<arr[1];

    //💖Gaur se dekho we didn't use return 0, still the code works fine, actually that return 0 is actually telling the compiler that code ran successfuly but today's modern compilers by defalut assume that the code ran successfully
}