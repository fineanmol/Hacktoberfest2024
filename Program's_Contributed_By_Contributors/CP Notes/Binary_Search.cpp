/*
Binary search is an alogrithm that works on a monotonic sequence, ie a sequence that has a certain order for eg:-
1,3,4,7,9 is a monotonic sequence ie always increasing or decreasing.
eg of these series are y = x^2;

Predicate function is a function that returns either True or False.
we can also apply binary search on predicate monotonic functions
eg T T T T T F F F F F ⚠️This concept is used in hard questions

Complexity is Log(N)
*/

#include<bits/stdc++.h>
using namespace std; 

int main(){
//Binary search works on upper and lower bound ie search space, like middle element se bada ya chota
int arr[] = {1,2,4,6,9,10,13,15};
int find = 9;
int lo = 0 , hi = 7, mid;
while(hi-lo>1) //We are left with only 2 elements simply compare them direclty
{
    mid = (lo+(hi-lo))/2; //the way to avoid overflowing
    if(arr[mid]>find)
    hi = mid-1;
    else
    lo=mid; //Ho sakta hai mid pe hi value ho
}
if(arr[lo]==find)
cout<<lo+1<<" Place pe hai"<<endl;
else if(arr[hi] == find)
cout<<hi+1<<" Place pe hai"<<endl;
else
cout<<"NAHI MILA"<<endl;
}